/*
 * Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

#include "wmm.h"

#include <math.h>
#include <stdio.h>
/*#include "EGM9615.h"*/
#include "GeomagnetismHeader.h"

static int getGeomagneticElements(MAGtype_GeoMagneticElements *geo_magnetic_elements, const double latitude,
                                  const double longitude, const int year, const int month, const int day)
{
  /* Check latitude and longitude */
  if ((latitude < -90.0) || (latitude > 90.0))
  {
    return WMM_LATITUDE_OUT_OF_RANGE;
  }
  if ((longitude < -180.0) || (longitude > 180.0))
  {
    return WMM_LONGITUDE_OUT_OF_RANGE;
  }

  /* Check month. It must be between 1 and 12, but 0 does not generate an error! */
  if (month <= 0)
  {
    return WMM_INVALID_DATE;
  }

  /* Initialize structures */
  MAGtype_MagneticModel *magnetic_models[1], *timed_magnetic_model;
  MAGtype_Ellipsoid ellip;
  MAGtype_CoordSpherical coord_spherical;
  MAGtype_CoordGeodetic coord_geodetic;
  MAGtype_Date user_date;
  MAGtype_Geoid geoid;

  /* Allocate memory and read model */
  char cof_path[] = COF_DATA_PATH;
  if (!MAG_robustReadMagModels(cof_path, &magnetic_models, 1))
  {
    char cof_path_2[] = COF_DATA_PATH_2;
    if (!MAG_robustReadMagModels(cof_path_2, &magnetic_models, 1))
    {
      return WMM_COF_DATA_NOT_FOUND;
    }
  }

  /* Allocate time modified model memory */
  int nMax = 0;
  if (nMax < magnetic_models[0]->nMax)
  {
    nMax = magnetic_models[0]->nMax;
  }
  int NumTerms = ((nMax + 1) * (nMax + 2) / 2);
  timed_magnetic_model = MAG_AllocateModelMemory(NumTerms); /* For storing the time modified WMM Model parameters */
  if ((magnetic_models[0] == NULL) || (timed_magnetic_model == NULL))
  {
    MAG_FreeMagneticModelMemory(magnetic_models[0]);
    return WMM_BAD_ALLOCATION;
  }

  /* Set default values and constants */
  MAG_SetDefaults(&ellip, &geoid);

  /* Set EGM96 Geoid parameters. GeoidHeighBuffer is an array inside EGM9615.h */
  /*geoid.GeoidHeightBuffer = GeoidHeightBuffer;
  geoid.Geoid_Initialized = 1;*/

  /* Set latitude and longitude */
  coord_geodetic.phi = latitude;
  coord_geodetic.lambda = longitude;

  /* Assume request is at mean sea level*/
  /*geoid.UseGeoid = 1;
  coord_geodetic.HeightAboveGeoid = 100.0;
  MAG_ConvertGeoidToEllipsoidHeight(&coord_geodetic, &geoid);*/

  /*geoid.UseGeoid = 0;
  double h = 0;
  MAG_GetGeoidHeight(latitude, latitude, &h, &geoid);
  coord_geodetic.HeightAboveEllipsoid = (h + 100.0) * 1e-03;*/
  coord_geodetic.HeightAboveEllipsoid = 0.0;

  /* Date */
  user_date.Month = month;
  user_date.Day = day;
  user_date.Year = year;
  char error_message[255];
  if (!MAG_DateToYear(&user_date, error_message))
  {
    MAG_FreeMagneticModelMemory(timed_magnetic_model);
    MAG_FreeMagneticModelMemory(magnetic_models[0]);
    return WMM_INVALID_DATE;
  }
  if ((user_date.DecimalYear > magnetic_models[0]->CoefficientFileEndDate) ||
      (user_date.DecimalYear < magnetic_models[0]->epoch))
  {
    MAG_FreeMagneticModelMemory(timed_magnetic_model);
    MAG_FreeMagneticModelMemory(magnetic_models[0]);
    return WMM_INVALID_YEAR;
  }

  /* Time adjust the coefficients, Equation 19, WMM Technical report */
  MAG_TimelyModifyMagneticModel(user_date, magnetic_models[0], timed_magnetic_model);

  /*Convert from geodetic to Spherical Equations: 17-18, WMM Technical report*/
  MAG_GeodeticToSpherical(ellip, coord_geodetic, &coord_spherical);

  /* Computes the geoMagnetic field elements and their time change*/
  MAG_Geomag(ellip, coord_spherical, coord_geodetic, timed_magnetic_model, geo_magnetic_elements);

  /* Computes the grid variation for |latitudes| > MAG_MAX_LAT_DEGREE */
  MAG_CalculateGridVariation(coord_geodetic, geo_magnetic_elements);

  /* Free memory */
  MAG_FreeMagneticModelMemory(timed_magnetic_model);
  MAG_FreeMagneticModelMemory(magnetic_models[0]);

  /* Print debug info */
  /*printf("Latitude: %f\n", latitude);
  printf("Longitude: %f\n", longitude);
  printf("Year: %d\n", year);
  printf("Month: %d\n", month);
  printf("Day: %d\n", day);
  printf("Declination: %f\n", geo_magnetic_elements.Decl);*/

  return WMM_OK;
}

int computeMagneticDeclination(double *declination, const double latitude, const double longitude, const int year,
                               const int month, const int day)
{
  MAGtype_GeoMagneticElements geo_magnetic_elements;
  const int error = getGeomagneticElements(&geo_magnetic_elements, 180.0 / M_PI * latitude, 180.0 / M_PI * longitude,
                                           year, month, day);
  *declination = (error != WMM_OK ? 0.0 : M_PI / 180.0 * geo_magnetic_elements.Decl);
  return error;
}

int computeHorizontalMagneticFieldStrength(double *horizontal_magnetic_field_strength, const double latitude,
                                           const double longitude, const int year, const int month, const int day)
{
  MAGtype_GeoMagneticElements geo_magnetic_elements;
  const int error = getGeomagneticElements(&geo_magnetic_elements, 180.0 / M_PI * latitude, 180.0 / M_PI * longitude,
                                           year, month, day);
  *horizontal_magnetic_field_strength = (error != WMM_OK ? 0.0 : 0.00001 * geo_magnetic_elements.H);
  return error;
}

int computeVerticalMagneticFieldStrength(double *vertical_magnetic_field_strength, const double latitude,
                                         const double longitude, const int year, const int month, const int day)
{
  MAGtype_GeoMagneticElements geo_magnetic_elements;
  const int error = getGeomagneticElements(&geo_magnetic_elements, 180.0 / M_PI * latitude, 180.0 / M_PI * longitude,
                                           year, month, day);
  *vertical_magnetic_field_strength = (error != WMM_OK ? 0.0 : 0.00001 * geo_magnetic_elements.Z);
  return error;
}

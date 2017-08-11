// LanssieToolKit-fresh.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

/*
*  ARToolKitCalibrationFileGenerator.cpp
*  ARTolKitCamCalib
*
*  This work is a modified version of the original "calib_camera.cpp" of
*  ARToolKit. The copyright and license information of ARToolKit is included
*  in this document as required by its GNU Lesser General Public License
*  version 3.
*
*  This file is a part of ARTolKitCamCalib.
*
*  Copyright 2017 Long Qian
*  Contact: lqian8@jhu.edu
*
*/

/* The original copyright information: */
/*
*  calib_camera.cpp
*  ARToolKit5
*
*  Camera calibration utility.
*
*  Run with "--help" parameter to see usage.
*
*  This file is part of ARToolKit.
*
*  ARToolKit is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  ARToolKit is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with ARToolKit.  If not, see <http://www.gnu.org/licenses/>.
*
*  As a special exception, the copyright holders of this library give you
*  permission to link this library with independent modules to produce an
*  executable, regardless of the license terms of these independent modules, and to
*  copy and distribute the resulting executable under terms of your choice,
*  provided that you also meet, for each linked independent module, the terms and
*  conditions of the license of that module. An independent module is a module
*  which is neither derived from nor based on this library. If you modify this
*  library, you may extend this exception to your version of the library, but you
*  are not obligated to do so. If you do not wish to do so, delete this exception
*  statement from your version.
*
*  Copyright 2015 Daqri, LLC.
*  Copyright 2002-2015 ARToolworks, Inc.
*
*  Author(s): Hirokazu Kato, Philip Lamb
*
*/

//#include "pch.h"
#include <cstdio>
#include <iostream>
#include "../../ARToolKit5/include/AR/ar.h"
#include "../../ARToolKit5/include/AR/param.h"

//#include "ARToolKitUWP.h"

extern "C" {
	FILE __iob_func[3] = {*stdin, *stdout, *stderr};
	//EXPORT_API  ARdouble getSizeFactor(ARdouble dist_factor[], int xsize, int ysize, int dist_function_version);
	//EXPORT_API  void convParam(ARdouble intr[3][4], ARdouble dist[4], int xsize, int ysize, ARParam *param);

	//__declspec(dllexport) void createHoloLenCamParam();
	__declspec(dllexport) int testInt();
}
//extern "C" {FILE __imp_func[3] = { *printf, *fprintf, *stderr }; }

__declspec(dllexport) int testInt()
{
	return 20;
}
//
//ARdouble getSizeFactor(ARdouble dist_factor[], int xsize, int ysize, int dist_function_version)
//{
//	ARdouble  ox, oy, ix, iy;
//	ARdouble  olen, ilen;
//	ARdouble  sf, sf1;
//
//	sf = 100.0;
//
//	ox = 0.0;
//	oy = dist_factor[7];
//	olen = dist_factor[6];
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = dist_factor[6] - ix;
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	ox = xsize;
//	oy = dist_factor[7];
//	olen = xsize - dist_factor[6];
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = ix - dist_factor[6];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	ox = dist_factor[6];
//	oy = 0.0;
//	olen = dist_factor[7];
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = dist_factor[7] - iy;
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	ox = dist_factor[6];
//	oy = ysize;
//	olen = ysize - dist_factor[7];
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = iy - dist_factor[7];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//
//	ox = 0.0;
//	oy = 0.0;
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = dist_factor[6] - ix;
//	olen = dist_factor[6];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//	ilen = dist_factor[7] - iy;
//	olen = dist_factor[7];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	ox = xsize;
//	oy = 0.0;
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = ix - dist_factor[6];
//	olen = xsize - dist_factor[6];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//	ilen = dist_factor[7] - iy;
//	olen = dist_factor[7];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	ox = 0.0;
//	oy = ysize;
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = dist_factor[6] - ix;
//	olen = dist_factor[6];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//	ilen = iy - dist_factor[7];
//	olen = ysize - dist_factor[7];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	ox = xsize;
//	oy = ysize;
//	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
//	ilen = ix - dist_factor[6];
//	olen = xsize - dist_factor[6];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//	ilen = iy - dist_factor[7];
//	olen = ysize - dist_factor[7];
//	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
//	if (ilen > 0)
//	{
//		sf1 = ilen / olen;
//		if (sf1 < sf) sf = sf1;
//	}
//
//	if (sf == 100.0) sf = 1.0;
//
//	return sf;
//}
//
//void convParam(ARdouble intr[3][4], ARdouble dist[4], int xsize, int ysize, ARParam *param)
//{
//	ARdouble   s;
//	int      i, j;
//
//	param->dist_function_version = 4;
//	param->xsize = xsize;
//	param->ysize = ysize;
//
//	param->dist_factor[0] = (ARdouble)dist[0];     /* k1  */
//	param->dist_factor[1] = (ARdouble)dist[1];     /* k2  */
//	param->dist_factor[2] = (ARdouble)dist[2];     /* p1  */
//	param->dist_factor[3] = (ARdouble)dist[3];     /* p2  */
//	param->dist_factor[4] = (ARdouble)intr[0][0];  /* fx  */
//	param->dist_factor[5] = (ARdouble)intr[1][1];  /* fy  */
//	param->dist_factor[6] = (ARdouble)intr[0][2];  /* x0  */
//	param->dist_factor[7] = (ARdouble)intr[1][2];  /* y0  */
//	param->dist_factor[8] = (ARdouble)1.0;         /* s   */
//
//	for (j = 0; j < 3; j++)
//	{
//		for (i = 0; i < 4; i++)
//		{
//			param->mat[j][i] = (ARdouble)intr[j][i];
//		}
//	}
//
//	s = getSizeFactor(param->dist_factor, xsize, ysize, param->dist_function_version);
//	param->mat[0][0] /= s;
//	param->mat[0][1] /= s;
//	param->mat[1][0] /= s;
//	param->mat[1][1] /= s;
//	param->dist_factor[8] = s;
//}
//
///*
//Conversion from opencv camera calibration to artoolkit camera calibration
//OpenCV camera calibration format: http://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_calib3d/py_calibration/py_calibration.html
//*/
//__declspec(dllexport) void createHoloLenCamParam()
//{
//	ARdouble intr[3][4] = {
//		{1611.7697684344448, 0.0, 656.607901398176},
//		{0.0, 1611.9107708992226, 365.7201106849852},
//		{0.0f, 0.0f, 1.0f},
//	};
//	ARdouble dist[4] = {0.026319872225231526, -0.7098683307234095, 0.0019888403557080194, 0.00921154022201671};
//	int xsize = 1408;
//	int ysize = 792;
//	ARParam paramHolo;
//	convParam(intr, dist, xsize, ysize, &paramHolo);
//	arParamDisp(&paramHolo);
//
//	arParamSave("C:\\Users\\lanssie\\Downloads\\LQs\\HoloLensARToolKit - master\\HoloLensARSample\\Assets\\StreamingAssets\\lanssie.dat", 1, &paramHolo);
//	//arParamSave("lanssie.dat",1, &paramHolo);
//
//}
//
//

// Lanssiekit.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


//#include "UnityNativeUWPDll.h"
#include "windows.media.core.h"
#include "windows.media.capture.h"
#include <AR/ar.h>
#include <Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "C:/Users/lanssie/AppData/Local/Programs/Python/Python36/Lib/site-packages/numpy/core/include/numpy/arrayobject.h"
#include<iostream>

//extern "C" {FILE __imp_func[3] = { *printf, *fprintf, *stderr }; }

ARdouble getSizeFactor(ARdouble dist_factor[], int xsize, int ysize, int dist_function_version)
{
	ARdouble  ox, oy, ix, iy;
	ARdouble  olen, ilen;
	ARdouble  sf, sf1;

	sf = 100.0;

	ox = 0.0;
	oy = dist_factor[7];
	olen = dist_factor[6];
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = dist_factor[6] - ix;
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	ox = xsize;
	oy = dist_factor[7];
	olen = xsize - dist_factor[6];
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = ix - dist_factor[6];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	ox = dist_factor[6];
	oy = 0.0;
	olen = dist_factor[7];
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = dist_factor[7] - iy;
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	ox = dist_factor[6];
	oy = ysize;
	olen = ysize - dist_factor[7];
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = iy - dist_factor[7];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}


	ox = 0.0;
	oy = 0.0;
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = dist_factor[6] - ix;
	olen = dist_factor[6];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}
	ilen = dist_factor[7] - iy;
	olen = dist_factor[7];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	ox = xsize;
	oy = 0.0;
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = ix - dist_factor[6];
	olen = xsize - dist_factor[6];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}
	ilen = dist_factor[7] - iy;
	olen = dist_factor[7];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	ox = 0.0;
	oy = ysize;
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = dist_factor[6] - ix;
	olen = dist_factor[6];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}
	ilen = iy - dist_factor[7];
	olen = ysize - dist_factor[7];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	ox = xsize;
	oy = ysize;
	arParamObserv2Ideal(dist_factor, ox, oy, &ix, &iy, dist_function_version);
	ilen = ix - dist_factor[6];
	olen = xsize - dist_factor[6];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}
	ilen = iy - dist_factor[7];
	olen = ysize - dist_factor[7];
	//ARLOG("Olen = %f, Ilen = %f, s = %f\n", olen, ilen, ilen / olen);
	if (ilen > 0)
	{
		sf1 = ilen / olen;
		if (sf1 < sf) sf = sf1;
	}

	if (sf == 100.0) sf = 1.0;

	return sf;
}

void convParam(ARdouble intr[3][4], ARdouble dist[4], int xsize, int ysize, ARParam *param)
{
	ARdouble   s;
	int      i, j;

	param->dist_function_version = 4;
	param->xsize = xsize;
	param->ysize = ysize;

	param->dist_factor[0] = (ARdouble)dist[0];     /* k1  */
	param->dist_factor[1] = (ARdouble)dist[1];     /* k2  */
	param->dist_factor[2] = (ARdouble)dist[2];     /* p1  */
	param->dist_factor[3] = (ARdouble)dist[3];     /* p2  */
	param->dist_factor[4] = (ARdouble)intr[0][0];  /* fx  */
	param->dist_factor[5] = (ARdouble)intr[1][1];  /* fy  */
	param->dist_factor[6] = (ARdouble)intr[0][2];  /* x0  */
	param->dist_factor[7] = (ARdouble)intr[1][2];  /* y0  */
	param->dist_factor[8] = (ARdouble)1.0;         /* s   */

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 4; i++)
		{
			param->mat[j][i] = (ARdouble)intr[j][i];
		}
	}

	s = getSizeFactor(param->dist_factor, xsize, ysize, param->dist_function_version);
	param->mat[0][0] /= s;
	param->mat[0][1] /= s;
	param->mat[1][0] /= s;
	param->mat[1][1] /= s;
	param->dist_factor[8] = s;
}

extern "C"
{
	__declspec(dllexport) int testInt()
	{
		return 25;
	}

	__declspec(dllexport) int createHoloLenCamParam(const char* saveLocation, double openCVCamMatrix[][3], double coeff[4], int w, int h)
	{
		/*ARdouble intr[3][4] = {
			{1611.7697684344448, 0.0, 656.607901398176},
			{0.0, 1611.9107708992226, 365.7201106849852},
			{0.0f, 0.0f, 1.0f},
		};*/
		ARdouble intr[3][4] = {
			{0.0, 0.0, 0.0},
			{0.0, 0.0, 0.0},
			{0.0f, 0.0f, 1.0f},
		};
		ARdouble *jp; /*= &dist[0];*/
		ARdouble *kp;
		double *pp;
		for(int j = 0; j < 2; j ++)
		{
			for (int k = 0; k < 3; k++)
			{
				jp = &intr[j][k];
				pp = &openCVCamMatrix[j][k];
				*jp = (ARdouble)*pp;
			}
		}
		//distance coefficient things;
		ARdouble dist[4] = {0};
		ARdouble *p; /*= &dist[0];*/
		double *np;/* = &coeff[0];*/
		for (int i = 0; i<4; i++)
		{	
			p = &dist[i];
			np = &coeff[i];
			*p = (ARdouble) *np;
		}
		//ARdouble dist[4] = {0.026319872225231526, -0.7098683307234095, 0.0019888403557080194, 0.00921154022201671};
		//int xsize = 1408;
		//int ysize = 792;
		ARParam paramHolo;
		convParam(intr, dist, w, h, &paramHolo);
		arParamDisp(&paramHolo);

		arParamSave(saveLocation, 1, &paramHolo);
		//arParamSave("lanssie.dat",1, &paramHolo);
		return h+w;
	}

	__declspec(dllexport) int pyscript(const char* pythonCommandLocation)
	{
		//int i, char * a0, char * a1, char* a2, char* a3, char* a4, char* a5, char* a6, char* a7
		/*Py_Initialize();
		FILE* f = fopen("otherTest.py", "r");
		PyRun_SimpleFile(f, "otherTest.py");
		Py_Finalize();*/
		//import_array()
		//FILE* f = fopen("otherTest.py", "r");
		//PyObject *pArgs, *pReturn, *pModule, *pFunc;
		//PyArrayObject *np_ret, *np_arg;
		//PyRun_SimpleFile(f, "otherTest.py");


		//IT WORKS MOFOOOO
		//system("python C:\\Users\\lanssie\\Downloads\\LQs\\Lanssiekit\\lanssie-test\\Lanssiekit\\Lanssiekit\\test.py");
		//std::string command = "python" + pythonCommandLocation;
		system(pythonCommandLocation);
		//system("pause");
		//--square_size 0.03 --pattern_width 7 --pattern_height 5 lanssie - near//*.jpg");
		
		return 0;
	}
}
/*
Conversion from opencv camera calibration to artoolkit camera calibration
OpenCV camera calibration format: http://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_calib3d/py_calibration/py_calibration.html
*/
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
//	//arParam
//}
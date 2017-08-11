HoloLens Camera Calibration
===
Author: [Lanssie Ma] (lanssie.com)

Date: 8. 11. 2017

## Intro
Building on top of this camera calibration series on Github here:https://github.com/qian256/HoloLensCamCalib, and decided to condense this into a much shorter process through a native Unity Plugin. What this does is create a camera calibration matrix (AToolKit format) from the HoloLens' camera point of view. You can later on use this for your HoloLens related applications build on ARToolKit. 
Broken down this plugin will call itself, as well as a python script internally. It works with extending the ARToolKit (version 5) further as plugin in Unity and also utilizes part of OpenCV.
The plugin folder is the source code, and the HoloLensCamCalib\HoloLensARToolKitCameraCalibrationSamples\HoloLensARSample\Assets\Sample contains a Unity project with the plugin already built in it, with all the notes carried out. Only the paths in the details below need to be modified.

## Steps in Detail:
Note that all paths must just \\ or /. 
1. Users first need to print out this chessboard picture, and take a series of at least 10 pictures from various angles from the HoloLens. 
2. Users place these files into the directory of your choice. It's easier if it's in the same directory as this plugin directory.  
3. Open Unity, users need to just create a gameobject with the script ARcalib.cs and input the following information. For reference, using the direct full path is often the safest way of completing this. 
	a. Path of the .dat (camera calibration matrix) in your directory.
	b. Square size of the chessboard, default 1.0
	c. Pattern width, default 7
	d. Pattern height, default 5
	e. Path of the photos you took in step 1-2, best if (myfolder/*.jpg)
	f. Path where you want to output the camera matrix files (I suggest Streaming Assets)
	g. Path of the Python file. dir\\calibration.py. You can move it around if you wish, but I suggest keeping it where it is in the plugins folder. 
4. Press Play.
	a. The python terminal will appear, and you can look at the output information before pressing enter to close the window.
5. The outputs are 2 camera matrix files (same matrix just in different formats) in the Streaming Assests folder. 
6. In ARUWP Controller object, update the .dat file to the file you just created, currently called CAM.json and CAM.yaml. 
7. Build and deploy to HoloLens!

If you want to learn more about camera calibration, you can learn about it through these few links that give tutorials and more math behind how these processes work. 
A few tutorials: 
http://docs.opencv.org/3.1.0/d4/d94/tutorial_camera_calibration.html
http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_calib3d/py_calibration/py_calibration.html
http://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html
What even is Camera Calibration? It estimates the parameters of a lens and image sensor of an image or video camera.  
The next step of perfecting camera calibration! https://arxiv.org/abs/1703.05834

-------

This repository contains **camera calibration file** of HoloLens [front-facing camera](https://developer.microsoft.com/en-us/windows/holographic/locatable_camera), with the 896x504 configuration. Please refer to [**Locatable Camera in Unity**](https://developer.microsoft.com/en-us/windows/mixed-reality/locatable_camera_in_unity) about how to obtain chessboard images from your own HoloLens.

## Near range calibration
The folder ```near``` contains calibration images collected from HoloLens and the calibration results of it.
The calibration pattern for near range calibration is (7x5, 30cm).
The images are taken from a distance of **about 0.3m to 0.5m**.

## Far range calibration
The folder ```far``` contains the calibration images and results of HoloLens, with distance of **about 1m to 1.5m**.
The calibration pattern configuration is (11x7, 45cm).

## Scripts
* ```calibrate.py``` and ```common.py``` are adapted from OpenCV project. Example usage is:
```bash
python calibrate.py --square_size 0.03 --pattern_width 7 --pattern_height 5 data1/raw/*.jpg
```
* ```cv2.CALIB_FIX_K3``` flag is set for function ```cv2.calibrateCamera``` in order for consistent adpation to ARToolKit camera parameter.
* ```scripts/ARToolKitCalibrationFileGenerator.cpp``` generates binary camera calibration file for ARToolKit. You need to correctly include the header files of ARToolKit and link to ARToolKit libraries.
* ```scripts/ARToolKitCalibrationFileReader.py``` makes your life easier when you want to see the values of an ARToolKit calibration file, and modify them.


## Results
* ```hololens896x504.json``` and ```hololens896x504.yaml``` are the camera calibration files of [OpenCV format](http://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html).
* ```hololens896x504.dat``` is the calibration file of HoloLens camera, for [ARToolKit](https://artoolkit.org/documentation/doku.php?id=2_Configuration:config_camera_calibration).


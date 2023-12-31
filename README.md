# OF_webcamShaders
OF_webcamShaders is a project that combines the power of openFrameworks (OF) with webcam input and shaders. This project is a framework for integrating real-time webcam feed with customizable shaders, allowing users to apply various visual effects to the video stream.

## Features

A variety of fragment shaders are used, some in conjunction, to apply these four effects to the webcam feed:
* Colour-altering fragment shader
* Threshold 'bloom' shader which highlights parts of the image
* Threshold 'shadow' ahder which intensifies dark parts of the image
* Glitchy shader based on sin(time)

## Dependencies

Make sure you have the following dependencies installed before running the project:

- [openFrameworks](https://openframeworks.cc/download/)

## Getting Started

1. Clone this repository:

    ```bash
    git clone https://github.com/your_username/OF_webcamShaders.git
    ```

2. Generate a new OpenFrameworks project (tested version 0.11.1)

3. Replace the contents of 'src' and 'bin/data' with the files from this repo

4. Experiment with different shaders and customize the code to create your own visual effects!

## License
This project is licensed under the MIT License.

# A lightweight abstraction for the most essential components of CSFML
## Pre-requisites
### Important packages to install (Tested on linux mint 22)
- build-essential cmake git libx11-dev freeglut3-dev libxcb-image0-dev libudev-dev libjpeg8-dev libopenal-dev libsndfile1-dev libfreetype6-dev
## How to run
- Run only once
chmod +x build.sh
- Run each time you make changes
./build.sh 
./build/Your_project_name_here
## Example usage
- See src/main.c for a simple example of how to use the library.
- See CMakeLists.txt for how to link the library to your project.
- See headers/ and src/ for the library source code.
## Features
- Window creation and management
- Basic graphics handling (Sprites, colors)
- Basic audio handling (Sound effects, music)
- Resource management (Loading and freeing resources)
## Planned features
- More graphics features (Shapes, text)
- More audio features (3D sound, streaming)
- Input handling (Keyboard, mouse, joystick)
- Networking (TCP, UDP)
- More robust error handling and logging
- Documentation and examples
## Contributing
- Feel free to fork the repository and submit pull requests.
- Report issues and suggest features via GitHub issues.
## License
- This project is licensed under the MIT License. See the LICENSE file for details.

# Agama Renderer

- A simple 3d renderer for my personal use

## Running the project

### Configure
```sh
# run this command only once
./setup.sh
```
### Build
```sh
./build.sh
```
### Running
```sh
./run.sh
```

## Output Recording

![](output/recording_2.gif)


## RoadMap

- **Make rectangle rotate in 3d with camera system**
  - [x] Write the boiler code for opengl
  - [x] Create Basic shader
  - [x] Create VBO for triangle and draw two of them
  - [x] Implement Camera System
  - [x] Rotate that shit
- **Draw 3d Models with lighting**
  - [x] Texture (UV coords and glTexture2d)
  - [x] Way to dynamically spawn cubes on mouse click
  - [ ] Import 3d Models
  - [ ] Triangle class (way to draw triangle elegantly)
  - [ ] Do Blinn-Phong Lighting system
- **Implement a particle system**
  - [ ] Particle system

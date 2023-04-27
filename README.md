# C++ Raycasting Engine

Simple engine to make games à la Wolfenstein3D, made entirely in C++, using SDL2 to handle graphics.

It's sill pretty rough, but very cute also <3

## Guide

To change the map, edit the 'map' file in the 'Map' folder.

<pre>
'1' = wall

' ' = floor/empty space

'P' = player's starting position
</pre>

The map should be surrounded by walls. If it's not and the player walks outside of it, the program's behaviour is undefined.

If there's more than one 'P' in the map or different symbols than the ones listed above, the program's behaviour is undefined as well.

The idea is to implement a map editor in the future, that's why I'm not having the game handle incorrectly filled maps. The editor will. Eventually.


## Demo

Only on Linux: run 'make play'

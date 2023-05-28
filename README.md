# Ray (2023)
Simple engine to make and then navigate 3D maps à la Wolfenstein3D, made entirely in C++ using the SDL2 library to handle graphics.

It's pretty rough, but very cute also <3

![Ray](https://user-images.githubusercontent.com/95633668/236510960-177c5dd1-4c86-47d4-941d-655a027ba7be.png)

# Guide
After selecting a size for the map, the editor will open.
## Draw Walls
Use the **red spray** tool to place walls:

<img src="https://user-images.githubusercontent.com/95633668/236492963-d5856c89-7ddc-4e4d-a353-6ce67801af7e.gif" width=50% height=50%>

## Erase Walls
Use the **black spray** tool or the **mouse right button** to erase walls:

<img src="https://user-images.githubusercontent.com/95633668/236494717-5a2de2dc-17df-4705-82b2-bd55f94d35d6.gif" width=50% height=50%>

## A Place to Start
Use the **green spray** tool to set an initial position for the navigation.

This is mandatory, the rendering of the map will not start without it.

<img src="https://user-images.githubusercontent.com/95633668/236495370-fe336c0a-fc18-4952-91ec-8bc3119b7977.gif" width=50% height=50%>

## Done
Finally, click on the **START** button and enjoy a nice walk through the map you've just drawn!

<img src="https://user-images.githubusercontent.com/95633668/236495700-05551006-9bf2-4922-8dd8-633f55bb5cdd.gif" width=50% height=50%>

## Navigation
Use **W**, **A**, **S** and **D** to move and the **left** and **right arrow keys** to rotate.
## Exit
Press **ESC** to exit anytime.

# Compilation
## Windows
run <code>make -C srcs</code> to compile an executable directly in the main folder.

## Linux
run <code>make -C srcs/UNIX_Makefile</code> to compile an executable in the main folder.

## Mac
Sorry, guys, you're on your own for now.

# Plans for future implementations
I'd like to add:
- A save/load system for the maps
- Mouse controlled rotation during navigation
- The possibility to place walls of different colors
- A loading system for external textures to use as walls or sprites
- A way to set movement patterns for the sprites
- Wait, is this becoming a game engine project?
- I really hope not, it would be exhausting and dreadfully time consuming...

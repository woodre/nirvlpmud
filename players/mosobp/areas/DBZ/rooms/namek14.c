inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A foyer");
set_long(
"This is a hallway in the castle. It looks like the walls are all soggy and wet.
  Up ahead you seem to see the outline of some stairs.");
add_item("outline","The outlines look like some stairs.");
add_item("walls","You see mildew on the wall.");
add_item("stairs","The stairs to the next floor of the castle.");
add_item("hallway","The path you are walking.");
add_exit("/players/gohan/namek/namek19.c","north");
add_exit("/players/gohan/namek/namek14.c","west");
}

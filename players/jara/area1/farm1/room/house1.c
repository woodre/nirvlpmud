/* Farm1, House1, Created <6/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="An old Farmhouse";
  long_desc=
    "  The wooden floor of the main room is well worn and covered in a thin\n"+
    "layer of dust. A row of workboots have been placed beside the door, and\n"+
    "a rocking chair is beside the front window. A hand-woven rug with dark\n"+
    "red and blue patterns is on the floor in the center of the room, and a\n"+
    "carved, wooden table and three chairs stand on the rug. A door in the\n"+ 
    "western wall leads to a bedroom, and the kitchen is to the east. There\n"+
    "is a narrow staircase leading upstairs.\n";
  items=({
    "floor",
    "The floor is made of light colored wooden panels, nailed together with\n"+
    "thick metal nails",
    "nails",
    "The round heads of the metal nails are all that is visible in the floor",
    "dust",
    "The dust is light brown in color",
    "workboots",
    "Sturdy, leather workboots with strong laces and support throughout the\n"+
    "ankles",
    "door",
    "There is a wooden door that leads to the porch, and a second door that"+
    "leads to a bedroom",
    "chair",
    "A hand-crafted rocking chair, made of a dark wood",
    "rug",
    "An oval shaped rug with an intricate red and blue pattern. The rug is\n"+
    "very worn",
    "staircase",
    "A narrow flight of stairs with a wooden handrail",
    "handrail",
    "The handrail is made of wood, and circular in shape",
    "table",
    "A table carved of a dark wood, oval in shape, with many knicks on the\n"+
    "surface",
    "chairs",
    "The chairs are carved of a dark wood and are very sturdy",
    "kitchen",
    "The kitchen is a large room, with wooden cupboards and a metal stove",
    "cupboards",
    "Cupboards made of a light colored wood, with handles and several rows\n"+
    "of shelves",
    "shelves",
    "The shelves hold food and cooking supplies",
    "stove",
    "A round metal stove with a pipe that extends from the stove through the\n"+
    "ceiling" });
  dest_dir=({ 
    PATH+"house4","east",
    PATH+"house2","west",
    PATH+"house3","up",
    PATH+"path8","out" });
}

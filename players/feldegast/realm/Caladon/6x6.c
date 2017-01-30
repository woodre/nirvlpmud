/*
File: 6x6.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object portal;
  ::reset(arg);
  if(arg) return;
  portal=clone_object(OBJ_PATH+"azure_portal.c");
  portal->set_destination("/players/feldegast/shrine.c");
  move_object(portal,this_object());
  x=6; y=6;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  You are high atop a hill overlooking the city of Calador to the\n\
southwest.  To the west is a well-paved road that runs north and south.\n\
As the tallest hill for miles around, this spot offers an excellent\n\
view of the rolling landscape.\n";
  items=({
    "foothills", "The hills are dotted with trees",
    "hills", "The hills are dotted with trees",
    "trees", "Tall, deciduous trees dot the hills",
    "road", "The road is paved with cobbles",
    "city", "The walled city of Calador is the prosperous Baronial seat of\n"+
            "the Barony of Caladon",
    "wall", "Calador is surrounded on all sides by walls ten meters tall with\n"+
            "towers every hundred meters",
    "calador", "The walled city of Calador is the prosperous Baronial seat of\n"+
               "the Barony of Caladon",
    "hill", "It is dotted with leafy green trees and near the top is a strange blue light",
    "landscape", "You are surrounded in all directions by rolling green hills",
  });
  dest_dir=({
    PATH+"6x7.c","north",
    PATH+"5x6.c","west",
    PATH+"7x6.c","east",
    PATH+"6x5.c","south",
  });
}


/*
File: 5x6.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=5; y=6;
  set_light(1);
  short_desc="Baron's Highway";
  long_desc=
"  A well-paved road winds south through low foothills dotted with\n\
trees.  Directly to the south is the walled city of Calador, the\n\
baronial seat of Caladon.  To the east is a hill with a strange blue\n\
light near the top.\n";
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
    "hill", "To the east of the road a hill rises steeply.  It is dotted with\n"+
            "leafy green trees and near the top is a strange blue light",
  });
  dest_dir=({
    PATH+"5x7.c","north",
    PATH+"4x6.c","west",
    PATH+"6x6.c","east",
    CALADOR+"quartz1.c","south",
  });
}


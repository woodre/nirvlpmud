/*
File: marble3.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  Town Square.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"     Tall buildings surround the town square of the city of\n"+
"Calador.  In the center of the square is a magnificent marble\n"+
"fountain with openmouthed fishes spitting plumes of water.\n"+
"To the north is a gothic cathedral while to the south are\n"+
"the steps of city hall.\n";
  items=({
    "buildings", "The crowded buildings of Calador are typically two to three\n"+
                 "stories in height.  The buildings near you are prosperous\n"+
                 "and well-maintained",
    "fountain",  "A white marble fountain with fishes spitting plumes of water",
    "plumes",    "Frothing white water leaving a rainbow trail in the mist",
    "water",     "The water frothes white",
    "cathedral", "A tall arching cathedral of the gothic style",
    "steps",     "Tall steps leading up to the entrance",
    "city hall", "A tall three story building that looks official"
  });
  dest_dir=({
    PATH+"cathedral","north",
    PATH+"marble2","west",
    PATH+"marble4","east",
    PATH+"townhall","south"
  });
}   

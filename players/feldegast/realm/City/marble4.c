/*
File: marble4.c
Author: Feldegast
Revised: 03/24/02
Description:
  Marble street.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  In the very center of Calador, Marble and Quartz street meet in a\n\
circular plaza with potted plants along the circumference and a bed of\n\
yellow daffodils in the center.  The busy people of the city stride\n\
purposefully through the plaza as they hurry about on their business.\n";
  /* Who do I sound like here? Blech. */

  items=({
    "plaza",         "reflexive",
    "plants",        "The potted plants add color to the otherwise achromatic city",
    "potted plants", "The potted plants add color to the otherwise achromatic city",
    "bed",           "The bed of yellow daffodils shine brightly in the spring sun",
    "daffodils",     "The bed of yellow daffodils shine brightly in the spring sun",
    "city",          "The free city of Calador is a busy, predominantly bourgeois city",
    "people",        "The busy people of the city move about on their business",
  });
  dest_dir=({
    PATH+"quartz2","north",
    PATH+"marble3","west",
    PATH+"marble5","east",
    PATH+"quartz3","south"
  });
}   

/*
File: marble5.c
Author: Feldegast
Created: 04/01/02
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
"  Marble street wends from east to west through a hilly urban\n\
district.  Shops, offices and apartment buildings line either side\n\
of the street.  The busy people of the city move quickly about\n\
their business.\n";

  items=({
    "city",          "The free city of Calador is a busy, predominantly bourgeois city",
    "people",        "The busy people of the city move about on their business",
    "street",   "The street is made out of cobblestones and appears well\n"+
                "maintained.  Merchants and peasants hustle and bustle about\n"+
                "their business",
    "district", "This part of Calador was built upon hilly terrain, with buildings\n"+
                "placed at odd angles to each other",
    "shops",    "None of the shops appear to be of interest to you",
    "offices",  "None of the offices appear to be of interest to you",    

  });
  dest_dir=({
    PATH+"marble4","west",
    PATH+"marble6","east",
  });
}   

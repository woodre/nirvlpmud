/*
File: quartz2.c
Author: Feldegast
Date: 3/23/02
Description:
  Quartz street.
*/

#include "defs.h"

inherit ROOM;

reset(arg) 
{
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Quartz street goes north and south from here straight through the\n\
center of the city.  Shops and townhouses line either side of the\n\
crowded street.  To the south of you is an intersection.\n";

  items=({
    "calador",  "It looks like a busy, but clean, city",
    "street",   "The street is made out of cobblestones and appears well\n"+
                "maintained.  Merchants and peasants hustle and bustle about\n"+
                "their business",
    "streets",  "The street is made out of cobblestones and appears well\n"+
                "maintained.  Merchants and peasants hustle and bustle about\n"+
                "their business",

    "quartz street","The street is made out of cobblestones and appears well\n"+
                    "maintained.  Merchants and peasants hustle and bustle about\n"+
                    "their business",
    "city",         "The free city of Calador is a busy, predominantly bourgeous city",
    "merchants",    "They bustle and bustle about their daily business",
    "peasants",     "They bustle and bustle about their daily business",
    "intersection", "Just to the south, Quartz street intersects with Marble street",
    "shops",        "None of the shops appear to be of interest to you",
    "townhouses",   "Neat little townhouses line the street",
  });
  dest_dir=({
    PATH+"quartz1.c", "north",
    PATH+"marble4.c","south",
  });
}   

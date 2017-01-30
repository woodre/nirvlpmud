/*
File: quartz4.c
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
/********************************************************************/
"  Quartz street ends to the south of here by the side of the River\n\
Xian.  A few small boats ply the chilly waters of the river, but\n\
produce little to trade.  This area of the city mostly consists of\n\
warehouses and private offices.\n";
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
    "warehouses",   "Most of the nearby warehouses appear to be empty",
    "offices", "You see nothing of interest about them",
    "private offices", "You see nothing of interest about them",
  });
  dest_dir=({
    PATH+"quartz3.c", "north",
  });
}   

/*
File: marble2.c
Author: Feldegast
Date: 3/23/02
Description:
  Marble street.
*/

#include "defs.h"

inherit ROOM;

reset(arg) 
{
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Marble street goes east and west through the heart of the city.  To\n\
the north Sapphire street begins, and to the south Copper street sags\n\
limply down to the river.  The streets teem busily with people.\n";
  items=({
    "calador",  "It looks like a busy, but clean, city",
    "street",   "The street is made out of cobblestones and appears well\n"+
                "maintained.  Merchants and peasants hustle and bustle about\n"+
                "their business",
    "streets",  "The street is made out of cobblestones and appears well\n"+
                "maintained.  Merchants and peasants hustle and bustle about\n"+
                "their business",
    "marble street","The street is made out of cobblestones and appears well\n"+
                    "maintained.  Merchants and peasants hustle and bustle about\n"+
                    "their business",
    "city",     "The free city of Calador is a busy, predominantly bourgeois city",
    "river", "The River Xian flows south of the city",
    "people", "The busy people of Calador move about, doing their daily business",
  });

  dest_dir=({
    PATH+"saph1.c",  "north",
    PATH+"marble1.c","west",
    PATH+"marble3.c","east",
    PATH+"copper1.c","south",
  });
}   

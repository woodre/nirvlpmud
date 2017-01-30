/*
File: marble1.c
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
"  To the west of you is the Barbarian Gate, which leads out of\n\
Calador, the capital of the Barony of Caladon.  Marble street begins\n\
at the gate and proceeds east, straight through the middle of the\n\
city.  Merchants and peasants crowd the streets as they go about their\n\
daily business.\n";

  items=({
    "gate",     "The gate is currently open, allowing passage in and out of\n"+
                "the city, however it can be closed at a moment's notice in\n"+
                "the event of war",
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
    "city",     "The free city of Calador is a busy, predominantly bourgeous city",
    "merchants","They bustle and bustle about their daily business",
    "peasants", "They bustle and bustle about their daily business",
  });

  dest_dir=({
    CALADON+"4x5.c", "west",
    PATH+"marble2.c","east",
  });
}   

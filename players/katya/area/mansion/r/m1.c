/*
 *     m1.c              
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "/players/vertebraker/closed/std/room";


reset(arg) {
  if(!arg)
  { 

   set_light(1);

   short_desc = HIK+"Mansion"+NORM;

   long_desc="\
A large stained glass window rests above an enormous solid oak door.\n\
Swaying from the cathedral ceiling is a dimly lit crystal chandler.\n\
The hard wood floors are covered in a red Asian printed rug that flows\n\
over the entire floor.  A large red carpeted oak staircase leads up to \n\
the second floor. Arched doorways lead east and west to the library\n\
and to the den.\n",

 items=({
"window",
        "A large stained glass window with an Asian design",
"glass",
        "A large stained glass window with an Asian design",
   });
}
}

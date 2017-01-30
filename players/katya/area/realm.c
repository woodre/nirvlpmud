/*
 *     realm.c              
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "/players/vertebraker/closed/std/room";

#define TP this_player()

reset(arg) {
  if(!arg)
  { 

   set_light(1);

   short_desc = HIM+"Forgotten Realm"+NORM;

   long_desc="\
   A magical realm that will send you to other worlds to explore.\n\
Following are realms you may get to from your currently location.\n\n\
                    Esquire                                      Lijiang\n\n",

 items=({
"esquire",
        "A large old looking theatre building with little square windows",
"lijiang",
        "A large snow capped mountain",
 });

       add_exit("/room/south/sforst6","out");
       add_exit("/players/katya/area/esquire/r/entrance.c","esquire");
       add_exit("/players/katya/area/mountain/r/m1.c","lijiang");

 }

}

/*
File: rat4.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  The rat's nest.
*/

#include "defs.h"
inherit ROOM;

int key_is_here;
int lit;

reset(arg) 
{
  if (arg) return;
  short_desc="Rat's Lair";
  long_desc=
"    Magnificent carpets and tapestries apoint this cozy yet\n"+
"eclectic den, covering every nook and cranny.  In the middle\n"+
"of this lair is a comfortable, yet oft patched sofa.  On a\n"+
"sidetable is a lantern.  Random objects and baubles are\n"+
"scattered around this room with no particular rhyme or\n"+
"reason.\n";

  items=({
    "carpets","Rich reds, royal purples, and natural greens catch your eye",
    "tapestries","You notice some artistry in one or two tapestries, but none\n"+
                 "of them catches your eye",
    "sofa","A comfortable blue sofa with several patchwork repairs done on the\n"+
           "upholstery",
    "lantern","A large bronze lantern with a wick that you could light",
    "objects","Odd bric-a-brac that doesn't catch your interest",
    "baubles","A few shiny rocks, wooden toys, and clothes"
  });

  dest_dir=({
    PATH+"rat3","up",
  });
  key_is_here = 1;
}   

init() {
  ::init();
  add_action("cmd_light","light");
  add_action("cmd_dim","dim");
  add_action("cmd_jump","jump");
  add_action("search","search");
}

search() {
  if(key_is_here) {
    object key;
    write("You find a key hidden under the sofa.\n");
    key=clone_object("/players/feldegast/std/key");
    key->set_short("A bronze key");
    key->set_id("key1212");
    move_object(key,this_player());
    this_player()->recalc_weight();
    key_is_here=0;
    return 1;
  }
  notify_fail("You don't find anything.\n");
}

cmd_light(str) {
  if(str && str=="lantern") {
    if(lit)
    {
      write("The lantern is already lit.\n");
      return 1;
    }
    write("You light the lantern.\n");
    set_light(1);
    lit=1;
    return 1;
  }
  notify_fail("Light what?\n");
}

cmd_dim(str) {
  if(str && str=="lantern") {
    if(!lit) {
      write("The lantern isn't lit.\n");
      return 1;
    }
    write("You dim the lantern.\n");
    set_light(-1);
    lit=0;
    return 1;
  }
  notify_fail("Dim what?\n");
}


/*
File: raven8.c
Author: Feldegast
Date: 10/22/01
Description:
  Top of the Tower of Ravens in Caladon.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return; /* Intentional. */
  if(!present("mistress of ravens"))
    move_object(clone_object(MON_PATH+"arien.c"), this_object());
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  This is a large, comfortable chamber at the very top of the Tower\n\
of Ravens.  A large bed, covered with silk sheets, sits atop a dais.\n\
A velvet-lined divan sits by a balcony which looks out over the\n\
countryside.\n";
  items=({
    "chamber", "reflexive",
    "bed", "It is ten feet square and covered with red silk sheets",
    "dais", "The dais raises the bed a few feet above the floor",
    "divan", "A velvet-lined divan sits by the balcony",
    "balcony", "The balcony looks out over the countryside",
    "countryside", "Chris Cisneros is a pimple-faced weenie!",
  });
  dest_dir=({
    PATH+"raven6.c", "south",
  });
}

view_room(str) {
  object targ,ob;
  
  targ=find_object(str);
  write(targ->short()+"\n");
  targ->long();
  ob=first_inventory(targ);  
  while(ob) {
    write(ob->short()+"\n");
    ob=next_inventory(ob);    
  }
  write("\n");
}

void long(string str)
{
  if(str == "countryside")
    view_room(PATH+"1x8.c");
  else
    ::long(str);
}


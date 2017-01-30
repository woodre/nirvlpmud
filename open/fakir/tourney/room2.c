#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+"Grand Tournament of Nirvana"+NORM;
  long_desc=
    "Burnished bronze figures line the walls and portray various styles of armed\n"+
    "combat.  Above each figure is a polished shield of silver inscibed with the\n"+
    "names of opponents, and listing victorys and defeats.  \n";
  items=({
  });
  dest_dir=({
    PATH+"room3.c","north",
    PATH+"room1.c","south",
  });
}

void init() {
  object ob;
  object next;
  ::init();
  if((int)this_player()->query_level() < 20) {
    command("drop all",this_player());
    ob=first_inventory(this_object());
    while(ob) { /* Move the junk to a holding room. */
      next=next_inventory(ob);
      if(!living(ob)) {
        move_object(ob,PATH+"drain.c");
        tell_room(this_object(),(string)ob->short()+" falls down the chute.\n");
      }
      ob=next;
    }
  }
  add_action("cmd_north","north");
}

int cmd_north(string str) {
  if((int)this_player()->query_level() < 20) {
    write("\nAs you pass through the archway, you sign your name to the list\n"+
          "of combatants for the next round.\n\n");
    MASTER->add_player((string)this_player()->query_real_name());
  }
  ::cmd_move(str);
  return 1;
}

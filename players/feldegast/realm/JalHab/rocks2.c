#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("goblin"))
    move_object(clone_object(MON_PATH+"brigand5.c"),this_object());
  if(!present("dwarf"))
    move_object(clone_object(MON_PATH+"brigand4.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Brigand Cave";
  long_desc=
"  A long wooden table is placed in the center of this dimly lit\n"+
"cavern.  On it are the remains of a feast upon which the brigands\n"+
"have gorged themselves.  A tunnel to the north leads further into\n"+
"the caves, and a passageway leads back into the light.\n";
  items=({
    "table","A long wooden table made out of oak that is heavily\n"+
            "scarred with rude sketches and initials such as B.B.,\n"+
            "B.M. and S.O.B",
    "feast","Cracked porcelain plates littered with pork ribs picked\n"+
            "clean, bare corn cobs, and ground pepper spilt on the\n"+
            "floor",
    "tunnel","The tunnel leads deeper into the caves",
    "passageway","It leads back outside",
  });
  dest_dir=({
    PATH+"rocks1.c","out",
    PATH+"rocks3.c","north",
  });
}

void init() {
  ::init();
  add_action("cmd_north","north");
}

int cmd_north(string str) {
  object brig;
  brig=present("brigand");
  if(brig) {
    tell_room(this_object(),(string)brig->query_name()+" says: Hey!  What do you think YOU'RE doing?\n");
    brig->attack_object(this_player());
    return 1;
  }
}

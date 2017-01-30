#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("khazanth");
  set_alias("dragon");
  set_short(BOLD+BLK+"A black dragon"+NORM);
  set_race("dragon");
  set_long(
    "The black dragon is a creature of terrifying beauty and power, its\n"+
    "rock hard scales, razor sharp fangs, and javelin-like claws making it\n"+
    "a near perfect engine of destruction.  The black dragon's red eyes"+
    "seeth with a naked hatred for all living things.  Despite this, it\n"+
    "does not attack you, almost as though it were under someone's else's\n"+
    "power.  You believe you could 'mount' the dragon if you wanted to.\n"
  );
  set_gender("female");
  set_level(25);
  set_wc(50);
  set_ac(100); /* Not really meant to be killed. */
  set_hp(5000);
  set_al(-1000);
  set_chat_chance(3);
  load_chat("The black dragon stares at you expectantly.\n");
  load_chat("The black dragon snorts, spraying a cloud of acid into the air.\n");
  set_a_chat_chance(5);
  load_a_chat("Your blows fail to harm the black dragon.\n");
  load_a_chat("The black dragon slashes you with its claws.\n");
  load_a_chat("The black dragon bites into your forearm.\n");
  load_a_chat("The black dragon sprays you with its acidic breath!\n");
}

void init() {
  ::init();
  add_action("cmd_mount","mount");
}

int cmd_mount(string str) {
  if(!str || str!="dragon") {
    notify_fail("Mount what?\n");
    return 0;
  }
  say((string)this_player()->query_name()+" mounts the dragon and takes off into the sky.\n");
  if((int)environment()->query_loc()==1) {
    move_object(this_object(),ROOMDIR+"plaza.c");
    move_object(this_player(),ROOMDIR+"plaza.c");
    write("\nYou mount the dragon and soon find yourself flying swiftly\n"+
          "over Nirvana's landscape.  After you don't know how long,\n"+
          "the dragon lands in a plaza.  You swiftly dismount.\n\n");
  } else {
    move_object(this_object(),ROOMDIR+"tower_top.c");
    move_object(this_player(),ROOMDIR+"tower_top.c");
    write("\nYou mount the dragon and soon find yourself flying swiftly\n"+
          "over Nirvana's landscape.  After you don't know how long,\n"+
          "the dragon lands atop the Misty Tower.  You swiftly dismount.\n\n");
  }
  command("look",this_player());
  say((string)this_player()->query_name()+" arrives upon the back of a black dragon.\n");
  return 1;
}

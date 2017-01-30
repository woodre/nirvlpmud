/* An example from Feldegast's jungle island area. */
#include "/players/feldegast/defines.h"
inherit ROOM;
  static opened;
reset(arg) {
  object pirate;
  opened=0;
  if (arg) return;
  set_light(1);
  short_desc="The Captain's Cabin";
  long_desc=
"You are in the captain's cabin of a pirate ship.  The cabin is\n"+
"lavishly decorated with silks and pillows.  A grand piano is in\n"+
"the corner next to a large chest.  A plaque is on the wall.\n";
  items=({
    "silks","Booty from many raids, probably",
    "pillows","Comfortable feather pillows in silk pillow cases",
    "chest","You think you could open it",
    "piano","It looks to heavy to move",
    "plaque","It's a law degree.  The name on it is 'T.P. King'"
  });
  dest_dir=({
    "/players/feldegast/island/ship1","south"
  });
  if(!present("boy")) {
    pirate=clone_object("/obj/monster");
    pirate->set_name("Cabin Boy");
    pirate->set_alt_name("boy");
    pirate->set_long(
"The cabin 'boy' looks to be in his mid-thirties and has a\n"+
"receding hairline.  He does odd jobs around the ship.\n"
    );
    pirate->set_race("human");
    pirate->set_level(4);
    pirate->set_wc(8);
    pirate->set_ac(4);
    pirate->set_hp(60);
    pirate->set_al(-50);
    pirate->set_a_chat_chance(5);
    pirate->load_a_chat("Cabin Boy says: At least I'm not living with my parents anymore.\n");
    pirate->load_a_chat("Cabin Boy says: Life sucks.\n");
    move_object(pirate,this_object());
  }
}
init() {
  ::init();
  add_action("open","open");
}
open(str) {
  object ingot,mirror;
  if(!str) {
     write("Open ");
     return 0;
  }
  if(!str=="chest") {
    write("Open ");
    return 0;
  }
  if(opened) {
    write("Somebody already opened it and took all the stuff.\n");
    return 1;
  }
  if(present("boy")) {
    write("The cabin boy stops you from opening the chest.\n");
    return 1;
  }
  write("You open the chest and spread its contents on the floor.\n");
  ingot=clone_object("obj/treasure");
  ingot->set_short("A Silver Ingot");
  ingot->set_id("silver-ingot-bs");
  ingot->set_alias("ingot");
  ingot->set_value(100);
  ingot->set_long("A solid piece of silver.\n");
  ingot->set_weight(1);
  move_object(ingot,this_object());
  mirror=clone_object("obj/treasure");
  mirror->set_short("A mirror");
  mirror->set_long(
"A ghastly visage appears in the mirror.  You hastily turn it away.\n"
  );
  mirror->set_id("mirror");
  mirror->set_value(50);
  mirror->set_weight(1);
  mirror->set_save_flag(1);
  move_object(mirror,this_object());
  opened=1;
  return 1;
}

#include "/players/feldegast/defines.h"

inherit ROOM;
reset(arg) {
  object pirate;
  if (arg) return;
  set_light(1);
  short_desc="The Crow's Nest";
  long_desc=
"You are high above the rest of the ship, standing on a board\n"+
"near the top of the mast.  You can see for miles in every\n"+
"direction.\n";
  items=({
    "land","There's an island to the east.  It is covered with jungle.",
    "mast","A huge piece of lumber that holds up the sail."
  });
  dest_dir=({
    "/players/feldegast/island/ship1","down"
  });
  if(!present("pirate")) {
    pirate=clone_object("/obj/monster");
    pirate->set_name("Lookout");
    pirate->set_alt_name("lookout");
    pirate->set_alias("pirate");
    pirate->set_long(
"The lookout is a young man with keen blue eyes and windblown\n"+
"hair.\n"
    );
    pirate->set_race("human");
    pirate->set_level(4);
    pirate->set_wc(8);
    pirate->set_ac(4);
    pirate->set_hp(60);
    pirate->set_al(-50);
    pirate->set_chat_chance(5);
    pirate->load_chat("Lookout says: Land ho!\n");
    pirate->load_chat(
"Lookout says: I'm actually afraid of heights.  I'm too scared\n"+
"              to climb down.\n");
    pirate->add_money(100+random(50));
    move_object(pirate,this_object());
  }
}


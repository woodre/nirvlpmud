#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("In the Evil Temple");
  set_long(
"You are in a Evil Temple, behind the alter to the south you can \n"+
"see a huge statue of Kali. to the west a rickety bridge leads into\n"+
"the darkness. The bridge looks wery frail.\n");
  dest_dir = ({
    "players/kantele/dirty_anteroom", "north",
    "players/kantele/behind_altar", "south",
    "players/kantele/on_bridge", "west"
  });
}

void
populate() {
  object fiend;
  if (!present("fiend", this_object())) {
    fiend = clone_object("obj/monster");
    fiend->set_name("pit fiend");
    fiend->set_alias("fiend");
    fiend->set_level(16);
    fiend->set_wc(22);
    fiend->set_ac(13);
    fiend->set_hp(300);
    fiend->set_al(-300);
    fiend->set_short("A huge Pit Fiend is here");
    fiend->set_aggressive(1);
    fiend->add_money(1500);
    fiend->set_chance(30);
    fiend->set_spell_mess1("The Pit Fiend casts a firebolt at you.");
    fiend->set_spell_mess2("You are hit by a firebolt");
    fiend->set_spell_dam(15);
    move_object(fiend,this_object());
  }
}

#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("A small dirty room");
  set_long(
"A small dirty room, It looks like this room was made for some reason\n"+
"The reason is lost to you.\n");
  dest_dir = ({
    "players/kantele/dirty_corridor", "south"
  });
}

void
populate() {
  object priest, mace, key;
  if (!present("priest", this_object())) {
    priest = clone_object("obj/monster");
    priest->set_name("priest");
    priest->set_level(14);
    priest->set_wc(18);
    priest->set_ac(11);
    priest->set_hp(220);
    priest->set_al(-200);
    priest->set_aggressive(1);
    priest->set_move_at_reset();
    priest->set_chance(30);
    priest->set_spell_dam(40);
    priest->set_spell_mess1("The priest throws a curse");
    priest->set_spell_mess2("The priest throws a curse at you, "+
                            "the curse weakens you");
    move_object(priest, this_object());
    mace = clone_object("obj/weapon");
    mace->set_name("mace");
    mace->set_class(17);
    mace->set_value(250);
    mace->set_short("A mace");
    move_object(mace, priest);
    command("wield mace", priest);
    key = clone_object("obj/treasure");
    key->set_id("key");
    key->set_alias("cellar key");
    key->set_short("A key");
    key->set_value(10);
    key->set_weight(1);
    move_object(key, priest);
  }
}

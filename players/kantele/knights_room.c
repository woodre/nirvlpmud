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
  set_short("Knights room");
  set_long(
"You are in 'the knights room', the rooms simple furnishing and\n"+
"and black dekor, shows what type of man he is, you can enter the\n"+
"training room to the east.\n");
  dest_dir = ({
    "players/kantele/office2", "west",
    "players/kantele/training_room", "east"
  });
}

void
populate() {
  object knight, chainmail, blade;
  if (!present("knight", this_object())) {
    knight = clone_object("obj/monster");
    knight->set_name("knight");
    knight->set_short("A black knight is here");
    knight->set_level(19);
    knight->set_whimpy();
    knight->set_al(- 200);
    knight->set_hp(450);
    knight->set_wc(28);
    knight->set_ac(16);
    knight->set_chance(50);
    knight->set_spell_dam(25);
    knight->set_spell_mess1("The knight clanks his shield and blade together");
    knight->set_spell_mess2("The knight clanks his shield and blade together");
    knight->set_aggressive(1);
    knight->set_move_at_reset();
    move_object(knight, this_object());
    chainmail = clone_object("obj/armor");
    chainmail->set_ac(4);
    chainmail->set_alias("armor");
    chainmail->set_type("armor");
    chainmail->set_alias("mail");
    chainmail->set_name("chainmail");
    chainmail->set_value(500);
    chainmail->set_short("A death black chainmail");
    chainmail->set_weight(5);
    move_object(chainmail, knight);
    blade = clone_object("players/kantele/black_demon_blade");
    move_object(blade, knight);
    command("wield blade", knight);
  }
}

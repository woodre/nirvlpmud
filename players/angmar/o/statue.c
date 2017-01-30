inherit "obj/treasure";

void
reset(status arg) {
  if (arg)
    return;
  set_name("statue");
  set_alias("stone statue");
  set_short("A stone statue");
  set_long("A stone statue of an elf.  It is very well made, it\n"+
           "looks almost alive...\n");
  set_weight(200);
}
  
status
get() {
  return 0;
}

void
init() {
  treasure::init();
  add_action("revive", "revive");
}

status
revive() {
  object elfwarrior, weap;

  tell_room(environment(this_object()), "The statue begins to glow!\n");
  tell_room(environment(this_object()),
    "The statue has suddenly transformed into an elfwarrior!\n");

  elfwarrior = clone_object("obj/monster");
  elfwarrior->set_name("elfwarrior");
  elfwarrior->set_level(18);
  elfwarrior->set_hp(350 + random(100));
  elfwarrior->set_wc(26);
  elfwarrior->set_ac(15);
  elfwarrior->set_short("An elfwarrior");
  elfwarrior->set_alias("warrior");
  elfwarrior->set_al(100);
  elfwarrior->set_chance(25);
  elfwarrior->set_spell_dam(15);
  elfwarrior->set_spell_mess1("The Elfwarrior throws his mace!\n");
  elfwarrior->set_spell_mess2("The Elfwarrior throws his mace at you!\n");
  elfwarrior->set_long(
"He looks very confused. He probably wonders where\n"+
"the wizard he just fought went\n");
  weap = clone_object("obj/weapon");
  weap->set_name("mace");
  weap->set_short("A heavy mace");
  weap->set_long("It has fresh bloodstains on it.\n");
  weap->set_class(15);
  weap->set_value(1000);
  weap->set_weight(4);
  move_object(weap, elfwarrior);
  move_object(clone_object("players/angmar/o/mithril_ring"), elfwarrior);
  move_object(elfwarrior,environment(this_object()));
  elfwarrior->init_command("wield mace");
  destruct(this_object());
  return 1;
}

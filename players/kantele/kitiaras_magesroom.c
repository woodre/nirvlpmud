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
  set_short("In the mages room");
  set_long(
"In the mages room, this little room only contains a small bed.\n");
  dest_dir = ({
    "players/kantele/kitiaras_lab", "south"
  });
}

void
populate() {
  object mage, weap;
  if (!present("mage", this_object())) {
    mage = clone_object("obj/monster");
    mage->set_name("necromancer");
    mage->set_alias("mage");
    mage->set_level(19);
    mage->set_wc(30);
    mage->set_ac(14);
    mage->set_hp(450);
    mage->set_al(-300);
    mage->set_short("A black robed necromancer is here");
    mage->set_aggressive(1);
    mage->set_move_at_reset();
    mage->set_chance(25);
    mage->set_spell_mess1("The necromancer casts a fireball.");
    mage->set_spell_mess2("You are hit by a fire ball.");
    mage->set_spell_dam(30);
    weap = clone_object("obj/weapon");
    weap->set_name("sword");
    weap->set_short("A sword");
    weap->set_class(17);
    weap->set_value(4000);
    move_object(weap,mage);
    command("wield sword", mage);
    move_object(mage, this_object());
  }
}

#pragma strong_types

inherit "obj/monster";

void
reset(status arg) {
  ::reset(arg);
  if (!present("axe")) {
    object weapon;
    weapon = clone_object("obj/weapon");
    weapon->set_name("battleaxe");
    weapon->set_class(12);
    weapon->set_alias("axe");
    weapon->set_value(250);
    weapon->set_weight(3);
    move_object(weapon, this_object());
    command("wield axe", this_object());
  }
  if (!present("key")) {
    object key;
    key = clone_object("obj/treasure");
    key->set_id("key");
    key->set_alias("mansion key");
    key->set_short("A key");
    key->set_value(10);
    key->set_weight(1);
    move_object(key, this_object());
  }
  
  if (arg)
    return;
  set_name("manservant");
  set_short("Kanteles manservant is here");
  set_long(
"Kantele's manservant is here, he looks mean !\n");
  set_level(10);
  set_hp(200);
  set_wc(10);
  set_ac(10);
  set_al(100);
}

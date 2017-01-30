/*
  wand_identification.c
*/

inherit "obj/treasure";

int wand_charges;
string str, who_or_what;

init() {
  add_action("use_wand", "use");
  add_action("use_wand", "wave");
}

use_wand(arg) {
  object obj;
  who_or_what = 0;
  if (!arg) return 0;
  if (query_verb()=="wave")
    sscanf(arg, "%s at %s", wand_name, who_or_what);
  else
    sscanf(arg, "%s on %s", wand_name, who_or_what);
  if (!id(wand_name)) return 0;
  if (!who_or_what) {
    if (query_verb()=="wave")
      write("Wave it at what?\n");
    else
      write("Use it on what?\n");
    return 1;
  }
  if (!present(who_or_what, this_player()) &&
      !present(who_or_what, environment(this_player()))) {
    write("But that's not here.\n");
    return 1;
  }
  obj = present(who_or_what);
  if (!obj) {
    write("That's not here.\n");
    return 1;
  }
  say(this_player()->query_name()+" "+query_verb()+"s a wand at "+
      who_or_what+".\n", this_player());
  if (obj->short())
    write("Name: "+obj->short()+"\n");
  if (obj->query_weapon_class())
    write("Weapon Class: "+obj->query_weapon_class()+"\n");
  if (obj->query_armor_class())
    write("Armor Class:  "+obj->query_armor_class()+"\n");
  if (obj->query_value())
    write("Value:        "+obj->query_value()+"\n");
  if (obj->query_weight())
    write("Weight:       "+obj->query_weight()+"\n");
  if (obj->query_wand_charges())
    write("Charges:      "+obj->query_wand_charges()+"\n");
  return 1;
}

reset(arg) {
  set_short("A wand");
  set_long("It is a thin wand of birchwood.\n");
  set_value(500);
  set_weight(1);
  set_wand_charges(12);
}

query_save_flag() { return 1; }

set_wand_charges(c) { wand_charges=c; }
query_wand_charges() { return wand_charges; }

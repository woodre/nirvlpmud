/*
  mimic.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  if (arg) return 0;
  ::reset();

  set_name("chest");
  set_level(9);
  set_alias("box");
  set_al(0);
  set_short("A chest");
  set_wc(16);
  set_ac(16);
  set_aggressive(0);
  set_alt_name("mimic");
  obj=clone_object("obj/money");
  obj->set_money(500);
  move_object(obj, this_object());
  obj=clone_object("players/nooneelse/obj/icon");
  move_object(obj, this_object());
}

init() {
  ::init();

  add_action("examine_mimic", "look");
  add_action("examine_mimic", "examine");
  add_action("mimic_react",   "take");
  add_action("mimic_react",   "get");
  add_action("mimic_react",   "open");
  add_action("mimic_react",   "unlock");
}

examine_mimic(str) {
  if (!str) return 0;
  if (query_verb()=="look" &&
      str=="at chest" || str=="at box" || str=="at mimic") str="chest";
  if (str != "chest") return 0;
  write("A sturdy looking, ironbound chest with a heavy brass lock.\n");
  return 1;
}

mimic_react(str) {
  object mimic_obj;
  string str2;
  if (!str) return 0;
  sscanf(str, "at %s", str2);
  if (str != "mimic" &&
      str != "chest" &&
      str != "box" &&
      str2 != "mimic" &&
      str2 != "chest" &&
      str2 != "box")
    return;
  write("As you examine the object, you realize that it is not a box,\n"+
        "but some kind of monster!\n");
  attack_object(this_player());
  return 1;
}

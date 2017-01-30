/* Murdock's Straight Jacket from Hell */

inherit "obj/armor.c";

string name;
object pl;

init() {
   ::init();
  name = call_other(this_player(),"query_name");
  add_action("duh","drop");
  add_action("duh","sell all");
  add_action("duh","sell");
  add_action("duh","drop all");
  add_action("duh","wield");
  add_action("dug","get");
  add_action("duh","get all");
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("jacket");
  set_alias("straight jacket");
  set_weight(3);
  set_ac(21);
  set_type("armor");
  set_value(100);
  set_short("A Straight Jacket");
}

duh() {
  write("Your wearing a straight jacket. How can you do that?\n");
  say(name+" just wriggled in the straight jacket.\n");
  return 1;
}


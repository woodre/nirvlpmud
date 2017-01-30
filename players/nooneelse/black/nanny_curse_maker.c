/*
 nanny_curse_maker.c
  This is a nanny curse maker.  To put a nanny curse in someone.
*/
inherit "obj/treasure";
string who;
init() {
  add_action("make_nanny", "nanny");
}

make_nanny(who){
  object target_obj, obj;
  string str;
  if (!who) {
    write("You must supply the name of the creature to nanny.\n");
    return 1;
  }
  target_obj=find_player(who);
  if (!target_obj) {
    write("I can't find a creature named "+who+"!\n");
    return 1;
  }
  obj=clone_object("players/nooneelse/black/cult_nanny_curse");
  move_object(obj, target_obj);
  obj->start_curse();
  write("Ok.\n");
  return 1;
}

reset(arg) {
  if (arg) return;
  set_short("A nanny curse maker. (type 'nanny <who>')");
  set_long("A nanny curse maker. (type 'nanny <who>').\n");
  set_value(0);
  set_weight(1);
}

id(str) { return str=="nanny curse maker"; }

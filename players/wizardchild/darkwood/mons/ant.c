/* ant.c: newbie monster */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  if(arg) 
    return ;
  ::reset(arg);
  set_name("ant");
  set_alias("worker ant");
  set_short("A worker ant");
  set_long("Although very large in appearance, this ant is of the smaller type: the\n"
          +"worker type. He doesn't appear to be very strong, despite his size.\n");
  load_chat("The ant hurries.\n");
  set_chat_chance(5);
  set_level(6+random(6));
  set_hp(80+random(41));
  set_wc(8);
  set_ac(8);
  set_al(120);
  move_object(random_item(), this_object());
}
id(str) { return str == "ant" || str == "worker ant"; }
random_item() {
  object ob;
  switch(random(3)) {
  case 0:
    ob = clone_object("obj/money");
    ob->set_money(135+random(30));
    break;
  case 1:
    ob = clone_object(ROOT_DIR+"obj/eggs");
    break;
  default:
    if(random(8) < 3)
      ob = clone_object(ROOT_DIR+"obj/antfood");
    else {
      ob = clone_object("obj/money");
      ob->set_money(10);
    }
    break;
  }
  return ob;
}

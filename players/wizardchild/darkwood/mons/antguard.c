/* antguard.c: guard of ant eggs/food */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  if(arg) 
    return ;
  ::reset(arg);
  set_name("ant");
  set_alias("guard ant");
  set_short("A guard ant");
  set_long("This ant appears to be stronger than the others, and serves the guarding\n"
          +"guarding role in the ants' society. He appears to be a formidable opponent,\n"
          +"standing between you and the property of his anthill.\n");
  load_chat("The ant stands his ground.\n");
  set_level(11);
  set_hp(115);
  set_wc(15);
  set_ac(9);
  set_al(80);
  move_object(random_item(), this_object());
}
id(str) { return str == "ant" || str == "guard ant"; }
random_item() {
  object ob;
  switch(random(3)) {
  case 0:
    ob = clone_object("obj/money");
    ob->set_money(220+random(30));
    break;
  case 1:
    ob = clone_object(ROOT_DIR+"obj/eggs");
    break;
  default:
    if(random(8) < 2)
      ob = clone_object(ROOT_DIR+"obj/antfood");
    else {
      ob = clone_object("obj/money");
      ob->set_money(15);
    }
    break;
  }
  return ob;
}

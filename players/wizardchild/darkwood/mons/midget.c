/* midget.c: a serious asshole */
#define ROOT_DIR "players/wizardchild/darkwood/"
#define TR(s) tell_room(environment(this_object()), s)
inherit "obj/monster";
reset(arg) {
  object cash;
  if(arg)
    return ;
  ::reset(arg);
  set_name("midget");
  set_alias("old midget");
  set_short("An old looking midget");
  set_long("Despite his aged appearance, he still manages to lift his shotgun and point it\n"
          +"at you. Although you could probably defeat him in a fair match, he is obviously\n"
          +"not interested in pride or honor - just in protecting his home.\n");
  set_spell_mess1("The midget wildly pulls the trigger.");
  set_spell_mess2("The midget wildly pulls the trigger.");
  set_spell_dam(65);
  set_chance(25);
  set_level(16);
  set_hp(100+random(21));
  set_wc(14);
  set_ac(4);
  set_al(120);
  move_object(clone_object(ROOT_DIR+"obj/shotgun"), this_object());
  cash = clone_object("obj/money");
  cash->set_money(2400+random(1100));
  move_object(cash, this_object());
}
id(str) { return str == "midget" || str == "old midget"; }
init() {
  int i, last;
  last = 4;
  i = 9;
  write("The midget looks for his shotgun.\n");
  while((i = remove_call_out("msg")) != -1)
    last = i;
  call_out("msg", last);
  while((i = remove_call_out("clear_room")) != -1)
    last = i;
  call_out("clear_room", last);
  ::init();
}
static msg() {
  TR("The midget finds his shotgun, and raises it to your chest.\n");
}
static clear_room() {
  object ob;
  TR("The midget pulls the trigger.\n");
  TR("You feel a hole in your chest, and hear a portion of your lung hit the wall\n");
  TR("behind you.\n");
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if(living(ob) && !ob->query_ghost() && (ob->query_level() < 20 || !ob->is_player()) && ob != this_object()) {
      if(ob->query_name())
        TR(ob->query_name()+" is shot!\n");
      ob->hit_player(180+random(40));
      TR("The midget reloads the shotgun!\n");
    }
    ob = next_inventory(ob);
  }
  TR("The midget looks around for more ammo and a broom.\n");
  if(test_if_any_here()) {
    remove_call_out("msg");
    remove_call_out("clear_room");
    call_out("msg", 8);
    call_out("clear_room", 14);
  }
  return 1;
}

inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("librarian");
  set_race("human");
  set_short("Librarian");
  set_long("The Librarian of The Great Library.\n"+
            "A pretty young woman of noble upbringing.\n"+
            "She knows the history of the library\n"+
            "so if you wish to know, just 'ask'.\n");
  set_hp(1000);
  set_level(8);
  set_al(0);
  set_wc(18);
  set_ac(10);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(1);
  load_chat("The Librarian turns a page in her book.\n");
  load_chat("People pass by looking for information.\n");
  load_chat("People pass by looking for information.\n");
  load_chat("Someone quietly passes by...\n");
  call_out("check",3);
}

check() {
  if(this_object()->query_attack()) {
    tell_room(environment(this_object()),"\nThe Librarian gestures and her attacker "+
            "disappears!\n\n");
    move_object((this_object()->query_attack()),"/players/mythos/lroom/pun.c");
    call_out("check",3);
    return 1;}
  call_out("check",3);
return 1;}

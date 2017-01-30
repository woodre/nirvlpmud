/* pitthing2.c: another pitthing */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  object cash;
  if(arg)
    return ;
  ::reset(arg);
  set_name("thing");
  set_alias("pit thing");
  set_short("A large-ish pit dwelling thing");
  set_long("Upon seeing this \"thing\", you immediately notice that it is much larger\n"
          +"many of the others around it. Evidentally, this is a mature type of these\n"
          +"creatures, while the others were only jueveniles.\n");
  load_chat("The large thing pushes the others out of the way.\n");
  set_chat_chance(8);
/* Changed level from 20 to 14 until monster can be fixed by WC  -Snow */
  set_level(14);
  set_hp(420+random(60));
  set_wc(19+random(5));
  set_ac(18); /* boost strength due to size */
  set_al(-400);
  move_object(clone_object(ROOT_DIR+"obj/chest"), this_object());
  cash = clone_object("obj/money");
  move_object(clone_object(ROOT_DIR+"obj/bones"), this_object());
  cash->set_money(1800+random(300));
  move_object(cash, this_object());
}
id(str) { return str == "thing" || str == "pit thing" || str == "large pit thing"; }

/* pitthing.c: thing in the pit */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  object cash;
  if(arg)
    return ;
  ::reset(arg);
  set_name("thing");
  set_alias("pit thing");
  set_short("A pit dwelling thing");
  set_long("Whatever this monster is, it appears to be a resident of this cave. Even after\n"
          +"careful examination, you can't tell what it is derived from. One thing you\n"
          +"can be sure of, however, is that it is bigger than you, and hungry.\n");
  load_chat("The thing circles around you, eyeing your chubby waist.\n");
  set_chat_chance(12);
/* Changed level from 18 to 14 until monster can be fixed by WC  -Snow */
  set_level(14);
  set_hp(360+random(60));
  set_wc(21);
  set_ac(13);
  set_al(-300-random(40));
  move_object(clone_object(ROOT_DIR+"obj/chest"), this_object());
  cash = clone_object("obj/money");
  cash->set_money(1300+random(300));
  move_object(cash, this_object());
}
id(str) { return str == "thing" || str == "pit thing" || str == "pit dwelling thing"; }

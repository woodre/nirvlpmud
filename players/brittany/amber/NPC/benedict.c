#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("benedict");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Benedict");
set_long("A tall hard-faced man, thin of body and face.  He is wearing\n"+
"the colors orange, yellow, and brown.  He has a long strong\n"+
"jaw and hazel eyes and brown straight hair.  He seldom laughs.\n");
set_gender("male");

set_level(11);
   set_hp(165);
   set_wc(15);
   set_ac(9);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Benedict says:  Murderer, I will kill you.\n");
load_chat("Benedict looks in your direction.\n");
load_chat("Benedict pierces you with his cold eyes.\n");
  
   gold = clone_object("obj/money");
gold->set_money(500);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince curses you, then dies.\n");
   return 0; }



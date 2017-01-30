#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("bleys");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Bleys");
set_long("A fiery bearded, flame-crowned man, his eyes were dark and\n"+
"devislish looking, his chin is slight covered with a beard.\n"+
"He is dressed all in red and orange, mainly of silk stuff.\n"+
"He wears two rings on his right hand and one on his left.  A\n"+
"sword hangs on a belt at his side.\n");
set_gender("male");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Bleys says:  We'll see how you fair against a prince.\n");
load_chat("Bleys says:\n");
load_chat("Bleys says:\n");
  
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince curses you, then dies.\n");
   return 0; }
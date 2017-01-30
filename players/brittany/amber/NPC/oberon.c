#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("oberon");
set_alias("man");
set_alt_name("lord");
set_race("human");
set_short("Lord Oberon");
set_long("Oberon, Lord of Amber stands before you in his\n"+
"green and gold.  High, wide, and thick, his beard\n"+
"black and filled with silver, his hair the same.\n"+
"Green rings in gold settings and a blade of golden\n"+
"color hangs at his side on his emerald belt.\n");

set_level(15);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(15);
set_heal(amt,rate);
set_aggressive(0);
set_dead_ob(this_object());

 set_chat_chance(5);
load_chat("Oberon exclaims.\n"+
"\n");
load_chat("Oberon says:\n"+
"\n");
load_chat("Oberon says:\n");
load_chat("Oberon says:\n"+
"\n");
  
   gold = clone_object("obj/money");
gold->set_money(550);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The lord curses you, then dies.\n");
   return 0; }
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("demon1");
set_alias("childling");
set_alt_name("demonkind");
set_race("creature");
set_short("A little Dream Demon");
set_long("Smaller then the older demon, but just as barbaric.\n"+
"For one to attempt to capture, tame a little demon\n"+
"is beyond the bounds of reason.  Do not trust this\n"+
"creature.\n");   

set_level(5);
   set_hp(75);
   set_wc(9);
   set_ac(5);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Childling says:  You can trust me, I am a small child.\n");
load_chat("Childling says:  I am hungry.\n");
  
   gold = clone_object("obj/money");
gold->set_money(200);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/claw.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "Childing squeals at you, then dies.\n");
   return 0; }
#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("fetch");
set_alias("guardian");
set_alt_name("fetch guardian");
set_race("creature");
set_short("Fetch Guardian");
set_long(
  "Fetch are harbingers of death.  They exist on the fringes of the\n"+
  "Abyss.  This guardian of the portal is a haggard and deathly pale\n"+
  "imitation of the person gazing at it.  It's eyes are dull and life-\n"+
  "less and it reflexively breaks into an evil grin when its eyes\n"+
  "meet those of its intended victim.  The fetch's flesh is ice cold\n"+
  "to the touch and they neither breathe nor speak.\n");

set_level(20);
set_hp(500 + random(50));
  set_al(-300 + random(300));
  set_wc(33);
  set_ac(18);
  set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("You experience overwhelming fear.....\n");
set_a_chat_chance(10);
  load_a_chat("Your head pounds from the SCREAMING... yet it's silent..\n");

gold = clone_object("obj/money");
gold->set_money(4000 + random(1000));
move_object(gold,this_object());
}

monster_died() {
  tell_object(this_player(),
   "A distant voice in your head intones, 'into the darkness I whisper\n"+
   "beneath my feet all is made firm' if you're asked by the red one.\n");
  write_file("/players/eurale/Abyss/LOG/abyss",
  tp->query_real_name()+"     "+ctime(time())+"     fetch3\n");
return 0; }

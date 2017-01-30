#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("vraaak");
set_alias("lizard");
set_alt_name("lizard");
set_race("lizard");
set_short(""+BOLD+""+BLK+"Vraaak"+NORM+"");
set_long(
  "This creature looks like it stepped right out of a nightmare. \n"+
  "It is around six feet long, thin, and covered in thick black \n"+
  "scales. Its four legs with six inch long claws.  It looks at\n"+
  "you with small blood red eyes. \n" );

set_level(14);
set_hp(150+random(100));
set_al(-200);
set_wc(20);
set_ac(10);
set_heal(5,40);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The "+BOLD+""+BLK+"vraaak"+NORM+" flicks it's tongue in the air. \n");
  load_chat("The "+BOLD+""+BLK+"vraaak"+NORM+" hisses at you. \n" );
set_a_chat_chance(15);
  load_a_chat("The "+BOLD+""+BLK+"vraaak"+NORM+" lunges for your throat. \n");
  load_a_chat("The "+BOLD+""+BLK+"vraaak"+NORM+" claws at your midsection. \n");

set_chance(20);
set_spell_dam((18));

set_spell_mess1(
  "The "+BOLD+""+BLK+"vraaak"+NORM+" "+HIR+"RIPS"+NORM+" you open. \n");
set_spell_mess2(
  " The "+BOLD+""+BLK+"vraaak"+NORM+" "+HIB+"TEARS"+NORM+" off a chunk of flesh. \n");

}

monster_died() {
 object claws;
 claws = clone_object("/players/dusan/area1/weapons/vrkclws.c");
 move_object(claws,present("corpse",environment()));
  tell_room(environment(this_object()),
	" \n");
return 0; }

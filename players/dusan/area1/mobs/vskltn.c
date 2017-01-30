#include "/players/dusan/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("vraaak");
set_alias("lizard");
set_alt_name("skeleton");
set_race("skeleton");
set_short(""+BOLD+""+BLK+"Vraaak Skeleton"+NORM+"");
set_long(
  "This creature looks like it stepped right out of a nightmare. \n"+
  "It is a six foot long skeleton with six inch long claws, and  \n"+
  "where the skin still clings to the bone it is covered in thick\n"+
  "black scales.  It still seems to have the same ferocious hunger \n"+
  "that it did in life.\n");

set_level(15);
set_hp(150+random(100));
set_al(-200);
set_wc(20);
set_ac(12+random(5));
set_armor_params("magical",10,0,0);
set_armor_params("other|evil",0,20,0);
set_armor_params("other|good",0,-20,0);
set_heal(5,20);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(15);
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
 object corpse;  
 corpse = present("corpse", environment());
move_object(clone_object("/players/dusan/area1/items/pieces.c"),
       environment(this_object()));
move_object(clone_object("/players/dusan/area1/items/vhide.c"),
       environment(this_object())); 
 if(corpse)
  destruct(corpse);
return 1; }

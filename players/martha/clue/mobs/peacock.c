#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("peacock");
  set_alt_name("mrs");
  set_race("human");  
  set_short(BOLD+BLU+"Mrs. Peacock"+NORM);
  set_long(
    "  Mrs. Peacock is a woman in her late fifties.  She has light\n"+
"reddish brown hair that has been thrown up into a ponytail of sorts,\n"+
"making her look disheveled.  Mrs. Peacock has a long feather boa\n"+
"around her neck.  She is wearing granny glasses and the ugliest hat\n"+
"that has ever been made.  She is the wife of a Senator.  Mrs. Peacock\n"+
"is being blackmailed for slipping used 'greenbacks' under the toilet\n"+
"stall doors in the mens room.  In other words she was taking bribes on\n"+
"her husbands behalf.\n");

  add_money(3000);
  set_level(20);
  set_hp(500+random(100));
  set_al(900);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
    
  load_chat("Mrs. Peacock says 'When were you ever in that mens room!'\n");
  load_chat("Mrs. Peacock says 'But look what happened to the cook!'\n");
  load_chat("Mrs. Peacock says 'This is one of my favorite dishes!\n");
  load_a_chat("Mrs. Peacock wraps the boa around your neck and pulls hard!\n");
  load_a_chat("Mrs. Peacock stabs you with her knife!\n");
  
  add_spell("slice","Mrs. #MN#$Y$ S$N$G$ L$N$B$ I$N$Y$ C$N$G$ E$N$B$ S$N$ you open with her knife!\n",
  				    "Mrs. #MN#$Y$ S$N$G$ L$N$B$ I$N$Y$ C$N$G$ E$N$B$ S$N$ #CTN# open with her knife!\n",
  				    50,50);
   /*move_object(clone_object("/players/martha/clue/weps/knife.c"), this_object());
	init_command("wield knife");
	move_object(clone_object("/players/martha/clue/weps/hat3.c"), this_object());
	init_command("wear hat");
	move_object(clone_object("/players/martha/clue/weps/boa.c"), this_object());
	init_command("wear boa"); */
}

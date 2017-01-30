#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("plum");
  set_alt_name("professor");
  set_alias("prof");
  set_race("human");  
  set_short(BOLD+MAG+"Professor Plum"+NORM);
  set_long(
    "  Professor Plum works for W.H.O. a part of U.N.O. in Washington\n"+
"D.C.  He used to be a psychiatrist, but now practices family planning.\n"+
"Professor Plum is an older man, perhaps in his fifties, although his\n"+
"hair is dark black, with not a touch of gray.  While he is not much to\n"+
"look at, he feels that he is a ladies man.  He wears eyeglasses and is\n"+
"often seen smoking a pipe.  You know the thing psychiatrists are not\n"+
"supposed to do with their patients?  Well, Professor Plum did that and\n"+
"that is why he is being blackmailed.  He must pay the blackmailer or\n"+
"risk losing his government job.\n");

  add_money(2300);
  set_level(20);
  set_hp(500+random(100));
  set_al(900);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
    
  load_chat("Professor Plum says 'I admit it, I did her!'\n");
  load_chat("Professor Plum says 'But is the FBI in the habit of cleaning up after multiple murder?'\n");
  load_chat("Professor Plum stares at your ass while rubbing his crotch softly.\n");
  load_a_chat("Professor Plum lights his pipe and blows smoke in your face!\n");
  load_a_chat("Professor Plum tosses the candlestick from hand to hand.\n");
  
  add_spell("strike","Professor #MN# $HC$S T R I K E S$N$ you on the back of the head with his candlestick!\n",
            		 "Professor #MN# $HC$S T R I K E S$N$ #CTN# on the back of the head with his candlestick!\n",
            		 50,50);
   /*move_object(clone_object("/players/martha/clue/weps/cstick.c"), this_object());
	init_command("wield candlestick");
	move_object(clone_object("/players/martha/clue/weps/eyeglasses.c"), this_object());
	init_command("wear eyeglasses");
	move_object(clone_object("/players/martha/clue/weps/smokingpipe.c"), this_object()); */
}

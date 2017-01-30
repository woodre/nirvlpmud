#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("mustard");
  set_alt_name("colonel");
  set_race("human");
  set_short(BOLD+YEL+"Colonel Mustard"+NORM);
  set_long(
    "  Here stands a man who appears to be in his late 40's.  His skin is tanned,\n"+
"though due to excessive tanning, his face is wrinkled, making him look older\n"+
"than he actually is.  His hair is a darker shade of blond and is combed over\n"+
"the top of his head to make it seem as though he has more hair then he does.\n"+
"A thick, bushy mustache sits on top of his upper lip.  Colonel Mustard is a\n"+
"stockier man, yet one can tell he was attractive in his younger years when he\n"+
"was a pilot in the war.  Colonel Mustard is being blackmailed because he sold\n"+
"essential radio parts on the black market during the war.  He is also a\n"+
"frequent visitor of a certain house of ill repute in Washington D.C.\n");
  
  add_money(2000);
  set_level(20);
  set_hp(500+random(100));
  set_al(-159);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
    
  load_chat("Colonel Mustard says 'I used to be a pilot in the war!'\n");
  load_chat("Colonel Mustard says 'You have photos of me doing what!?!?!'\n");
  load_chat("Colonel Mustard says 'Are you trying to make me look stupid in front of the other guests?'\n");
  load_a_chat("Colonel Mustard frowns and says 'I don't know how much more of this I can take!'\n");
  load_a_chat("Colonel Mustard shouts 'This is war, casualties are inevitable!'\n");
  
  add_spell("bonk","Colonel #MN#$R$ B$N$B$ O$N$G$ N$N$Y$ K$N$R$ S$N$ you on the head with his wrench!\n",
  				   "Colonel #MN#$R$ B$N$B$ O$N$G$ N$N$Y$ K$N$R$ S$N$ #CTN# on the head with his wrench!\n",
  				   50,50);
   /*move_object(clone_object("/players/martha/clue/weps/wrench.c"), this_object());
	init_command("wield wrench");
	move_object(clone_object("/players/martha/clue/heals/cognac.c"), this_object()); */
}

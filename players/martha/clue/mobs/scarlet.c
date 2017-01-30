#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("scarlet");
  set_alt_name("miss");
  set_race("human");  
  set_short(BOLD+RED+"Miss Scarlet"+NORM);
  set_long(
    "  Miss Scarlet is by far the most beautiful dinner guest here\n"+
"this evening.  She is wearing a skin tight, form fitting, red dress\n"+
"which shows off her bountiful cleavage.  Long red gloves cover her\n"+
"arm from her elbow to her fingertips.  She holds in one hand a lit\n"+
"cigarette and in the other a half empty glass of cognac.  She is\n"+
"being blackmailed because she owns a house and telephone line that\n"+
"offers men the services of a woman for a short time.  Miss Scarlet\n"+
"not only recognizes some of the invited guests here tonight, but\n"+
"she knows a few of the uninvited guests as well!\n");

  add_money(2000);
  set_level(20);
  set_hp(500+random(100));
  set_al(-900);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
    
  load_chat("Miss Scarlet says 'True! Who are you?  Perry Mason?'\n");
  load_chat("Miss Scarlet says 'Communism was just a red herring!'\n");
  load_chat("Miss Scarlet says 'Ha! Now I know why he was lying on his back all of the time!'\n");
  load_a_chat("Miss Scarlet grazes your head with the lead pipe!\n");
  load_a_chat("Miss Scarlet bends over and shows you her boobies, making you lose momentum!\n");
  
  add_spell("smash","Miss #MN# $HR$S M A S H E S$N$ your head in with the lead pipe!\n",
  				    "Miss #MN# $HR$S M A S H E S$N$ #CTN#'s head in with the lead pipe!\n",
  				    50,50);
   /*move_object(clone_object("/players/martha/clue/weps/pipe.c"), this_object());
	init_command("wield pipe");
	move_object(clone_object("/players/martha/clue/weps/gloves.c"), this_object());
	init_command("wear gloves");
	move_object(clone_object("/players/martha/clue/heals/glass.c"), this_object()); */
}

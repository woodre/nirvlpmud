#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("wadsworth");
  set_alt_name("butler");
  set_race("human");
  set_short(BOLD+HIK+"Wadsworth"+NORM);
  set_long(
    "  Wadsworth is the butler.  He is an attractive man, thought he has\n"+
"large, bugged out eyes.  His hair is short brown and he is wearing a very\n"+
"nice servants tuxedo.  There are many hidden pockets in his suit.  While\n"+
"Wadsworth is the butler, it appears he may know more about this evening\n"+
"than he is letting on.  Wadsworth is the one who called this meeting, but\n"+
"he has a bigger secret to tell.  He is not only the butler, but the\n"+
"blackmailer as well!\n");

  add_money(2000+random(1300));
  set_level(20);
  set_hp(500+random(100));
  set_al(-900);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
    
  load_chat("Wadsworth says 'Communism is just a red herring!'\n");
  load_chat("Wadsworth says 'I'm the butler, I buttle.'\n");
  load_chat("Wadsworth shouts 'I'm not shouting, I'm not shouting!'\n");
  load_a_chat("Wadsworth points his gun at you and makes you sing 'For he's a jolly good fellow'\n");
  load_a_chat("Wadsworth flashes the proof he has to blackmail you with!'\n");
  
  add_spell("fire","#MN# aims his gun at you and $HR$F I R E S$N$ off a shot!\n",
  				   "#MN# aims his gun at #CTN# and $HR$F I R E S$N$ off a shot!\n",
  				   50,50);
   /*move_object(clone_object("/players/martha/clue/weps/gun.c"), this_object());
	init_command("wield gun");
	move_object(clone_object("/players/martha/clue/weps/key.c"), this_object());
	move_object(clone_object("/players/martha/clue/weps/envelope.c"), this_object()); */
}

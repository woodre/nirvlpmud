#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("green");
  set_alt_name("mr");
  set_race("human");
  set_short(BOLD+GRN+"Mr. Green"+NORM);
  set_long(
    "  Mr. Green is approximately 6 feet 4 inches tall and gangly.  His mousy\n"+
"brown hair is cut short and swept across his forehead.  He has oversized\n"+
"eyeglasses and is constantly pushing them up the bridge of his nose as\n"+
"they are too big for him.  While Mr. Green is very pale, he dresses well\n"+
"and looks like he has a flair for fashion.  Mr. Green is being blackmailed\n"+
"because he is an alleged homosexual.  While he finds no shame in this, he\n"+
"must keep it a secret or he will lose his job.\n");
  
  add_money(2400);
  set_level(20);
  set_hp(500+random(100));
  set_al(900);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("Mr. Green says 'I find no shame in being a homosexual.'\n");
  load_chat("Mr. Green says 'But I didn't do it!!!!!!!!'\n");
  load_chat("Mr. Green says 'That call from J. Edgar Hoover was for me.'\n");
  load_a_chat("Mr. Green points his revolver at you and screams 'Put your hands up where I can see them motherfucker!'\n");
  load_a_chat("Mr. Green yells 'YOU BASTARD!!!'\n");
   
  add_spell("whip","Mr. #MN# pistol $HG$W H I P S$N$ you with his revolver!\n",
  				   "#CTN# crumples in pain as $R$B L O O D$N$ pours from #TP# wound!\n",
  				   50,50);
   /*move_object(clone_object("/players/martha/clue/weps/revolver.c"), this_object());
	init_command("wield revolver");
	move_object(clone_object("/players/martha/clue/weps/id.c"), this_object());
	init_command("wear id");
	move_object(clone_object("/players/martha/clue/weps/blazer.c"), this_object());
	init_command("wear blazer");
	 */
}

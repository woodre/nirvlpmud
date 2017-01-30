#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("yvette");
  set_alt_name("maid");
  set_race("human");
  set_short(HIB+"Yvette"+NORM);
  set_long(
    "  Yvette is dressed in a skimpy french maid outfit, which makes one\n"+
"believe that she actually is a maid.  Yvette has platinum blonde hair\n"+
"that is swept up in a french twist.  Resting on the top of her head is\n"+
"a tiny white servants hat.  She is wearing jet black fishnet stockings\n"+
"and high heels, which show off her long, delicious legs.  Her ample\n"+
"bosom is pushed up and out by the tight uniform and really leaves little\n"+
"to the imagination.  Yvette is not being blackmailed, however, she has\n"+
"been recognized by more than one of the guests this evening.  Yvette has\n"+
"given information, as well as her body, to a certain unnamed host.\n");
  
  add_money(2976);
  set_level(20);
  set_hp(500);
  set_al(-75);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("Yvette says 'Oui, Oui Madame!'\n");
  load_chat("Yvette lifts her ample bosom up and shifts them around.\n");
  load_a_chat("Yvette begins to untie her uniform, making it difficult for you to remain focused!\n");
  load_a_chat("Yvette screams 'BUT I AM A LAY-DEE!!'\n");
   
  add_spell("impale","#MN# $HM$I M P A L E S$N$ you with a 6 inch stiletto heal!\n",
  					 "#CTN# doubles over in pain as $R$B L O O D$N$ pours from a hole in #TP# stomach!\n",
  					 50,50);
   /*move_object(clone_object("/players/martha/clue/weps/fmaid.c"), this_object());
	init_command("wear uniform");
	move_object(clone_object("/players/martha/clue/weps/heels.c"), this_object());
	init_command("wear heels");
	move_object(clone_object("/players/martha/clue/weps/fnet.c"), this_object());
	init_command("wear stockings");
	 */
}

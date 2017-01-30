#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("chief");
  set_alt_name("man");
  set_race("human");
  set_short(HIG+"The Chief"+NORM);
  set_long(
    "  An older man with a full white beard and longish, shaggy, white\n"+
"hair, The Chief appears to be one of those religious nuts who goes\n"+
"door to door trying to recruit new members.  How odd though, that he\n"+
"might show up so late at night, especially during a thunderstorm.\n"+
"He holds brochures in one hand and the other hand is up under his long\n"+
"trenchcoat.  What might he be reaching for?\n");
  
  add_money(3450);
  set_level(20);
  set_hp(500);
  set_al(500);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("The Chief says 'The Kingdom of Heaven is at hand!'\n");
  load_a_chat("The Chief screams 'You better pray for your soul mother fucker!'\n");
  load_a_chat("The Chief slices your face open with a brochure!\n");
   
  add_spell("slice","The #MN#$HY$ S L I C E S$N$ your face open with a brochure!\n",
  					"You feel sick as $R$ B L O O D$N$ pours from the paper cut on #CTN#'s face!\n",
  					50,50);
  /*move_object(clone_object("/players/martha/clue/weps/trenchcoat.c"), this_object());
    init_command("wear trenchcoat");
	move_object(clone_object("/players/martha/clue/weps/brochure.c"), this_object());
	 */
}

#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("cop");
  set_race("human");
  set_short(HIM+"The Cop"+NORM);
  set_long(
    "  The Cop is off duty.  He just stopped by to use the telephone, but\n"+
"he seemed to recognize someone here.  The Cop is an older, dark skinned\n"+
"man with very little hair on his head.  Thankfully he wears a standard\n"+
"police issued hat that covers his head so no one can tell he is bald.\n"+
"His belly protrudes from his tight fitting, blue uniform shirt and hangs\n"+
"over the dark blue pants he must wear.  The Cop is not being blackmailed\n"+
"and his presence here on this particular evening is not coincidence either.\n"+
"The Cop is one of the informants who gives information to a certain unnamed\n"+
"host.  Who here does this man have secrets about??\n");
  
  add_money(3400);
  set_level(20);
  set_hp(500);
  set_al(0);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("The Cop says 'No, I am off duty right now.'\n");
  load_chat("The Cop says 'Something very strange is going on here'\n");
  load_a_chat("The Cop swings the cuffs around and looks menacing!\n");
  load_a_chat("The Cop jabs you with his nightstick!\n");
   
  add_spell("bash","The #MN# $HW$ B$N$R$ A$N$HW$ S$N$R$ H$N$HW$ E$N$R$ S$N$ you with his nightstick!\n",
   				   "#CTN# falls to the floor from the $HG$FORCE$N$ of the #CMN#'s blow!\n",
   				   50,50);
  /*move_object(clone_object("/players/martha/clue/weps/cuffs.c"), this_object());
	move_object(clone_object("/players/martha/clue/weps/hat.c"), this_object());
	init_command("wear hat");
	move_object(clone_object("/players/martha/clue/weps/stick.c"), this_object());
	init_command("wield stick");
	 */
}

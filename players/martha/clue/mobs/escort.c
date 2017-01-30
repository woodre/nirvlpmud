#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("escort");
  set_alt_name("whore");
  set_race("whore");
  set_short(MAG+"The Escort"+NORM);
  set_long(
    "  The Escort is a beautiful, younger woman with a creamy,\n"+
"white complexion.  Long, red curls of hair trail down her back,\n"+
"covering her slender waist.  The Escort wears only a sexy black\n"+
"teddy, fishnet stockings held up with garter belts and stiletto\n"+
"heels.  She is waiting for one of her clients to come pay her a\n"+
"visit.  She saw her employer and one of her 'johns' eating dinner\n"+
"earlier in the evening and was told to wait in this room for her\n"+
"man to come see her.  She runs a polished hand over the tops of\n"+
"her silky breasts, which are spilling out of her teddy.  One only\n"+
"needs good eyes to see her nakedness, there is nothing left to the\n"+
"imagination.  The Escort is not being blackmailed, but she has done\n"+
"some things to the people here who are, many dirty, naughty things!\n");
  
  add_money(3750);
  set_level(20);
  set_hp(500);
  set_al(0);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("The Escort offers to show you all of the interesting things she can do with her tongue!\n");
  load_chat("The Escort says 'I hope this box of condoms is enough!'\n");
  load_chat("The Escort says 'Don't I look sexy in my little black teddy?'\n");
  load_a_chat("The Escort spreads her legs open, causing you to lose all focus and stare at her fuzzy box!\n");
  load_a_chat("The Escort throws a dirty condom at you!\n");
   
  add_spell("love","The #MN# thrusts your head between her luscious $HR$L O V E$N$ pillows!\n",
  				   "You feel a strange $HR$stirring$N$ in your pants!\n",
  				   50,50);
  /*move_object(clone_object("/players/martha/clue/weps/condoms.c"), this_object());
	move_object(clone_object("/players/martha/clue/weps/teddy.c"), this_object());
	init_command("wear teddy");
	 */
}

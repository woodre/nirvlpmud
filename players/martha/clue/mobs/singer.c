#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("telegram");
  set_alt_name("singer");
  set_alias("girl");
  set_race("human");
  set_short(HIY+"The Singing Telegram"+NORM);
  set_long(
    "  Young, beautiful, and petite, this girl goes door to door\n"+
"singing telegrams when she is hired to do so.  She is wearing a\n"+
"red uniform, with gold detailing, gold buttons and a red hat.\n"+
"On her feet are black tap shoes and she is skilled at tapping.\n"+
"The hat on her head covers her short, curly brown hair and\n"+
"allows only a few curls to peep out from underneath it.  In her\n"+
"hands is a telegram.  This girl is not being blackmailed, however\n"+
"the secret she holds within could ruin a certain guests career.\n");
  
  add_money(3000);
  set_level(20);
  set_hp(500);
  set_al(500);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("The Singing Telegram sings 'I...am...your...singing telegram!'\n");
  load_chat("The Singing Telegram sings 'Dadah Dadah Da...DAH!'\n");
  load_a_chat("The Singing Telegram screams 'Haven't I been through enough already you bastard!?!'\n");
  load_a_chat("The Singing Telegram tap dances all over your face!\n");
   
  add_spell("kick","The Singing Telegram $HB$K I C K S$N$ your face in with her tap shoes!\n",
  				   "The Singing Telegram $HB$K I C K S$N$ #CTN#'s face in with her tap shoes!\n",
  				   50,50);
  /*move_object(clone_object("/players/martha/clue/weps/uniform.c"), this_object());
    init_command("wear uniform");
	move_object(clone_object("/players/martha/clue/weps/shoes2.c"), this_object());
	init_command("wear shoes");
	move_object(clone_object("/players/martha/clue/weps/telegram.c"), this_object());
	 */
}

#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("boddy");
  set_alt_name("host");
  set_race("human");
  set_short(HIR+"Mr. Boddy"+NORM);
  set_long(
    "  Mr. Boddy is a greasy looking low-life.  He wears black pants, a\n"+
"black shirt, a black leather jacket and black shoes.  He has stubble on\n"+
"his face, which he intentionally keeps that length as he thinks it makes\n"+
"him look sexier.  Mr. Boddy is allegedly blackmailing all of the other\n"+
"guests and everyone believes he is the host of the evening.  Mr. Boddy\n"+
"thinks they are gathered tonight to discuss a certain financial obligation\n"+
"he has imposed upon them all.\n");
  
  add_money(2850);
  set_level(20);
  set_hp(500);
  set_al(-640);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("Mr. Boddy says 'No thanks Yvette, I just ate.'\n");
  load_chat("Mr. Boddy says 'Oh, I knew I was meeting you tonight.'\n");
  load_a_chat("Mr. Boddy opens up his satchel and begins throwing various objects at you!\n");
  load_a_chat("Mr. Boddy laughs as he burns you with a cigarette!\n");
   
  add_spell("burn","Mr. #MN#$R$ B$N$Y$ U$N$$R$ R$N$Y$ N$N$R$ S$N$ you with a lit cigarette!\n",
                   "Mr. #MN#$R$ B$N$Y$ U$N$$R$ R$N$Y$ N$N$R$ S$N$ #CTN# with a lit cigarette!\n",
                   50,50);
  /*move_object(clone_object("/players/martha/clue/weps/satchel.c"), this_object());
	move_object(clone_object("/players/martha/clue/weps/shoes.c"), this_object());
	init_command("wear shoes");
	move_object(clone_object("/players/martha/clue/heals/cigs.c"), this_object());
	 */
}

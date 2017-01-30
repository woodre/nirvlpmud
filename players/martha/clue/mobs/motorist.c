#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("motorist");
  set_race("human");
  set_short(HIB+"The Motorist"+NORM);
  set_long(
    "  The Motorist is a rugged, unshaved man in his early forties.\n"+
"A dark brown fedora sits upon his head, crushing his light brown\n"+
"hair.  His eyes are a beautiful shade of blue.  This man was at one\n"+
"time very handsome, but now appears to be worn out.  He is wearing\n"+
"a brown suede jacket and a pair of tan work boots.  The Motorist is\n"+
"not being blackmailed, however he has informed on one of the guests\n"+
"here this evening.\n");
  
  add_money(2500);
  set_level(20);
  set_hp(500);
  set_al(500);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("The Motorist says 'My car broke down, may I use your telephone?\n");
  load_chat("The Motorist says 'There seems to be some kind of strange party going on here.\n");
  load_chat("The Motorist takes a swig of whiskey.\n");
  load_a_chat("The Motorist kicks you hard in the shin with his steel tipped boots!\n");
  load_a_chat("The Motorist spits whiskey in your face!\n");
   
  add_spell("hit","The #MN# throws his hat like a frisbee and $HY$H I T S$N$ you in the eye!\n",
     			  "The #MN# throws his hat like a frisbee and $HY$H I T S$N$ #CTN# in the eye!\n",
     			  50,50);
  /*move_object(clone_object("/players/martha/clue/weps/hat2.c"), this_object());
    init_command("wear hat");
	move_object(clone_object("/players/martha/clue/weps/jacket.c"), this_object());
	init_command("wear jacket");
	move_object(clone_object("/players/martha/clue/heals/whiskey.c"), this_object());
	 */
}

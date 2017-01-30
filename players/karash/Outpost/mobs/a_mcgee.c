
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: a_mcgee.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A mid-level mob in the Outpost introductory area used to enhance
 *			the initial theme of the id software group.   
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("American McGee");
  SetMultipleIds( ({ "american", "mcgee", "american mcgee" }) );
  set_race("human");
  set_short("American McGee");
  set_long("  American McGee joined the 'id' group in his mid-20s towards the end\n\
of Project Doom.  He and Sandy have worked very closely with the two\n\
Johns (Romero and Carmack) to further develop the slipgate.  McGee is\n\
a stylish, intelligent, clean-cut young man who seems pretty confident\n\
about himself, yet a little unsure about the current situation.\n");
  set_level(18);
  set_al(0);
  set_ac(20);
  set_wc(26);
  set_hp(350+(random(150)));
  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("McGee says, 'John has travelled very far to find that sword.  "+BBLK+HIW+"You should\n\
see it and watch the gleam in his eye when you compliment it."+NORM+"'\n");
    load_chat("McGee says, 'This whole mission is like Alice falling down the rabbit\n\
	hole, but much more macabre.'\n");
    load_chat("McGee says, 'They are calling this Mission: Quake, but they won't give\n\
	us details.'\n");
  /*set_a_chat_chance(0);
    load_a_chat("\n");
	load_a_chat("\n");
  */
  add_spell("bunk_bed",
    "#MN# attempts to turn over a $B$bunkbed$N$ on top of you.\n",
    "#MN# attempts to turn over a $B$bunkbed$N$ on top of #TN#.\n",
    20,"30-40","physical",0);

  add_money(random(1500)+2000);
  
  }
  
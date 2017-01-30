
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: s_petersen.c
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
   
  set_name("Sandy Petersen");
  SetMultipleIds( ({ "sandy", "petersen", "sandy petersen" }) );
  set_race("human");
  set_short("Sandy Petersen");
  set_long("  Sandy also joined the 'id' group during Project Doom.  He and McGee\n\
have worked very closely with the two Johns (Romero and Carmack) to\n\
further develop the slipgate.  Sandy is a middle-aged man, balding and\n\
robust, and it only takes a brief interaction with him to notice hints\n\
of his strategic mind.  Yet, he seems pretty easy-going and laid-back.\n");
  set_level(18);
  set_al(0);
  set_ac(20);
  set_wc(26);
  set_hp(350+(random(150)));
  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("Petersen says, 'John"+YEL+" really"+NORM+" loves that sword.  "+BBLK+HIW+"Just tell him how you feel\n\
about it and you'll see what I mean."+NORM+"'\n");
    load_chat("Petersen says, 'We were called here to advise, but they will not give\n\
	us details.'\n");
    load_chat("Petersen says, 'They sent the soldiers into the slipgate; something\n\
	about Operation Counterstrike to fight against Quake.'\n");
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
  

inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: a_carmack.c
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

reset(arg) 
{
  ::reset(arg);
  if(arg) return;
   
  set_name("Adrian Carmack");
  SetMultipleIds( ({ "adrian", "carmack", "adrian carmack" }) );
  set_race("human");
  set_short("Adrian Carmack");
  set_long("  Adrian may have been one of the original members of the 'id' think-tank\n\
group, but was more of a designer than a developer of ideas.  The group\n\
treated him as an outcast and eventually forced him from the group, but\n\
it appears something has brought them back together.  However, Adrian\n\
currently sits alone in the cafeteria drinking a Mountain Dew.  He\n\
peers through his glasses with tired eyes, his long hair looks unwashed,\n\
his goatee is untrimmed, and he looks like he could use a shower.\n");
  set_level(18);
  set_al(0);
  set_ac(20);
  set_wc(26);
  set_hp(350+(random(150)));
  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("Adrian says, 'I am an artist.'\n");
    load_chat("Adrian says, 'They forced me out of the 'id' and stuck me here in the kitchen.'\n");
    load_chat("Adrian says, 'I don't even know why I'm here.'\n");
  set_a_chat_chance(5);
    load_a_chat("Adrian screams: Leave me alone!  I AM AN ARTIST!\n");
	load_a_chat("Adrian yells: You should be gibbed!\n");

  add_spell("kitchen_knife",
    "#MN# ducks into the kitchen and comes up throwing a $HK$knife$N$.\n",
    "#MN# ducks into the kitchen and comes up throwing a $HK$knife$N$ at #TN#.\n",
    20,"15-25","physical",0);

  add_money(random(1500)+2000);
	
}
  
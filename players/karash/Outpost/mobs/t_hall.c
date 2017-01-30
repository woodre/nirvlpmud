
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: t_hall.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A mid-level mob in the Outpost introductory area used to enhance
 *			the initial theme of the id software group.  Mob has higher AC
 *			for its level due to counter between NPC and players.  
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg) 
{
  ::reset(arg);
  if(arg) return;
   
  set_name("Tom Hall");
  SetMultipleIds( ({ "tom", "hall", "tom hall" }) );
  set_race("human");
  set_short("Tom Hall");
  set_long("  Tom Hall was one of the original members of the 'id' think-tank group\n\
and is credited with the first plans for the slipgate prior to being\n\
forced out of the group by John Carmack due to differences of opinion.\n\
He appears to be in his early 30s and his trimmed beard and moustache\n\
matches his dark hair, which extends past his shoulders.  Despite this\n\
being some kind of military-type outpost, Tom is dressed pretty casual.\n\
His beige short-sleeved shirt is unbuttoned, revealing a black t-shirt\n\
tucked into his loose-fitting jeans.  He looks tired as he stands\n\
behind the counter.\n");
  set_level(18);
  set_al(0);
  set_ac(25);
  set_wc(26);
  set_hp(350+(random(150)));
  set_res(0);
  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("Tom says, 'The slipgate was my idea. I initially designed it for Project Doom.'\n");
    load_chat("Tom brags, 'John said he will take me to the Ion Storm.'\n");
    load_chat("Tom says, 'John and I have worked with the Commander many times.'\n");
  set_a_chat_chance(5);
    load_a_chat("Tom screams: John Romero's about to make you his BITCH!\n");
	load_a_chat("Tom yells: John! Come teach these losers a lesson!\n");
	load_a_chat("Tom screams: John Romero's about to make you his BITCH!\n");
  
  add_spell("bitch_slap",
    "#MN# stretches over the counter flailing a backhand in your direction.\n",
    "#MN# stretches over the counter flailing a backhand at #TN#.\n",
    80,"5-10","other|energy",0,"bitch_slapped" );

  add_money(random(1500)+2000);
  
}

/** First attempt at calling other functions from add_spell **/  
void bitch_slapped(object target, object room, int damage) 
{
  if(damage > 8)
    { 
    tell_room(environment(),"\n\n"+target->query_name()+" just got "+HIR+"BITCHSLAPPED"+NORM+"!\n\n"); 
    }
}
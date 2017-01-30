
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: guard.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A mid-level mob in the Outpost introductory area used to enhance
 *			the initial theme of the slipgate outpost complex.   
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("guard");
  SetMultipleIds( ({ "guard", "guard", "guard" }) );
  set_race("human");
  set_short("Guard");
  set_long("  The guards here seem like your typical grunts; emotionless soldiers\n\
touting military-grade gear and an assault shotgun.  They stand on\n\
either side of the door to the main building and motion you to enter.\n");
  set_level(22);
  set_al(0);
  set_ac(25);
  set_wc(40);
  set_hp(700+(random(150)));
  set_res(0);
  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(3);
    load_chat("Guard motions to the door and says, 'The commander is inside.'\n");
    load_chat("Guard says, 'I should be with the Operation Counterstrike team.'\n");
    load_chat("Guard says, 'The counterstrike team has not reported back yet.'\n");
  set_a_chat_chance(5);
    load_a_chat("Guard yells:  'I am not your enemy!'\n");
    load_a_chat("Guard tells you:  'You should direct this aggression to the slipgate!'\n");
    load_a_chat("Guard asks:  'Did you come through the slipgate?  Are you one of them?'\n");
  
  add_spell("shotgun_smash",
    "#MN# swings the butt of his $HK$shotgun$N$ at your head.\n",
    "#MN# swings the butt of his $HK$shotgun$N$ at #TN#.\n",
    50,"20-30","physical",0);

  add_money(random(3500)+3500);
  
  move_object(clone_object("/players/karash/Outpost/items/shotgun.c"), this_object());
  command("wield shotgun", this_object());
  
  }
  

inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: keen.c
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
   
  set_name("Commander Keen");
  SetMultipleIds( ({ "commander", "keen", "commander keen" }) );
  set_race("human");
  set_short("Commander Keen");
  set_long("  Commander?  This young man doesn't even look like he's out of his\n\
teens.  Red sneakers; blue jeans; a purple t-shirt with the words\n\
'Goodbye Galaxy' across the chest; and an old, scratched up Green Bay\n\
Packers helmet without a face guard sitting loosely on his head.  This\n\
must be a joke, right?  Yet, the others call him Commander and he\n\
talks of missions to Mars, Vortican VI, Gnosticus IV, Korath and the\n\
Fribbulus Xax.  Either everyone here is going mad or you stand before\n\
some super genius who must have gotten his start before he was 10.\n\
Well, this 'Commander' does exude confidence and simply nods his head\n\
towards the other rooms as if he doesn't want to be bothered.\n");
  set_level(25);
  set_al(0);
  set_ac(30);
  set_wc(50);
  set_hp(1250+(random(250)));
  set_gender("male");
 /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("Keen says, 'Welcome, I hope you are here to help with the mission.'\n");
    load_chat("Keen says, 'Romero may give you details of the mission if he's not too\n\
busy admiring his latest "+YEL+"treasure"+NORM+". "+BBLK+HIW+"You should tell him how you feel\n\
about his "+NORM+GRY+"sword"+NORM+HIW+"."+NORM+"'\n");
    load_chat("Keen says, 'Some "+BBLK+HIW+"well-placed compliments"+NORM+" will put John in a good mood.\n\
Just remember, his assistance is invaluable, so please don't stress him\n\
even more.'\n");
  set_a_chat_chance(15);
    load_a_chat("Keen shouts:  'You would be better served helping the cause, not\n\
interfering with it!'\n");
    load_a_chat("Keen asks:  'Wait! Are you a minion of Quake?'\n");
    load_a_chat("Keen yells:  'You shall face the same fate as Quake's desciples!'\n");
  
  set_multi_cast(1);
  
  add_spell("shotgun_smash",
    "#MN# swings the butt of his $HK$shotgun$N$ at your head.\n",
    "#MN# swings the butt of his $HK$shotgun$N$ at #TN#.\n",
    40,"40-60","physical",0);

  add_spell("double_shot",
    "#MN# double taps his $HK$shotgun$N$ in the direction of all attackers\n\
and quickly reloads.\n",
    "#MN# double taps his $HK$shotgun$N$ in the direction of all attackers\n\
and quickly reloads.\n",
    40,"40-60","physical",3);
	
  add_money(random(3500)+8000);
  
  move_object(clone_object("/players/karash/Outpost/items/pogo.c"), this_object());
  move_object(clone_object("/players/karash/Outpost/items/shotgun.c"), this_object());
  command("wield shotgun", this_object());
  move_object(clone_object("/players/karash/Outpost/items/tshirt.c"), this_object());
  move_object(clone_object("/players/karash/Outpost/items/gbhelmet.c"), this_object());
  
  }
  
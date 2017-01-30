/*****************************************************************************
 *      File:                   treluna2.c
 *      Function:               Treluna second form
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2010 Sparrow
 *                              All Rights Reserved.
 *      Source:                 12/20/10 (happy birthday me!)
 *      Notes:
 *      Change History:
 ****************************************************************************/
#include "/sys/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    /* sm - spell marker. Make it easier for players to see when important
       battle messages come through.
    */
    string sm;
    sm = HIY+" ~ "+NORM;
    set_name("treluna");
    set_alias("mistress");
    set_short("Treluna "+HIR+"["+NORM+"Mistress of Insanity"+HIR+"] ["+NORM+"hag"+HIR+"]"+NORM);
    set_race( "demon");
    set_long("Treluna, the Mistress of Insanity as she is known in some circles, was the first of the\n"+
    		 "demons imprisoned by the Black Willow three centuries ago. Appearing in her second form,\n"+
    		 "the withered hag, the first facade has been wiped away. Few that have ever beared witness\n"+
    		 "to the power of the hag have survived to tell the tale. Eyes glowing with a sickly purple\n"+
    		 "hue, her crocked smile shows rows of razor sharp teeth. Her shriveled frame hides tremendous\n"+
    		 "power that seems locked inside waiting to be freed.\n");
    set_level(40);
    set_ac(40+random(20));
    set_wc(80+random(40));
    set_hp(1500+random(500));
    set_al(-100);
    set_aggressive(1);
    set_chat_chance(0);
    set_a_chat_chance(0);
    set_dead_ob(this_object());
    add_spell("fireball",
	  sm+"A blast of "+HIR+"flame"+NORM+" errupts from Treluna's hands blasting you back!\n\n",
	  sm+"#CTN# is blasted by a huge "+HIR+"fireball"+NORM+"!\n\n",
	  20,({"10d10","5d10"}),({"other|fire",0}),1);
	add_spell("feeble",
	  sm+"A "+HIB+"cold"+NORM+" ray blasts you "+HIC+"freezing"+NORM+" you to the core!\n"+sm+"Treluna looks revitalized!\n\n",
	  sm+"Treluna unleases a ray of cold on #CTM#.\n"+sm+"Treluna looks revitalized!\n\n",
      25,({"25d3","15d4"}),({"other|cold","other|evil"}),0,"trelunaDrain");
    add_spell("lightning",
	  sm+"There is a bright flash of light as you are consumed by a bolt of\n"+
	  sm+HIY+"      __    ____   ___   _   _  ____  _  _  ____  _  _  ___   \n"+
	  sm+HIY+"     (  )  (_  _) / __) ( )_( )(_  _)( \\( )(_  _)( \\( )/ __)  \n"+
	  sm+HIY+"      )(__  _)(_ ( (_-.  ) _ (   )(   )  (  _)(_  )  (( (_-.  \n"+
	  sm+HIY+"     (____)(____) \\___/ (_) (_) (__) (_)\\_)(____)(_)\\_)\\___/  \n"+sm+"\n"+
	  sm+NORM+"  A crack of loud thunder follows, knocking you off your feet!.\n\n",
	  sm+HIY+"There is a bright flash of light, #CTN# is struck by a bolt of lightning!\n"+
	  sm+NORM+"A crack of loud thunder follows, knocking #CTN# off #TP# feet!.\n\n",
	  30,({"25d2","5d5"}),({"other|electric","other|sonic"}),1);
	add_spell("shadowmissile",
	  HIK+"#MN# screams as multiple balls of dark energy fly from her fingers!\n"+
	  "Your body is rocked by a wave of "+HIM+"D"+HIK+"ark "+HIM+"M"+HIK+"issiles!\n\n"+NORM,
	  HIK+"#MN# screams as multiple balls of dark energy fly from her fingers!\n"+
	  "#CTN#'s body is rocked by a wave of "+HIM+"D"+HIK+"ark "+HIM+"M"+HIK+"issiles!\n\n"+NORM,
	  20,({20,20,20,15,15,15}),({"other|dark","other|dark","other|dark","magical","magical","magical"}),0);
    set_multi_cast(1);
    set_weapon_params("other|evil",30,0);
  }

}

monster_died() {
  object x;
  object y;
  tell_room(environment(this_object()),
    "Treluna's beauty drains from her body, shriveling into the form of an old hag!\n");
  x = present("corpse",environment(this_object()));
  destruct(x);
  y = clone_object("/players/sparrow/areas/darkGauntlet/npc/treluna3.c");
  move_object(y,environment(this_object()));
  if(attacker_ob && y){
      y->attacked_by(attacker_ob);
  }
  return 0;
}

void trelunaPeace(object att) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
    att->stop_fight();
    att->stop_fight();
    att->stop_hunter();
  }

  void trelunaDrain(object att) {
  	this_object()->heal_self(10*(random(10)+1));
  }
/*****************************************************************************
 *      File:                   treluna3.c
 *      Function:               Treluna final form
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
    set_alias("demon");
    set_short(HIW+"Treluna "+HIM+"["+HIW+"D"+HIC+"emon of "+HIW+"I"+HIC+"nsanity"+HIM+"]"+NORM);
    set_race( "demon");
    set_long(HIW+"Treluna has finally exposed her true form, a demon of the ancient world. A gangly looking\n"+
                 "creature, her long spindly arms reach almost to the ground. Wisps of dark mist escape rows\n"+
                 "of jagged yellow fangs. Her dark green skin oozes with venom glistening like wet rubber.\n"+
                 "Long claws drip with with fresh blood and flesh stinking like a rotting corpse.\n"+NORM);
    set_level(40);
    set_ac(20+random(20));
    set_wc(100);
    set_hp(1000+random(500));
    set_al(-1000);
    set_aggressive(1);
    set_chat_chance(0);
    set_a_chat_chance(0);
    set_dead_ob(this_object());
    set_ac_bonus(75);
    add_spell("claws",
	  sm+"Treluna slashes at you with #TP# claws slashing you deeply!\n\n",
	  sm+"#CTN# is slashed open by Treluna's claws!\n\n",
	  75,({"5d10","5d10"}),({0,"other|evil"}),0);
	add_spell("bite",
	  sm+"Treluna jumps on you and begins biting your neck!\n\n",
	  sm+"Treluna jumps on #CTN#'s back and savagely bites #TP# neck!\n\n",
	  20,({"10d10","5d10"}),({0,"other|poison"}),0);
	add_spell("scream",
      sm+"Treluna wails like a banshee tearing at your eardrums!\n\n",
	  sm+"#CTN# holds #TP# ears as Treluna wails like a banshee!\n\n",
	  50,"10d10","other|sonic",1);
	add_spell("pummel",
	  sm+"Treluna goes into a primal R A G E !!!\n\n",
      sm+"Treluna goes into a primal R A G E !!!\n\n",
	  50,"20",0,1,"pummel");
    set_multi_cast(1);
    set_weapon_params("other|evil",30,0);
  }

}

monster_died() {
  object x;
  object y;
  tell_room(environment(this_object()),
    "The demon explodes into nothingness, leaving only a small stone behind.\n");
  x = present("corpse",environment(this_object()));
  destruct(x);


  return 0;
}


  void pummel(object att) {
    int combo, dam1;
    string loc, action, severity;
    if(att) {
    combo = (random(5)+3);
	while(combo > 0) {
	  switch(random(10) + 1) {
	    case 10:
	      loc = "head";
		  dam1 = random(10) + 5;
	    break;
	    case 7..9:
	      loc = "chest";
	      dam1 = random(10) + 5;
	    break;
	    case 5..6:
	      loc = "arm";
	      dam1 = random(5) + 5;
	    break;
	    case 3..4:
	      loc = "leg";
	      dam1 = random(5) + 5;
	    break;
	    case 2:
	      loc = "groin";
	      dam1 = random(7) + 5;
	    break;
	    default:
	      loc = "neck";
	      dam1 = random(10) + 5;
	  }
	  switch(random(10)) {
	    case 9:
	      severity = HBRED+"SLAUGHTERS"+NORM;
	      dam1 = dam1 + 5;
	    break;
	    case 6..8:
	      severity = HIR+"MAIMS"+NORM;
	      dam1 = dam1 + 7;
	    break;
	    case 5:
	      severity = YEL+HBBLU+"OWNZ"+NORM;
	      dam1 = dam1 + 10;
	    break;
	    case 3..4:
	      severity = RED+"destroys"+NORM;
	      dam1 = dam1 + 3;
	          break;
	    case 2:
	      severity = RED+"pummels"+NORM;
	      dam1 = dam1 + 4;
	    break;
	    default:
	      severity = "punishes";
	      dam1 = dam1 + 2;
	  }
	  switch(random(7)) {
	    case 0:
	      action = "- claws slashing mericlessly into the";
	    break;
	    case 1:
	      action = "with a savage bite to the";
	    break;
	    case 2:
	      action = "with a deadly kick to the";
	    break;
	    case 3:
	      action = "with a suprise bite to the";
	    break;
	    case 4:
	      action = "with a brutal combination to the";
	    break;
	    case 5:
	      action = "with a series of slashes to the";
	    break;
	    default:
	      action = "with a barrage of attacks to the";
	  }
	  tell_room(environment(att),
	  "Treluna "+severity+" "+att->query_name()+" "+action+" "+loc+"!\n");
	  if(dam1 > att->query_hp()) {
	    dam1 = (int)att->query_hp();
	    dam1 = dam1 - 1;
	  }
	  att->do_damage(({dam1}), ({"physical"}));
	  combo = combo -1;
	}
  }
}

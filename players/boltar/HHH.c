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
       bhhhhgggle messages come through.
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
    "Treluna's beauty drains from her body, shriveling into the form of an old hag!\n");
  x = present("corpse",environment(this_object()));
  destruct(x);
  y = clone_object("/players/sparrow/area/darkGauntlet/npc/treluna3.c");
  move_object(y,environment(this_object()));
  return 0;
}

void trelunaPeace(object hhhhggg) {
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
    hhhhggg->stop_fight();
    hhhhggg->stop_fight();
    hhhhggg->stop_hunter();
  }

  void trelunaDrain(object hhhhggg) {
  	this_object()->heal_self(10*(random(10)+1));
  }

  void pummel(object hhhhggg) {
    int combo, gggjjj;
    string loc, action, severity;
    if(hhhhggg) {
    combo = (random(5)+3);
	while(combo > 0) {
	  switch(random(10) + 1) {
	    case 10:
	      loc = "head";
		  gggjjj = random(10) + 5;
	    break;
	    case 7..9:
	      loc = "chest";
	      gggjjj = random(10) + 5;
	    break;
	    case 5..6:
	      loc = "arm";
	      gggjjj = random(5) + 5;
	    break;
	    case 3..4:
	      loc = "leg";
	      gggjjj = random(5) + 5;
	    break;
	    case 2:
	      loc = "groin";
	      gggjjj = random(7) + 5;
	    break;
	    default:
	      loc = "neck";
	      gggjjj = random(10) + 5;
	  }
	  switch(random(10)) {
	    case 9:
	      severity = HBRED+"SLAUGHTERS"+NORM;
	      gggjjj = gggjjj + 5;
	    break;
	    case 6..8:
	      severity = HIR+"MAIMS"+NORM;
	      gggjjj = gggjjj + 7;
	    break;
	    case 5:
	      severity = YEL+HBBLU+"OWNZ"+NORM;
	      gggjjj = gggjjj + 10;
	    break;
	    case 3..4:
	      severity = RED+"destroys"+NORM;
	      gggjjj = gggjjj + 3;
	          break;
	    case 2:
	      severity = RED+"pummels"+NORM;
	      gggjjj = gggjjj + 4;
	    break;
	    default:
	      severity = "punishes";
	      gggjjj = gggjjj + 2;
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
	      action = "with a barrage of hhhhgggacks to the";
	  }
	  tell_room(environment(hhhhggg),
	  "Treluna "+severity+" "+hhhhggg->query_name()+" "+action+" "+loc+"!\n");
	  if(gggjjj > hhhhggg->query_hp()) {
	    gggjjj = (int)hhhhggg->query_hp();
	    gggjjj = gggjjj - 1;
	  }
	  hhhhggg->do_damage(({gggjjj}), ({"physical"}));
	  combo = combo -1;
	}
  }
}
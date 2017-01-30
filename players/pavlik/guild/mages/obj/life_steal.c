#include "/players/pavlik/closed/colors.h"
#define ME capitalize(owner->query_name())
#define IT capitalize(target->query_name())
#define MAX 9

/*
 * This spell does damage to the target and heals the player.
 * There is always the chance for the target to reverse the
 * spell and heal by using the players hit points. If the target
 * breaks the spell the player suffers major damage.
 *
 * A player can do NO other commands while this spell is in effect!
 * In fact the player must wait for X amount of time AFTER the
 * spell has been completed before he can do anything else.
 *
 * Hopefully the fact that the caster can execute NO other commands
 * and the severe damage that can be suffered if the spell fails will
 * justify the numbers of this spell.
 *
 * Changes Made (11/21/05) :
 *    - reduced max from 12 to 9
 *    - increased per round cost to 20 sp
 *    - changed amount formula from random(necr)/4 to random(necr)/3
 *    - increased max amount from 20 to 30
 *    - added check to make minimum damage = 3
 *    - various text changes
 */

object owner;
object target;
int conduit;
int count;

reset(arg){
  if(arg) return;
  owner = 0;
  target = 0;
  conduit = 1;
  count = 0;
  call_out("spell", 3);
  call_out("gone", 300);
}

short() { 
  if(conduit > 0) return HIW+"An arcing conduit of energy"+NORM;
  else return;
}

long() {
  if(conduit > 0) write("An crackling conduit of energy arcs between "+ME+" and "+IT+"!\n");
  return;
}

id(str) {
  return str == "conduit" || str == "life_steal" ||
  str == ME+"'s conduit";
}

get(){ return 0; }
drop(){ return 1; }
query_owner(){ return owner; }
set_owner(ob){ owner = ob; }
query_target(){ return target; }
set_target(ob){ target = ob; }
query_conduit(){ return conduit; }

init() {
  add_action("do_nothing"); add_xverb("");
}

/*
 * Spellcaster cannot execute any other commands when this spell is in effect.
 * (note: wizards get the write msg but fall through to allow commands)
 */
do_nothing(str) {
  if(conduit > 0) {
	write(HIW+"Your entire being is concentrated on the conduit - You can't do anything else!"+NORM+"\n");
  }
  else {
	write(HIW+"Your entire body is numb - You can't do a thing!"+NORM+"\n");
	say(ME+" twitches slightly.\n");
  }
  if(this_player() && this_player()->query_level() < 20) {
	return 1;
  }
}


spell() {
  
  int num, amt, msg;
  int chance;

  if(!owner) return destruct(this_object());                
  if(!environment(owner)) return call_out("spell", 2);

  if(!owner) {
	destruct(this_object());
	return 1;
  }

  if(!target || !present(target, environment(owner))) {
	end_conduit();
	return 1;
  }

  if(!owner->query_attack()) {
	end_conduit();
	return 1;
  }

  if(owner->query_attack() != target) {
	end_conduit();
	return 1;
  }

  /* this is never supposed to happen */
  if(!present("mageobj", owner)) {
	end_conduit();
	return 1;
  }

  /* end the spell if we run out of spell points */
  if(owner->query_sp() < -10) {
	tell_object(owner, HIY+"You have become too too tired to maintain the Lifesteal spell."+NORM+"\n");
	end_conduit();
	return 1;
  }

  /* end the spell after max repetitions */
  if(count > MAX) {
	if(owner->query_level() > 20)
		tell_object(owner, "Lifesteal: maxiumum repititions reached.\n");
	end_conduit();
	return 1;
  }

  msg = random(4);
  if(msg == 0)
	tell_room(environment(owner),
	"The arcing conduit between "+ME+" and "+IT+" "+HIY+"crackles loudly"+NORM+".\n");
  else if(msg == 1)
	tell_room(environment(owner),
	"A "+HIW+"blazing conduit of energy"+NORM+" showers you with "+HIY+"sparks"+NORM+".\n");
  else if(msg == 2)
	tell_room(environment(owner),
	"Jagged "+HIY+"bolts of magical energy"+NORM+" flash between "+ME+" and "+IT+".\n");
  else
	tell_room(environment(owner),
	"A "+HIW+"conduit of energy"+NORM+" "+MAG+"sizzles"+NORM+" between "+ME+" and "+IT+".\n");

  /*
   * Chance is based on the target's level.
   * Figure the average monster these players are going after is between 17-19
   * so num will be around 136-152.
   */
  chance = target->query_level() * 8;
  if(chance > 168) chance = 168;
  num = random(chance);

  /*
   * if the random chance is in top 3-4% then amazing things can happen,
   * none of which are good for the spell caster...
   */
  if(num >= (chance - chance/26)) {
	tell_room(environment(owner),
		"The "+HIY+"magical conduit"+NORM+" "+HIR+"RUPTURES"+NORM+" and "+ME+" is struck by a powerful backlash of energy!\n"+
		"A deafening "+HIR+"concussion blast"+NORM+" pounds through your skull and shakes the ground beneath your feet!\n");
	owner->hit_player(random(100));
	target->heal_self(random(100));
	conduit = 0;
	end_conduit();
	return 1;
  }

  /* if fail check then target sucks owners hit points */
  if(num > present("mageobj", owner)->query_total_necr()) {
	tell_room(environment(owner),
		IT+" "+HIR+"reverses"+NORM+" the flow and "+HIR+"sucks"+NORM+" away "+ME+"'s life!\n");
	amt = random(30);
	owner->heal_self(-amt/2);
	target->heal_self(amt);
	if(owner->query_level() > 20)
		tell_object(owner, HIR+"[Lifesteal: target heal: "+amt+" / player heal: -"+amt/2+"]"+NORM+"\n");
  }
  /* else the owner sucks hit points of target */
  else {
	tell_room(environment(owner),
		ME+" "+HIR+"steals"+NORM+" "+IT+"'s "+HIW+"life force"+NORM+" through the conduit!\n");
	amt = random(present("mageobj", owner)->query_total_necr()) / 3;
	if(amt > 30) amt = 30;
	if(amt < 4) amt = 4;
	target->hit_player(amt, "other|mental");
	owner->add_hit_point(amt/2);
	if(owner->query_level() > 20)
		tell_object(owner, HIW+"[Lifesteal: dmg: "+amt+" / heal: "+(amt/2)+"]"+NORM+"\n");
  }
  owner->add_spell_point(-20);
  count++;
  call_out("spell", 4);
  return 1;
}

/*
 * This function ends the spell.  Note that the player still remains
 * helpless and unable to execute commands until a recovery-time has
 * passed.  This leaves the player helpless in combat.
 */
end_conduit() {
  int timed;
  if(!owner) return destruct(this_object());
  if(environment(owner)) {
	tell_object(owner, "Your "+HIR+"Lifesteal"+NORM+" spell comes to an end.\n");
	tell_room(environment(owner),
	  "The crackling "+HIW+"conduit of white energy"+NORM+" "+HIC+"disappears"+NORM+" in a "+
	  HIY+"bright flash"+NORM+"!\n"+
	  ME+" "+HIG+"slumps"+NORM+" to the ground, "+HIR+"exhuasted"+NORM+" by the effort.\n");
  }
  conduit = 0;
  timed = 40 - random(present("mageobj", owner)->query_total_necr()) / 3;
  if(timed < 7) timed = 7;
  call_out("recover", timed);
  return 1;
}

recover() {
  if(owner)
	tell_object(owner, "\n"+
	  HIW+"The numbness leaves your body and you are "+NORM+MAG+"able to move"+NORM+HIW+" once again."+NORM+"\n\n");
  destruct(this_object());
  return 1;
}

/*
 * This function assures us that the object will not get stuck and
 * leave the player forever helpless.  It is a bit redundant but
 * its a good safeguard to have in place.
 */
gone() {
  if(owner)
	tell_object(owner, HIW+"You recover from the Life Steal spell."+NORM+"\n");
  destruct(this_object());
  return 1;
}


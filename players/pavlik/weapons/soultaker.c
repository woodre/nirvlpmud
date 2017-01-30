inherit "obj/weapon.c";
#include "/players/pavlik/closed/colors.h"

#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())
#define tp this_player()
#define ST RED+"Soultaker"+NORM

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name(RED+"the Soultaker"+NORM);
  set_alt_name("soultaker");
  set_alias("soul sword");
  set_type("sword");
  set_short(RED+"the Soultaker "+HIR+"[evil]"+NORM);
  set_long(
  "A wicked blade of blood stained carpathian steel.  You are in the presence\n"+
  "of the infamous "+RED+"Soultaker!"+NORM+"  The white ivory handle is lined with\n"+
  "gleaming diamonds that shine brilliantly in contrast to the deadly black blade.\n"+
  "The sword simply emanates "+HIR+"absolute POWER"+NORM+"\n");
  set_class(19);
  set_value(50000);
  set_save_flag(1);
  message_hit = ({
    HIY+"crippled"+NORM, " with a blow of "+HIC+"devastating"+NORM+" force",
    "delivered a "+RED+"massive"+NORM+" two-handed "+HIR+"hack"+NORM+" into", "'s body",
    MAG+"flayed"+NORM+" the flesh from", "'s bones",
    BLU+"bashed"+NORM, " soundly with the "+RED+"Soultaker's"+NORM+" jeweled hilt",
    "chopped "+MAG+"cruelly"+NORM+" into", "'s body",
    "growled menacingly as "+ST+" bit into", "'s body",
    "stabbed "+GRN+"viscously"+NORM+" at", "",
  });
  set_hit_func(this_object());
}

weapon_hit(attacker){
  int x, ranx;
  object limb;

  /*
   * Can only be wielded by Evil players.
   */
  if(tp->query_alignment() > 0){
	if(random(2)==0)
	write(ST+" fights against you.  The sword glows "+HIY+"too hot"+NORM+" in your hands!\n");
	else
	write("The evil sword causes your hands to "+HIR+"blister"+NORM+" painfully.\n");
	tp->heal_self(-random(10));
	return 0;
  }

  /*
   * Constant drain on the wielders spell points.
   */
  tp->add_spell_point(-random(4));

  /*
   * make sure we are REALLY evil for the good stuff.
   */
  if(tp->query_alignment() < -300) ranx = random(10);
  else ranx = random(5);

  /*
   * see special function below.
   */
  if(killing_blow(attacker)) {
	return 7;
  }

  if(ranx == 2){
	tell_room(environment(tp),
	"An "+MAG+"Aura of Death"+NORM+" hangs over the room.\n"+
	"The wicked "+ST+" gleams brightly with evil magic!\n");
	return random(4);
  }
  else if(ranx == 3){
	write(ST+" whistles sharply as you swing it through its deadly arc!\n");
	say(ST+" whistles sharply as "+ME+" swings it through its deadly arc!\n");
	return 3;
  }
  else if(ranx == 4){
	tell_room(environment(tp),
	ST+" snickers evily as it CHOPS into "+IT+"'s flesh!\n");
	return 4;
  }
  else if(ranx == 5){
	tell_room(environment(tp),
	ME+" "+HIM+"buries"+NORM+" the sinister blade deep into the body of his enemy!\n"+
	"You hear the sickening <CRUNCH> of "+IT+"'s bones!\n");
	return 5;
  }
  else if(ranx == 6){
	tell_room(environment(tp), ME+" plunges "+ST+" deep into his enemy's chest!\n");
	if(call_other(tp, "query_attrib", "wil") > random(60)){
		tell_room(environment(tp), "The evil sword "+HIM+"drinks "+IT+"'s life greedily!\n"+NORM);
		write("You feel "+HIY+"stronger"+NORM+" as "+ST+" feeds you life!\n");
		tp->heal_self(random(8));
		return 0;
	}
	return 3;
  }
  else if(ranx == 7){
	tell_room(environment(tp),
	ST+" "+BLU+"sliccccccces"+NORM+" through the air and buries itself into "+IT+"'s skull!\n");
	return random(7);
  }
  else if(ranx == 8){
	if(call_other(tp, "query_attrib", "str") > random(40)){
		tell_room(environment(tp),
		ME+" cackles like a maniac and hacks "+HIR+"SAVAGELY"+NORM+" at "+IT+".\n");
		return 3;
	} else {
		tell_room(environment(tp), "\n"+
		"THere is a loud WHOOSH as "+ST+" cleaves clean through "+IT+"'s body!!!\n"+
		IT+"'s severed limb drops into the dust.\n\n");
		limb = clone_object("obj/treasure");
		x = random(4);
		if(x == 0){
			limb->set_short(IT+"'s severed hand"); limb->set_id("hand"); } else 
		if(x == 1){
			limb->set_short(IT+"'s severed leg"); limb->set_id("leg"); } else
		if(x == 2){
			limb->set_short(IT+"'s severed arm"); limb->set_id("arm"); } else {
		limb->set_short(IT+"'s severed foot"); limb->set_id("foot"); }
		limb->set_long(IT+"'s severed limb. [bloody]\n");
		limb->set_alias("corpse");
		limb->set_value(0);
		limb->set_weight(5);
		move_object(limb, environment(tp));
		return 7;
	}
  }
}


/*
 * This provides a one-shot killing blow to a target that
 * is 5% or less in health.
 */
killing_blow(obj) {
  string name;

  /*
   * Not avaliable against players.
   */
  if(!obj->query_npc()) {
	return 0;
  }

  /*
   * Make sure the target is at 5% health or less.
   */
  if(obj->query_hp() > obj->query_mhp()/20 || obj->query_hp() > 50) {
	return 0;
  }

  name = capitalize(obj->query_name());

  tell_room(environment(tp), "\n\n"+
  ME+" swings "+ST+" in a great arc and "+HIC+"PARTS "+HIM+name+"'s "+HIC+
  "BODY DOWN THE MIDDLE!!!\n"+NORM+
  name+"'s "+RED+"inards"+NORM+" spill onto the ground and "+HIR+"sizzle"+NORM+" at your feet.\n"+
  "\n\n");
  obj->heal_self(-obj->query_hp());
  this_player()->add_spell_point(-35);
  return 1;
}


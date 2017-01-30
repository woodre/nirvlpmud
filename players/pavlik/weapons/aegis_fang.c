#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())
#define AEG CYN+"Aegis Fang"+NORM

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name(AEG);
  set_alt_name("aegis fang");
  set_short(AEG);
  set_long(
	"The mithiril warhammer, "+AEG+", rests in your posession. Made \n"+
	"by Breunor for his adopted son Wulfgar, this powerfully enchanted weapon\n"+
	"has defeated many powerful evil creatures. Forged from a solid piece of\n"+
	"mithiril, carved from the very heart of Mithiril Hall, the warhammer\n"+
	"glistens in the light. Not a scratch can be seen on its delicatly runed\n"+
	"head.\n");
  set_class(20);
  set_type("club");
  set_weight(5);
  set_value(8450);
  set_save_flag(1);
  message_hit = ({
    "screamed in "+HIW+"blood-thirsty rage"+NORM+" and "+HIW+"DEMOLISHED"+NORM, "",
    "bellowed fiercly and "+HIR+"BURIED"+NORM+" the "+AEG+" into", "'s body!",
    HIR+"knocked"+NORM, " "+RED+"to the ground"+NORM+" with a heavy blow from "+AEG,
    "hefted the mighty "+AEG+" and "+YEL+"bashed"+NORM, " "+YEL+"sensless"+NORM,
    "swung the "+CYN+"mithiril warhammer"+NORM+" and bashed", " in the head",
    MAG+"snarled"+NORM+" as "+AEG+" "+MAG+"crashes"+NORM+" into", "",
    "clipped", " with an ill-timed swing of "+AEG,
  });
  set_hit_func(this_object());
}

wield(str) {
  if(id(str)) {
    /*
     * Can only be wielded by Good players.
     */
    if(this_player()->query_alignment() < 100) {
	write("Your soul is not pure enough to wield such a mighty weapon.\n");
	return 1;
    }
  }
  ::wield(str);
  if(wielded) {
	write("The "+HIW+"call for battle"+NORM+" echoes in your blood as you heft the mighty "+AEG+"!\n");
  }
  return 1;
}

weapon_hit(attacker) {
  int stat;

  if(attacker->query_alignment() >= 200) {
	return -random(12);
  }

  if(death_blow(attacker)) {
	return 5;
  }

  stat = call_other(this_player(), "query_attrib", "pie") + call_other(this_player(), "query_attrib", "str");

  if(stat > random(100)) {
	switch (random(3)) {
	case 0 :
	   write("You hurl "+AEG+" at "+IT+"!  "+HIC+"<<< CRUNCH!!! >>>"+NORM+"\n");
	   write(AEG+" instantly reappears in your hand.\n");
	   say(ME+" hurls the "+AEG+" at "+IT+"!  "+HIC+"<<< CRUNCH!!! >>>"+NORM+"\n");
	   say(AEG+" instantly reappears in "+ME+"'s hand.\n");
	   break;
	case 1 :
	   write("With a "+HIY+"deafening battle-cry"+NORM+" you leap into the fray!\n");
	   write(AEG+" "+HIW+"arcs overhead"+NORM+" and comes "+HIR+"crashing"+NORM+" down on "+IT+"!\n");
	   say("With a "+HIY+"deafening battle-cry"+NORM+" "+ME+" leaps into the fray!\n");
	   say(AEG+" "+HIW+"arcs overhead"+NORM+" and comes "+HIR+"crashing"+NORM+" down on "+IT+"!\n");
	   break;
	case 2 :
	   write("You hurl "+AEG+"!  Aegis Fang "+HIW+"soars"+NORM+" through the air and "+HIC+"hammers"+NORM+" "+IT+"!\n");
	   write("The "+AEG+" reappears in your hand.\n");
	   say(ME+" hurls "+AEG+"!  Aegis Fang "+HIW+"soars"+NORM+" through the air and "+HIC+"hammers"+NORM+" "+IT+"!\n");
	   say("The "+AEG+" reappears in "+ME+"'s hand.\n");
	   break;
	}
	return 2 + random(6);
  }
  return;
}

death_blow(attacker) {
  if((attacker->query_hp() <= attacker->query_mhp()/14) && attacker->query_hp() < 50) {
	say("\n"+ME+" calls on the Gods of War and hurls "+AEG+" through the air!\n");
	write("\nYou call on the Gods of War and hurl "+AEG+" through the air!\n");
	tell_room(environment(attacker),
	"The "+CYN+"mithiril hammer"+HIW+" soars through the air"+NORM+" and "+MAG+"connects"+NORM+" with "+IT+"'s head!\n"+
	AEG+" "+HIR+"CRUSHES"+NORM+" "+IT+"'s skull like a "+GRN+"ripe melon"+NORM+"!\n");
	tell_room(environment(attacker),
	IT+"'s "+RED+"lifeless body"+NORM+" falls to the ground.\n"+
	"\n");
	say(AEG+" instantly "+HIW+"reappears in "+ME+"'s hand.\n");
	write(AEG+" instantly "+HIW+"reappears"+NORM+" in your hand.\n");
	attacker->heal_self(-attacker->query_hp());
	this_player()->add_spell_point(-22);
	return 1;
  }
  return 0;
}



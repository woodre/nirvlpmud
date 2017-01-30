#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())
#define DMN HIC+"Demonbane"+NORM

/*
 * A weapon_class 20 weapon with some special returns.
 * The weapon can only be wielded by players with good alignment
 * and can only be used against evil monsters.
 */

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name(HIC+"Demonbane"+NORM);
  set_alt_name("demonbane");
  set_short("the "+HIC+"Demonbane Mace"+NORM);
  set_long(
    "The "+DMN+" Mace is a weapon weapon created at the forge of\n"+
    "the gods.  The silvery metal of the mace's shaft sparkles\n"+
    "brilliantly and the blue-stoned pommel is said to contain the\n"+
    "magic of Biln, God of Goodness.  The large unusual stone shines\n"+
    "magnificently, casting back the darkness.\n");
  set_class(20);
  set_type("mace");
  set_weight(5);
  set_value(4450);
  set_save_flag(1);
  message_hit = ({
    HIM+"BEAT"+HIY,      HIM+" within an inch of its life!!"+NORM,
    HIM+"clobbered"+NORM, " brutaly with a might swing of "+DMN,
    HIY+"bashed"+NORM,    " into a fleshy pulp",
    HIC+"crunched"+NORM+" into", " with a mighty swing of "+DMN,
    "smacked",            " with a mighty swing of "+DMN,
    "thumped",            " soundly",
    "nearly smashed",     " into the ground",
  });
  set_hit_func(this_object());
}

wield(str) {
  if(id(str)) {
    /*
     * Can only be wielded by Good players.
     */
    if(this_player()->query_alignment() < 250) {
	write("Your soul is not pure enough to wield such a mighty weapon.\n");
	return 1;
    }
  }
  ::wield(str);
  if(wielded) {
	write("The holy mace "+YEL+"hums"+NORM+" quietly in your grip.\n");
	say(DMN+" "+YEL+"hums"+NORM+" quietly in "+ME+"'s grip.\n");
  }
  return 1;
}

weapon_hit(attacker){
  int pie, aln;

  /*
   * What if we have turned evil?
   */
  if(this_player()->query_alignment() < 100) {
	write(
	"The great "+DMN+" mace shivers in your hand and then falls to\n"+
	"the ground.  You know you have become unworthy to wield such\n"+
	"a weapon as this.\n");
	command("drop demonbane", this_player());
	return;
  }

  /*
   * We aren't supposed to fight good beings with this weapon!
   */
  if(attacker->query_alignment() > 100) {
	write("The "+HIW+"noble"+NORM+" mace seems to "+BLU+"shudder"+NORM+" in your grasp.\n");
	this_player()->add_spell_point(-2);
	this_player()->add_alignment(-random(5));
	return;
  }

  pie = random(call_other(this_player(), "query_attrib", "pie")) + 1;

  if(pie == 20) {
	tell_room(environment(this_player()), "\n"+
	"The mighty "+DMN+" whistles through the air and "+HIM+"CRASHES"+NORM+" into "+IT+"'s head!\n"+
	IT+"'s skull "+MAG+"cracks open"+NORM+" like an egg!\n\n");
	return 7;
  }
  else if(pie == 18) {
	tell_room(environment(this_player()),
	"A "+HIY+"holy light"+NORM+" fills the room as "+ME+"'s mace arcs through the air!\n");
	heal_good();
	return;
  }
  else if(pie == 13 || pie == 15) {
	tell_room(environment(this_player()),
	"A resounding "+HIG+"'CRUNCH'"+NORM+" echoes through your ears.\n"+
	IT+"'s blood "+RED+"splatters"+NORM+" into the air and falls about you like rain.\n");
	return random(6);
  }
  else if(pie == 9) {
	write("The "+DMN+" "+HIW+"hums"+NORM+" powerfully in your grip!\n");
	say("The "+DMN+" "+HIW+"hums"+NORM+" powerfully in "+ME+"'s grip!\n");
	return 4;
  }
  return;
}

/*
 * Heal all good things in the room a minor amount.
 */
heal_good() {
  object *obj;
  int i;

  obj = all_inventory(environment(this_player()));
  for(i=0; i<sizeof(obj); i++) {
	if(obj[i]->query_alignment() > 100) {
		obj[i]->heal_self(random(10));
		tell_object(obj[i], "You feel somewhat "+YEL+"refreshed"+NORM+".\n");
	}
  }
}


#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("crush");
  set_name("Soul Crush");
  set_color_name(MAG+"Soul Crush"+NORM);
  set_level(3);
  set_school("necromancy");
  set_stat("power");
  set_combat_spell(1);
  set_descrip(
	"Cast this spell to instantly drain the remaining lifeforce " +
	"from an opponent.  The target must be nearing death, however " +
	"more advanced Mages can use this spell on healthier targets.\n"
  );
}

query_sp_cost(){ return CRUSH_COST; }
query_cost_string(){ return CRUSH_COST + " sp"; }


spell()
{
  object obj;
  int total, dmg;
  int msg;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  /* the max damage we can do is based on guild stat */
  total = guild->query_total_guild_stat("necromancy");

  /* if monster is healthier than max damage then we cannot do this */
  if(obj->query_hp() >= total)
  {
	notify_fail(IT+" is too healthy for this spell to succeed.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ...\n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell!\n");
	write(IT+"'s lifeforce grows "+HIM+"stronger"+NORM+" from your mistake.\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell.\n");
	obj->add_hit_point(total);
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  msg = random(4);
  if(msg == 0)
  {
	write("\nYou "+HIY+"SHOUT"+NORM+" a "+HIB+"powerful"+NORM+" word of "+HIM+"magic"+NORM+"!\n");
	tell_room(env, "\n"+ME+" "+HIY+"SHOUTS"+NORM+" a "+HIB+"powerful"+NORM+" word of "+HIM+"magic"+NORM+"!\n", ({tp}));
	tell_room(env,
	  IT+"'s body "+HIR+"explodes instantly"+NORM+", showering the room with "+HIR+"gore"+NORM+"!\n"+
	  IT+"'s "+MAG+"mutlilated"+NORM+" body crumples to the ground.\n");
  }
  else if(msg == 1)
  {
	write("\nYou release a powerful "+HIR+"death spell"+NORM+"!\n");
	tell_room(env, "\n"+ME+" releases a powerful "+HIR+"death spell"+NORM+"!\n", ({tp}));
	tell_room(env,
	  IT+"'s body "+HIG+"turns to stone"+NORM+", and then "+HIBLK+"crumbles to dust!\n"+NORM);
  }
  else if(msg == 2)
  {
	write("\nYou point your hands to the sky ... \n");
	tell_room(env, "\n"+ME+" points "+PO+" hands to the sky ... \n", ({tp}));
	tell_room(env,
	  "A brilliant "+HIY+"bolt of lightning"+NORM+" streaks down and "+HIR+"incinerates"+NORM+" "+IT+"!\n"+
	  IT+"'s "+HIBLK+"charred body"+NORM+" falls to the ground.\n");
  }
  else if(msg == 3)
  {
	write("\nYou trace an "+CYN+"ancient sigil"+NORM+" of "+HIC+"magic"+NORM+" in the air.\n");
	tell_room(env, "\n"+ME+" traces an "+CYN+"ancient sigil"+NORM+" of "+HIC+"magic"+NORM+" in the air.\n", ({tp}));
	tell_room(env,
	  "The bones of "+IT+" "+HIB+"instantly disintegrate"+NORM+" inside its body!\n"+
	  IT+"'s "+MAG+"shapeless"+NORM+" body forms a "+HIC+"puddle"+NORM+" on the ground.\n");
  }

  obj->death();

  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}


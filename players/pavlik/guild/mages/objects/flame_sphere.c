#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "/players/pavlik/guild/mages/inherit/tell_damage.c";

#define FSP HIR+"flame "+NORM+HIW+"sphere"+NORM

object owner;
int damage;

reset(arg){
  if(arg) return;
  owner = 0;
  damage = 0;
}

short(){ return; }
long(){ write("a mages flame_sphere_obj.\n"); return; }
id(str){ return str == "flame_sphere_obj"; }
get(){ return 0; }
drop(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }


init_spell()
{
  damage = present("mageobj", owner)->query_total_guild_stat("conjuration") / 7;
  call_out("continue_spell", 4);
  return 1;
}


continue_spell()
{
  int r;

  if(!owner || !present("mageobj", owner))
  {
	destruct(this_object());
	return 1;
  }

  if(environment(this_object()) != owner || !owner->query_attack())
  {
	if(present("mageobj", owner))
		present("mageobj", owner)->set_casting(0);
	tell_object(owner, MPROMPT+"Your "+FSP+" spell ends uneventfully.\n");
	destruct(this_object());
	return 1;
  }

  if(damage >= FSP_MAX_DAMAGE)
  {
	cast_spell();
	return 1;
  }

  damage += FSP_DAMAGE;
  r = random(3);

  if(r == 0)
  {
	tell_object(owner,
	  MPROMPT+"The "+FSP+" continues to grow larger in your hands.\n");
	tell_room(environment(owner),
	  "The "+FSP+" continues to grow in "+OWN+"'s hands.\n",
	  ({owner}));
  }
  else if(r == 1)
  {
	tell_object(owner,
	  MPROMPT+"You continue to gather "+HIW+"magical"+NORM+HIR+" fire"+NORM+" in your hands.\n");
	tell_room(environment(owner),
	  OWN+" continues to gather "+HIW+"magical "+NORM+HIR+"fire"+NORM+".\n",
	  ({owner}));
  }
  else
  {
	tell_object(owner,
	  MPROMPT+"You continue to increase the power of your "+FSP+" spell.\n");
	tell_room(environment(owner),
	  OWN+"'s "+FSP+" continues to gather strength.\n",
	  ({owner}));
  }

  if(damage >= FSP_MAX_DAMAGE)
  {
	tell_object(owner,
	  MPROMPT+"Your "+FSP+" has reached "+HIC+"maximum level!\n"+NORM);
  }

  call_out("continue_spell", 4);
  return 1;
}


cast_spell()
{
  object obj;

  if(!owner || !present("mageobj", owner))
  {
	destruct(this_object());
	return 1;
  }

  if(environment(this_object()) != owner || !(obj = owner->query_attack()))
  {
	if(present("mageobj", owner))
		present("mageobj", owner)->set_casting(0);
	tell_object(owner, MPROMPT+"Your "+FSP+" spell ends uneventfully.\n");
	destruct(this_object());
	return 1;
  }

  tell_object(owner,
    "You hurl the "+FSP+" at your enemy!\n" +
    "The ball of fire "+HIY+"*{ "+NORM+HIR+"E X P L O D E S "+NORM+HIY+"}*"+NORM+" on impact with "+IT+"!\n" +
    IT+"'s flesh "+YEL+"sizzles"+NORM+" and "+RED+"burns"+NORM+" the magical fire "+HIW+"consumes"+NORM+" it.\n");

  tell_room(environment(owner),
    capitalize(owner->query_name())+" hurls a "+FSP+" at "+owner->query_possessive()+" enemy!\n",
    ({owner}));
  tell_room(environment(owner),
    "The ball of fire "+HIY+"*{ "+NORM+HIR+"E X P L O D E S "+NORM+HIY+"}*"+NORM+" on impact with "+IT+"!\n" +
    IT+"'s flesh "+YEL+"sizzles"+NORM+" and "+RED+"burns"+NORM+" as "+OWN+"'s magical fire "+HIW+"consumes"+NORM+" it.\n",
    ({owner}));

  tell_damage2(damage, obj, owner);

  if(damage > FSP_MAX_DAMAGE)
	damage = FSP_MAX_DAMAGE;

  present("mageobj", owner)->set_casting(0);
  obj->do_damage(({damage}), ({"other|fire"}));
  destruct(this_object());
  return 1;

}


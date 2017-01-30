inherit "/obj/treasure";
#include "/obj/ansi.h"

#define PROMPT HIC+"*"+NORM+CYN+"><"+NORM+HIC+"*"+NORM
#define OWNER capitalize(owner->query_real_name())
#define ME capitalize(this_player()->query_real_name())
#define IT capitalize(obj->query_name())

object owner;
string what;
string error_room;
int spell_fail, spell_cost;

reset(arg) {
  if(arg) return;
  set_long("A Mage Summons.\n");
  set_weight(0);
  set_value(0);
  owner = 0;
  what = "goto";
  spell_fail = 0;
  error_room = allocate(10);
  error_room[0] = "room/shop";
  error_room[1] = "room/church";
  error_room[2] = "room/slope";
  error_room[3] = "room/mount_pass";
  error_room[4] = "room/farmroad1";
  error_room[5] = "room/sea";
  error_room[6] = "room/inn";
  error_room[7] = "room/fortress";
  error_room[8] = "room/path1";
  error_room[9] = "room/big_tree";
  call_out("do_tlp", 60);
  call_out("times_up", 120);
}

id(str)
{
  return str == "summon_obj" || str == "mage_teleport";
}

set_owner(ob){ owner = ob; }
set_what(str){ what = str; }
set_spell_fail(str){ spell_fail = str; }
set_spell_cost(int x) { spell_cost = x; }

init()
{
  add_action("answer_no","tpno");
  add_action("answer_yes","tpyes");
}


do_tlp()
{
  if(!environment() || !owner)
  {
	destruct(this_object());
	return 1;
  }

  if(what == "goto")
	tell_object(environment(),
	  PROMPT+" "+OWNER+" has asked your permission to "+HIB+"Teleport"+NORM+" to your location.\n");
  else
	tell_object(environment(),
	  PROMPT+" "+OWNER+" has offered to "+HIB+"Teleport"+NORM+" you to "+
	  owner->query_possessive()+" location.\n");

  tell_object(environment(),
    "If you wish to "+HIY+"accept"+NORM+" "+OWNER+"'s request, type '"+HIW+"tpyes"+NORM+"'.\n"+
    "If you wish to "+RED+"decline"+NORM+" the request, type '"+HIW+"tpno"+NORM+"'.\n");

  return 1;
}


times_up()
{
  if(!owner || !environment() || !environment(environment()))
  {
	destruct(this_object());
	return 1;
  }

  tell_object(environment(),
    PROMPT+" No Answer - You have "+RED+"declined"+NORM+" "+OWNER+"'s Teleport request.\n");

  tell_object(owner,
    PROMPT+" No Answer - "+capitalize(environment()->query_name())+" has "+RED+"declined"+NORM+" your Teleport request.\n");

  destruct(this_object());
  return 1;
}


answer_no()
{
  if(!owner)
  {
	write("You "+RED+"decline"+NORM+" the "+HIB+"Teleport"+NORM+" request.\n");
	destruct(this_object());
	return 1;
  }

  write("You "+RED+"decline"+NORM+" "+OWNER+"'s "+HIB+"Teleport"+NORM+" request.\n");
  tell_object(owner,
    "\n" +
    PROMPT+" "+ME+" has "+RED+"declined"+NORM+" your "+HIB+"Teleport"+NORM+" request.\n");

  destruct(this_object());
  return 1;
}


answer_yes()
{
  object ob, obj;

  if(!owner || !environment(owner) || !environment(this_player()))
  {
	write("The "+HIB+"Teleport"+NORM+" request has been "+MAG+"cancelled"+NORM+", you can no longer accept it.\n");
	destruct(this_object());
	return 1;
  }

  write("You "+HIY+"accept"+NORM+" "+OWNER+"'s "+HIB+"Teleport"+NORM+" request.\n");
  tell_object(owner, PROMPT+" "+ME+" has "+HIY+"accepted"+NORM+" your "+HIB+"Teleport"+NORM+" request.\n");

  if(environment(owner)->real() == "NT" || environment(this_player())->realm() == "NT")
  {
	tell_object(this_player(), "Strange forces "+HIR+"block"+NORM+" the "+HIB+"Teleport"+NORM+" spell.\n");
	tell_object(owner, "Strange forces "+HIR+"block"+NORM+" the "+HIB+"Teleport"+NORM+" spell.\n");
	destruct(this_object());
	return 1;
  }

  if(what == "bring")
	obj = this_player();
  else
	obj = owner;

  tell_object(obj,
    "You begin to feel a "+HIB+"tugging force"+NORM+" on your body.  Your entire person is simultaneously\n" +
    HIY+"ripped apart"+NORM+" and "+HIM+"squished together"+NORM+".  The ground drops out from under your feet and you\n" +
    "are "+HIM+"magically"+NORM+" swept "+HIW+"away!\n"+NORM);
  tell_room(environment(obj),
    "You feel the pulse of "+HIM+"magic"+NORM+" in the air.\n" +
    IT+" is suddenly wrapped in a "+HIB+"bubble"+NORM+" of "+HIM+"magical energy"+NORM+".\n" +
    "The magic "+HIB+"bubble"+NORM+" lifts into the air and "+IT+" "+HIW+"disappears"+NORM+" with a sudden "+HIY+"POP!\n"+NORM,
    ({obj}));

  if(spell_fail)
  {
	tell_object(owner, "Something has gone "+HIR+"horribly wrong"+NORM+" with your spell!\n");
	if(what == "bring")
	{
		tell_object(owner, IT+" was lost in the "+HIB+"Teleport!\n"+NORM);
		tell_object(this_player(), OWNER+" has "+HIR+"miscast"+NORM+" the spell and you reappear "+HIC+"somewhere else!\n"+NORM);
	}
	else
	{
		tell_object(owner, "You reappear in a new location.\n");
		tell_object(this_player(), OWNER+" has "+HIR+"miscast"+NORM+" the spell and "+HIM+"fails"+NORM+" to arrive.\n");
	}
	move_object(obj, error_room[random(sizeof(error_room))]);
  }
  else if(what == "bring")
	move_object(this_player(), environment(owner));
  else
	move_object(owner, environment(this_player()));

  tell_object(obj, "You rematerialize somewhere else ... \n");

  tell_room(environment(obj),
    "A bubble of "+HIM+"magical energy"+NORM+" suddenly "+HIC+"appears"+NORM+" in the air!\n" +
    "The bubble "+HIW+"explodes"+NORM+" with a sudden "+HIY+"POP!"+NORM+" and "+IT+" drops to the ground.\n",
    ({obj}));

  owner->add_spell_point(-spell_cost);
  destruct(this_object());
  return 1;

}

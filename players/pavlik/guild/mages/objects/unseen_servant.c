inherit "obj/monster";
#include <ansi.h>

#define ME capitalize(owner->query_name())
#define DEST capitalize(destination->query_name())

int failed;
object owner;
object destination;
object cargo;

reset(arg){
 ::reset(arg);
 if(arg) return;
 set_name("Shadowy Servant");
 set_race("unseen_servant");
 set_short("A Shadowy Servant");
 set_long("A shadowy servant, summoned by a powerful Mage.\n");
 set_hp(100);
 set_ac(50);
 set_wc(1);
 set_al(0);
 set_level(1);
 call_out("serve", 10+random(25));
}

set_owner(ob){ owner = ob; }
set_destination(ob){ destination = ob; }
set_cargo(ob){ cargo = ob; }
set_failed(i){ failed = i; }

serve()
{
  int value;

  if(!owner)
  {
	destruct(this_object());
	return 1;
  }

  if(!cargo)
  {
	tell_object(owner,
	 "\n" +
	 "Your "+YEL+"Unseen Servant"+NORM+" spell encountered a "+HIR+"problem"+NORM+".\n" +
	 "The item you sent has been "+HIR+"lost"+NORM+": "+CYN+"cause unknown"+NORM+".\n\n");
	destruct(this_object());
	return 1;
  }

  if(failed)
  {
	tell_object(owner,
	 "\n"+
	 "Your "+YEL+"Unseen Servant"+NORM+" has "+HIR+"broken the spell!"+NORM+"\n" +
	 "The "+HIBLK+"trecherous servant"+NORM+" has "+HIR+"run away"+NORM+" with "+cargo->short()+"!\n\n");
	destruct(this_object());
	return 1;
  }

  if(destination == this_object())
  {
	tell_room(environment(owner),
	 "A chill runs down your spine when a shadowy figure rises from the ground.\n"+
	 "The ghostly figure gives something to "+ME+".\n"+
	 "It bows deeply to "+ME+" and then disappears into the ground.\n");

	/* calculate the legal value of the object */
	value = cargo->query_value();
	if(value > 1000) value = 1000+random(400);
	if(value > cargo->query_value()) value = cargo->query_value();

	tell_object(owner,
	 "Your "+YEL+"unseen servant"+NORM+" gives you "+HIG+value+NORM+" gold coins.\n");
	owner->add_money(value);
	destruct(cargo);
	destruct(this_object());
	return 1;
  }

  if(destination && environment(destination))
	move_object(this_object(), environment(destination));

  if(!destination ||
     !environment(destination) ||
     environment(destination)->realm() == "NT" ||
     environment(this_object()) != environment(destination))
  {
	tell_room(environment(owner),
	 "You feel a chill in your heart when a shadowy figure appears.\n"+
	 "The gives something to "+ME+" and then disappears.\n");

	tell_object(owner,
	 "The "+YEL+"unseen servent"+NORM+" was unable to complete the delivery.\n");

	if(transfer(cargo, owner))
	{
		tell_object(owner,  "You cannot carry the object.  Your servant places it on the ground.\n");
		transfer(cargo, environment(owner));
	}
	else
	{
		tell_object(owner, "The item has been returned to you.\n");
		transfer(cargo, owner);
	}
	destruct(this_object());
	return 1;
  }

  say(
   "A "+HIB+"chill"+NORM+" enters your heart when a "+HIBLK+"shadowy figure"+NORM+" rises from the ground.\n"+
   "The "+HIBLK+"Shade"+NORM+" points a long narrow finger at "+DEST+".\n",
   destination);

  tell_object(destination,
   "A "+HIB+"chill"+NORM+" enters your heart when a "+HIBLK+"shadowy figure"+NORM+" rises from the ground.\n"+
   "The "+HIBLK+"Shade"+NORM+" points a long narrow finger at "+HIW+"You"+NORM+"!\n" +
   "The dark figure whistpers to you: "+HIC+ME+" hass ssssent thissss to you.\n"+NORM);

  if(transfer(cargo, destination))
  {
	tell_object(destination,
	 "You cannot carry this much.  The "+cargo->short()+" is placed on the ground.\n");
	say(
	 "The "+HIBLK+"Shade"+NORM+" places something on the ground and "+CYN+"disappears"+NORM+".\n",
	 destination);
	transfer(cargo, environment(destination));
  }
  else
  {
	tell_object(destination,
	 "The "+HIBLK+"Shade"+NORM+" gives you: "+cargo->short()+" and then "+CYN+"disappears"+NORM+"\n");
	say(
	 "The "+HIBLK+"Shade"+NORM+" gives something to "+DEST+" and then "+CYN+"disappears"+NORM+".\n",
	 destination);
	transfer(cargo, destination);
  }

  tell_object(owner,
   "\n" +
   "Your "+YEL+"Unseen Servent"+NORM+" has completed it's task.\n" +
   cargo->short()+" has been delivered successfully.\n");

  destruct(this_object());
  return 1;

}


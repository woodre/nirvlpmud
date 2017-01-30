#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/pet.c";
inherit "obj/monster.c";

object owner;
int follow;
string follow_msg;
string mood;

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_follow(i){ follow = i; }
query_follow(){ return follow; }

set_follow_msg(str){ follow_msg = str; }
query_follow_msg(){ return follow_msg; }

set_mood(str){ mood = str; }
query_mood(){ return mood; }

do_khirstel()
{
  if(!owner)
  {
	destruct(this_object());
	return 1;
  }
  if(mood == "grinning")
  {
	tell_room(environment(this_object()), "Khirstel "+HIC+"giggles"+NORM+" inanely.\n");
	tell_object(owner, "You feel kind of giddy.\n");
  }
  else if(mood == "snarling")
  {
	tell_room(environment(this_object()),
	 "Khirstel issues a long deep "+HIR+"growl."+NORM+"\n" +
	 "The Khirstel "+HIR+"snaps"+NORM+" his jaws menacingly.\n");
  }
  else if(mood == "snoring")
  {
	tell_room(environment(this_object()), "Khirstel "+YEL+"snores"+NORM+" loudly.\n");
  }
  else if(mood == "smiling")
  {
	tell_room(environment(this_object()), "Khirstel "+HIY+"smiles"+NORM+" happily.\n");
	tell_object(owner, "You feel a little happier.\n");
  }
  else if(mood == "sniffing")
  {
	tell_room(environment(this_object()), "Khirstel "+HIB+"sniffs"+NORM+" around the room.\n");
  }
}


mood_shift()
{
  int x;

  if(!owner)
  {
	destruct(this_object());
	return 1;
  }

  x = random(6);
  if(x == 1){
	tell_room(environment(this_object()), "Khirstel winks at you and "+HIC+"grins"+NORM+".\n");
	mood = "grinning";
  } else if(x == 2){
	tell_room(environment(this_object()), "Khirstel "+HIR+"snarls"+NORM+" dangerously.\n");
	mood = "snarling";
  } else if(x == 3){
	tell_room(environment(this_object()), "Khirstel falls "+YEL+"asleep"+NORM+".\n");
	mood = "snoring";
  } else if(x == 4){
	tell_room(environment(this_object()), "Khirstel "+HIY+"smiles"+NORM+" happily.\n");
	mood = "smiling";
  } else if(x == 5){
	tell_room(environment(this_object()), "Khirstel "+HIB+"sneezes"+NORM+" loudly!\n");
	mood = "sniffing";
  }
}


kemote(str)
{
  if(tp == owner)
  {
	if(!str)
	{
		write("Khirstel Emote what?\n");
		say("Khirstel pees on "+OWN+"'s foot.\n", tp);
		return 1;
	}
	write("You do a khirstel emote:\n");
	tell_room(environment(this_object()),
	OWN+"'s Khirstel "+str+"\n");
	return 1;
  }
}


kdismiss()
{
  if(tp == owner)
  {
	write("You "+MAG+"dismiss"+NORM+" your Khirstel.\n");
	write("Khirstel gives you a big wet slobberly lick and disappears.\n");
	say(OWN+" dismisses the Khirstel.\n", tp);
	say("The Khirstel gives "+OWN+" a big wet slobberly lick and then waddles off.\n", tp);
	destruct(this_object());
	return 1;
  }
}


klook(str)
{
  object ob;
  string short;

  if(tp == owner)
  {
	if(!str)
	{
		write("Khirstel gives you a puzzled look.\n");
		return 1;
	}

	write("You "+HIW+"whistle"+NORM+" to Khristel and point "+HIY+str+NORM+".\n");
	command(str, this_object());

	if(environment(this_object()) == environment(this_player()))
	{
		write("Khirstel could not find anyway to go "+str+".\n");
		return 1;
	}

	say(OWN+" points and the Khirstel leaves "+str+".\n", tp);

	write(CYN+"~~~~~ You see through the Khirstel's eyes: ~~~~~\n"+NORM);
	call_other(environment(this_object()), "long", 0);
	ob = first_inventory(environment(this_object()));
	while(ob)
	{
		if(ob && ob != this_object())
		{
			short = call_other(ob, "short", 0);
			if(short) write(short + "\n");
		}
		ob = next_inventory(ob);
	}

	write(CYN+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"+NORM);
	move_object(this_object(), environment(this_player()));
	tell_room(environment(this_object()), "Khirstel waddles back in.\n");
	return 1;
  }
}


khir_attack()
{
  object obj;
  if(owner->query_attack() && !this_object()->query_attack())
  {
	obj = owner->query_attack();
	tell_room(environment(this_object()),
	  HIC+OWN+"'s Khirstel jumps into the battle!\n"+NORM);
	obj->set_can_kill(1);
	this_object()->set_can_kill(1);
	this_object()->attack_object(obj);
	this_object()->attack_object(obj);
  }
}


khir_stopattack()
{
  object obj;

  obj = this_object()->query_attack();

  if(obj && obj->query_npc() && mood != "snarling")
  {
	tell_room(environment(this_object()),
	  CYN+"Khirstel appears to get bored and leaves the fight.\n"+NORM);
	if(obj->query_attack() == this_object())
	{
		obj->stop_fight();
		obj->stop_fight();
		obj->stop_hunter();
	}
	this_object()->stop_fight();
	this_object()->stop_fight();
	this_object()->stop_hunter();
  }
}


kkick(str)
{
  int x;

  if((str == "khirstel") && (tp == owner))
  {
	x = random(100);
	write("You kick Khirstel.\n");
	say(OWN+" kicks Khirstel.\n", tp);
	if(x < 29)
	{
		tell_room(environment(this_object()), "The poor khirstel wimpers and crawls away.\n");
		write("Now don't you feel like a big bully?\n");
		destruct(this_object());
		return 1;
	}
	else if(x > 69)
	{
		tell_room(environment(this_object()),
		 "The khirstel gets really upset and chews a hole in "+OWN+"'s boot!\n" +
		 "Khirstel snarls dangerously.\n");
		mood = "snarling";
		return 1;
	}
	return 1;
  }
}


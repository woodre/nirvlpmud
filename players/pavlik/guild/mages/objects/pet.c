#include "/players/pavlik/guild/mages/defs.h"
#define PET capitalize(this_object()->query_name())

object owner;		/* who do we belong to? */
int follow;
string follow_msg;

query_pet(){ return 1; }
query_mage_pet(){ return 1; }

set_owner(ob){ owner = ob; }
query_owner(){ return owner; }

set_follow(i){ follow = i; }
query_follow(){ return follow; }

set_follow_msg(str){ follow_msg = str; }
query_follow_msg(){ return follow_msg; }


pet_follow()
{
  if(!owner || !environment(owner))
  {
	destruct(this_object());
	return 1;
  }

  if(!follow_msg) follow_msg = "wanders";
  if(follow && environment(this_object()) != environment(owner))
  {
	tell_room(environment(this_object()),
	  capitalize(this_object()->query_name())+" "+follow_msg+" out.\n");
	move_object(this_object(), environment(owner));
	tell_room(environment(this_object()),
	  capitalize(this_object()->query_name())+" "+follow_msg+" in following "+OWN+".\n");
  }
}


pet_give(str)
{
  string who, what, s;
  object obj, ob, next_ob;
  int weight;

  if(!str)
  {
	write(PET + " gives you a puzzled look.\n");
	if(tp->query_level() > WIZLEVEL) write("no str");
	return 1;
  }
  if(str == "all" || str == "everything")
  {
	str = "all to " + tp->query_real_name();
  }
  if(sscanf(str, "%s to %s", what, who) !=2 )
  {
	write(PET + " gives you a puzzled look.\n");
	if(tp->query_level() > WIZLEVEL) write("bad sscanf");
	return 1;
  }

  if(what == "all" || what == "everything")
	ob = first_inventory(this_object());
  else
	ob = present(what, this_object());

  obj = present(who, environment(this_object()));

  if(!ob || !obj || !living(obj))
  {
	write(PET + " gives you a puzzled look.\n");
	if(!ob && tp->query_level() > WIZLEVEL) write("bad ob");
	if(!obj && tp->query_level() > WIZLEVEL) write("bad obj");
	if(!living(obj) && tp->query_level() > WIZLEVEL) write("not living obj");
	return 1;
  }

  while(ob)
  {
	s = ob->short();
	if(what == "all" || what == "everything")
		next_ob = next_inventory(ob);

	if(ob->drop() == 1)
	{
		write("You discover that "+PET+" cannot drop "+s+".\n");
		ob = 0;
	}
	else if(!ob->get())
	{
		write(capitalize(who)+" is unable to take "+s+".\n");
		ob = 0;
	}
	else if(!obj->add_weight(ob->query_weight()))
	{
		write(IT+" cannot carry anymore.\n");
		ob = 0;
		return 1;
	}
	else {
		this_object()->add_weight(-(ob->query_weight()));
		move_object(ob, obj);
		tell_object(obj, PET+" gives you "+s+"\n");
		say(PET+" gives "+s+" to "+IT+".\n", obj);
	}

	if(what == "all" || what == "everything")
		ob = next_ob;
	else
		ob = 0;
  }

  return 1;

}


pet_get(str)
{
  string what, container;
  string s;
  object obj, ob, next_ob;
  int weight;

  if(!str)
  {
	write(PET + " gives you a puzzled look.\n");
	if(tp->query_level() > WIZLEVEL) write("no str");
	return 1;
  }
  if(sscanf(str, "%s from %s", what, container) == 2) {
	obj = present(container, this_object());
	if(!obj) obj = present(container, environment(this_object()));

	if(!obj)
	{
		write(PET + " gives you a puzzled look.\n");
		if(tp->query_level() > WIZLEVEL) write("no container obj");
		return 1;
	}
	if(!obj->can_put_and_get())
	{
		write(PET + " gives you a puzzled look.\n");
		if(tp->query_level() > WIZLEVEL) write("container not put_and_get");
		return 1;
	}

	if(what == "all" || what == "everything")
		ob = first_inventory(obj);
	else
		ob = present(what, obj);

	if(!ob)
	{
		write(PET + " gives you a puzzled look.\n");
		if(tp->query_level() > WIZLEVEL) write("no ob in container");
		return 1;
	}
  }
  else if(str == "all" || str == "everythng")
  {
	what = "all";
	ob = first_inventory(environment(this_object()));
  }
  else
  {
	what = str;
	ob = present(what, environment(this_object()));
	if(!ob)
	{
		write(PET + " gives you a puzzled look.\n");
		if(tp->query_level() > WIZLEVEL) write("bad ob");
		return 1;
	}
  }

  while(ob)
  {
	s = ob->short();
	if(what == "all" || what == "everything")
		next_ob = next_inventory(ob);

	if(!ob->get())
	{
		ob = 0;
	}
	else if(!this_object()->add_weight(ob->query_weight()))
	{
		write(PET+" cannot carry anymore.\n");
		ob = 0;
		return 1;
	}
	else {
		move_object(ob, this_object());
		if(obj)
		{
			say(PET+" takes "+s+" from "+container+".\n");
			obj->add_weight(-(ob->query_weight()));
		}
		else
		{
			say(PET+" takes "+s+"\n");
		}
	}

	if(what == "all" || what == "everything")
		ob = next_ob;
	else
		ob = 0;
  }

  return 1;

}


pet_drop(str)
{
  object ob, next_ob;

  if(!str)
  {
	write(PET + " gives you a puzzled look.\n");
	if(tp->query_level() > WIZLEVEL) write("no str");
	return 1;
  }
  if(str == "all" || str == "everything")
  {
	ob = first_inventory(this_object());
  }
  else
  {
	ob = present(str, this_object());
	if(!ob)
	{
		write(PET + " gives you a puzzled look.\n");
		if(tp->query_level() > WIZLEVEL) write("bad ob");
		return 1;
	}
  }

  while(ob)
  {
	next_ob = next_inventory(ob);
	if(!ob->drop())
	{
		if(ob->query_weight())
			this_object()->add_weight(-(ob->query_weight()));
		move_object(ob, environment(this_object()));
		say(PET+" drops "+ob->short()+"\n");
	}
	ob = next_ob;
  }

  return 1;
		
}



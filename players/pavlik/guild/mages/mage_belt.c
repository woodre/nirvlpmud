inherit "obj/armor";
#include "/players/pavlik/guild/mages/macs2"

#define BASE_CAPACITY 20
#define RANK_CAPACITY 2

object owner;
int capacity;
mapping components;

reset(arg){
  ::reset(arg);
  set_short("Mage Belt");
  set_arm_light(0);
  set_ac(1);
  set_weight(1);
  set_value(0);
  set_alias("mage_belt");
  set_name("Mage Belt");
  set_type("belt");
  set_save_flag(1);
  set_long("Mage Belt\n");
  set_silently(1);
  components = ([]);
}

init() {
  ::init();
  if(environment() && environment()->is_player()) {
	if(environment()->query_level() < 20 && environment()->query_guild_name() != "mage") {
		tell_object(environment(), "This belt is not for you.\n");
		destruct(this_object());
		return 1;
	}
	else {
		owner = environment();
	}

	/* increase AC value for higher guild ranks */
	if(environment()->query_guild_rank() > 50) {
		set_ac(2);
	}

	if(!query_worn()) {
		wear("mage_belt");
	}

	add_action("test_add_component", "t_add");
	add_action("test_query_component", "t_query");
  }
}

short() {
  string str;
  int i;
  if(!owner) return "An old useless belt";
  i = owner->query_guild_rank();
  if(i < 1) return "An old useless belt";
  else if(i < 11) str = YEL+"An Apprentice Magician's Belt"+NORM;
  else if(i < 21) str = YEL+"A Journeyman Magician's Belt"+NORM;
  else str = YEL+"A Master Sorcerer's Belt"+NORM;
  if(query_worn()) str = str + " (worn)";
  return str;
}

long() {
  string *c;
  int total;
  int i;

  write(
    "Another requirement of a life "+MAG+"devoted to magic"+NORM+" is the need for various\n" +
    CYN+"spell components"+NORM+" and "+CYN+"devices"+NORM+".  For this reason you are "+HIW+"never without"+NORM+" this\n" +
    "belt of which numerous pockets, pouches and bags are adorned.\n");

  c = keys(components);

  if(sizeof(c) < 1) {
	write("Your belt currently holds no spell components. (Capacity: "+query_max_capacity()+")\n\n");
  }
  else {
	write("Your belt contains the following spell components :\n\n");
	for(i=0; i<sizeof(c); i++) {
		string name;
		int x;
		name = PAV->get_component_name(c[i]);
		x = 28 - strlen(name);
		write("     " + name + " ");
		while(x > 0) {
			write (".");
			x--;
		}
		write(" " + components[c[i]] + "\n");
		total += PAV->get_component_weight(c[i]) * components[c[i]];
	}
	write("\n");
	write("Belt Capacity: "+total+"/"+query_max_capacity()+"\n\n");
  }

  return 1;
}

test_add_component(string str) {
  string id;
  int i;
  sscanf(str, "%s %d", id, i);
  add_component(id, i);
  return 1;
}

test_query_component(string str) {
  if(!components[str])
	write("The component '"+str+"' is not present.\n");
  else
	write("Component '"+str+"': " + components[str] + "\n");
  return 1;
}

add_component(string id, int qty) {
  if(components[id]) components[id] += qty;
  else components[id] = qty;
  if(components[id] <= 0) components = m_delete(components, id);
}

query_component(string id) {
  if(components[id]) return components[id];
  else return 0;
}


query_capacity() {
  string *c;
  int i;
  int total;

  c = keys(components);
  for(i=0; i<sizeof(c); i++) {
	total += PAV->get_component_weight(c[i]) * components[c[i]];
  }

  return total;
}

query_max_capacity() {
  if(!owner) return 0;
  return BASE_CAPACITY + (owner->query_guild_rank() * RANK_CAPACITY);
}

set_owner(obj) { owner = obj; }
query_owner() { return owner; }

/*
 * this armor object cannot be removed by players
 */
remove(str) {
  if(id(str)) {
	if(this_player()->query_level() > 19) {
		::remove(str);
		return 1;
	}
	write("You would not dare remove your Mage's belt.\n");
	return 1;
  }
}

drop() { return 1; }
get() { return 1; }


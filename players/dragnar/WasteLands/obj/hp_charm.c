int active;

id(string str) {
   return str == "charm" || str == "hp_regen_object";
}
short() {
	return "A Health Charm";
}

long() {
	write(active ? "Good for staying alive.\n": "It can be activated.\n");
}

reset(arg){
  if(arg) return;
}

init() {
  add_action("Activate","activate");
}

int query_hp_regen()
{
  return active ?10 : 0;
}

Activate() {
  active = 1;
  write("Active\n");
}

get() { return 1; }

drop() { return 0; }

query_save_flag() { return active ? 1 : 0; }

query_weight() { return 1; }

query_value() { return 60000; }

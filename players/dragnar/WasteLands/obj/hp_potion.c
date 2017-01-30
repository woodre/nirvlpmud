int active;

id(string str) {
   return str == "potion" || str == "generic_hp_bonus";
}
short() {
	return "A Health Charm";
}

long() {
	write("Good for staying alive.\n");
}

reset(arg){
  if(arg) return;
}

init() {
  add_action("Activate","activate");
}

int gen_hp_bonus()
{
  return ? active 100 : 0;
}

Activate() {
  active = 1;
  write("Active\n");
}

get() { return 1; }

drop() { return 0; }

query_save_flag() { return ? active 1 : 0; }

query_weight() { return 1; }

query_value() { return 60000; }
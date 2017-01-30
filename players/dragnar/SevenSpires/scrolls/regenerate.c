id(string str) {
   return str == "scroll" || str == "hp_regen_object";
}
short() {
	return "A Scroll of Regeneration";
}

long() {
	write("Good for staying alive.\n");
}

reset(arg){
  call_out("time_out",60);
  if(arg) return;
}

int query_hp_regen()
{
  return 10+random(15);
}

time_out() {
  if( environment() )
    tell_object( environment(), "The scroll crumbles into dust and you feel weakened.\n");
  destruct(this_object());
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

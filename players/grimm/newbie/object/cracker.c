inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A salted Cracker");
set_long("This is a very stale salted cracker.\n");
set_weight(1);
set_alias("cracker");
set_id("cracker");
set_value(3);
}

init() {
  add_action("eat","eat");
}

eat(str) {
  if(!str) { write("What do you want to eat?\n"); return 1; }
  if(str!="cracker") return;
  write("The cracker is very dry but feels wholesome.\n");
  this_player()->add_hit_point(2);
  destruct(this_object());
  return 1;
}

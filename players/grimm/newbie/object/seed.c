inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A sunflower seed");
set_long("This is a rather large sunflower seed.\n");
set_weight(1);
set_alias("seed");
set_id("seed");
set_value(4);
}

init() {
  add_action("eat","eat");
}

eat(str) {
  if(!str) { write("What do you want to eat?\n"); return 1; }
  if(str!="seed") return;
  write("You crack the seed open and eat its contents.\n");
  this_player()->add_hit_point(3);
  destruct(this_object());
  return 1;
}

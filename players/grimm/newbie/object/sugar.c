inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A packet of sugar");
set_long("This is a packet of sugar.\n");
set_weight(1);
set_alias("packet");
set_id("sugar");
set_value(2);
}

init() {
  add_action("eat","eat");
}

eat(str) {
  if(!str) { write("What do you want to eat?\n"); return 1; }
  if(str!="sugar") return;
  write("The sugar is very sweet and tastes good.\n");
  this_player()->add_hit_point(2);
  destruct(this_object());
  return 1;
}

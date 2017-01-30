id(str) { return str == "guts"; }
short() { return "Fish guts"; }
long() {
  write("This appears to tuna fish meat. Tuna is very healthy for you.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 1000; }

init() {
  add_action("eatme","eat");
}

eatme(str) {
  if(!str || str!="guts") return 0;
    if(!this_player()->eat_food(5)) {
      write("You don't feel like eating that much right now.\n");
      return 1;
    }
  this_player()->heal_self(20);
  this_player()->add_weight(-1);
  write("You viciously devour the tuna.\n");
  say((this_player()->query_name())+" eats some fish guts.\n");
  destruct(this_object());
  return 1;
}

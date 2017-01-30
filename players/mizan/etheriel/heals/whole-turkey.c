id(str) { return str == "turkey"; }
short() { return "A turkey"; }
long() { write("This is a HUGE oven-baked turkey.\n"); }
init() { add_action("eat","eat"); }
query_weight() { return 4; }
query_value() { return 1000; }
get() { return 1; }
eat(str) {
  if(!str) return 0;
  if(str != "turkey") return 0;
    this_player()->eat_food(16);
    write("Like a barbarian, you devour the turkey with reckless abandon.\n");
    say((this_player()->query_name())+" eats an ENTIRE turkey.\n");
   this_player()->heal_self(50);
  destruct(this_object());
   return 1; 
}

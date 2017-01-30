/*
 * Standard Stuffed heal: 2 charges, Heal 20+random(40), Stuffed 7
 */

int bites;
 
id(str) { 
  return str == "chicken leg" || str == "chicken" || str == "leg";
}
 
reset(arg) {
  if(arg) return;
  bites = 1+random(3);
}
 
long() {
  write(
  "A large chicken leg.  Most of the meat has already been stripped\n"+
  "away but it looks like you could find a little more to eat on the\n"+
  "bone.\n");
  return;
}

short() { return "A chicken leg (cooked)"; }

query_value() { return 10; }

get() { return 1; }
 
query_weight() { return 1; }
 
query_save_flag() { return 1; }
 
is_heal() { return "stuffed"; }
query_potence() { return 50; }
 
init() {
  add_action("eat_chicken","eat");
}

eat_chicken(str) {
  if(id(str)) {
    if(!this_player()->eat_food(7)) {
       return 1;
    }
    write("You gnaw some meat of the chicken leg.  The soft meat tastes good!\n");
    say(capitalize(this_player()->query_name())+" strips some meat from a chicken leg.\n");
    this_player()->heal_self(20+random(40));

    bites--;

    if(!bites) {
      write("You finish the meat and toss the bone.\n");
      this_player()->add_weight(-1);
      destruct(this_object());
      return 1;
    }

    return 1;
  }
}
 

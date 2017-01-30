
/*
 * BEER (4/25/94)
 * Cloned in /players/molasar/rowan/drake/bar.c
 */

id(str) { return str == "beer" || str == "bottle"; }

init() {
  add_action("drink", "drink");
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 10; }    

short() { return "A bottle of beer"; }

long() {
   write("Although the small cask seems somewhat decayed and in less\n");
   write("than perfect shape the beer looks good.\n");
}

drink(str) {
    if(str && str != "beer" && str != "from bottle")
      return 0;
    if(!call_other(this_player(), "drink_alcohol", 4))
      return 1;
    this_player()->heal_self(10);
    write("It is really good beer!\n");
    say(this_player()->query_name()+" drinks a bottle of beer.\n");
    destruct(this_object());
    return 1;
}


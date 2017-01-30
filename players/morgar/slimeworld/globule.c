id(str) { return str=="globule" || str == "slime"; }

#ifndef __LDMUD__ /* Rumplemintz */
init() { add_action("eat"); add_verb("eat"); }
#else
void init() { add_action("eat", "east"); }
#endif

long() { write("A small globule of acidic slime.  It does, however smell nice.\n"); }

short() { return "A slime globule"; }

query_value() { return 200; }

get() {
    return 1;
}

query_weight() {
    return 1;
}

query_name() {
   return "globule";
}

eat(str) {
   if(present(str, this_player()) != this_object()) {
      notify_fail("Eat what?\n"); return 0; }
    write("You eat the globule, and are healed somewhat.\n");
    call_other(this_player(), "heal_self", 15);
    move_object(this_object(), "players/morgar/store");
    return 1;
}

/*
get() {
    write("The acid burns you a little, but you take the globule.\n");
    call_other(this_player(), "heal_self", -15);
    return 1;
}
*/

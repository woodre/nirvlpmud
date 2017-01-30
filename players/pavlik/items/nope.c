/*
 * This object keeps a player from using a specified name
 * in any commands.
 */

string who;

reset(arg) {
  who = "worm";
}

short() { return; }

long() {
  write("nope.\n");
  return;
}

id(str) { return (str == "nope" || str == "noway"); }

set_who(str){ who = str; }
query_who(){ return who; }

init() {
#ifndef __LDMUD__
  add_action("nope"); add_xverb("");
#else
  add_action("nope", "", 3);
#endif
}

nope(str) {
  string crap1, crap2;

  /* keep moving to player to keep at top of inventory */
  move_object(this_object(), environment(this_object()));

  if(sscanf(str, "%s"+who+"%s", crap1, crap2)==2 ||
     str == who) {
     write("Nope!\n");
     return 1;
  }
}
 
get() { return 1; }
drop(){ return 1; }
query_weight() { return 0; }
query_value() { return 0; }


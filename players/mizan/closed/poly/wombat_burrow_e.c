#define MORPH_ID "Mizan-morph-object"
#define WOMBAT_BURROW "players/mizan/closed/poly/wombat_burrow"
#define DEATHTIME 2000

reset(arg) {
  if(!arg) call_out("fill_in", DEATHTIME);
}

fill_in() {
  if(environment(this_object()))
    tell_room(environment(this_object()), "A hole suddenly disappears.\n");
  destruct(this_object());
  return 1;
}



string owner;

id(str) { return str == "burrow" || str == "hole"; }
short() { return "A hole in the ground, made by " + owner; }

set_owner(str) { owner = str; }
query_owner() { return owner; }

long() {
  if(owner && this_player()->query_real_name() == owner)
  write("This is a hole that you dug recently.\n"+
  "Perhaps you can 'enter' it. \n");
}

init() {
  add_action("enterme","enter");
}

enterme(str) {

  object burrow,mob;
  if(!str || str != "hole" || this_player()->query_real_name() != owner) return 0;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  burrow = mob->query_burrow();
  if(!burrow) {
    burrow=clone_object(WOMBAT_BURROW);
    burrow->set_owner(this_player()->query_real_name());
    mob->set_burrow(burrow);
  }
  write("You dive headfirst into the hole and make your way to your burrow.\n");
  this_player()->_say((this_player()->query_name()) + " dives into the hole and disappears.\n");
  move_object(this_player(), burrow);
  this_player()->say((this_player()->query_name()) + " tumbles in.\n");
  return 1;
}



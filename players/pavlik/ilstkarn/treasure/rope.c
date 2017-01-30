#define ME capitalize(this_player()->query_name())

/*
 * A piece of rope, which if attached to the spiked ball from the
 * Rock Dragon, will create the Rockbreaker weapon.
 */

reset(arg){
  if(arg) return;
}

id(str){
  return str == "rope" || str == "frayed rope" || str == "frayed_rope";
}

long(){
  write(
  "A short length of rope that is frayed at one end.  The rope is about 5 feet\n"+
  "long and would only be useful if it was Attached to something.\n");
  return;
}

short(){
  return "A frayed rope";
}

get() {
  return 1;
}

query_weight() {
  return 1;
}

query_value() {
  return 5;
}

init() {
  add_action("attach","attach");
  add_action("attach","tie");
}

attach(str) {
  if(str == "rope to ball" || str == "rope to spiked ball" || str == "ball to rope" ||
  str == "spiked ball to rope" || str == "ball" || str == "spiked ball") {

    if(!present("rock_dragon_tail", this_player())) {
      return 0;
    }

    write(
    "You tie the short length of rope around the heavy spiked ball.\n"+
    "Although the grip is somewhat awkward, the items combine to make a\n"+
    "rather deadly weapon!\n");
    move_object(clone_object("players/pavlik/ilstkarn/weapons/rockbreaker"),
    this_player());
    destruct(present("rock_dragon_tail", this_player()));
    destruct(this_object());
    this_player()->add_weight(-5);

    return 1;
  }
}



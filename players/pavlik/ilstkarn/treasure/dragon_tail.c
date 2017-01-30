#define ME capitalize(this_player()->query_name())

/*
 * Spiked tail from rock_dragon.  Used to create Rockbreaker weapon.
 */

reset(arg){
  if(arg) return;
}

id(str){
  return str == "ball" || str == "spiked" || str == "spiked ball" ||
  str == "rock_dragon_tail";
}

long(){
  write(
  "This massive chunk of spiked stone used to belong on the tail of a Rock Dragon\n"+
  "The dangerous Rock Dragon would swing its club-tipped tail at its foe, causing\n"+
  "mortal injuries.  If you could find something to Attach this spiked ball to,\n"+
  "maybe you could cause havoc with it too...\n");
  return;
}

short(){
  return "A Spiked Ball";
}

get() {
  return 1;
}

query_weight() {
  return 4;
}

query_value() {
  return 50;
}


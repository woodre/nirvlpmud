#define TO this_object()
#define ENV environment
#define ENVTO environment(this_object())

id(str) { return str == "stun_blow"; }
get() { return 1; }
drop() { return 1; }

init() {
#ifndef __LDMUD__
  add_action("stun_move"); add_xverb("");
#else
  add_action("stun_move", "", 3);
#endif
}

destruct_stun(num) {
  string dmess;
  dmess = "You have overcome the effects of the stunning blow.\n";
  if(!num) {              
    tell_object(ENVTO, dmess);
    tell_room(ENV(ENVTO), capitalize(ENV()->query_real_name())+" shakes off the stun.\n");
    destruct(TO); return 1; }
  call_out("destruct_stun", num);
  return 1;
}

stun_move(str) {
  if(ENVTO) {
    if(living(ENVTO)) {     
      if(str == "north" || str == "south" || str == "east" ||
         str == "west" || str == "up" || str == "down" ||
         str == "in" || str == "out" || str == "northwest" ||
         str == "southwest" || str == "northeast" ||
         str == "southeast" || str == "exit" || str == "leave") {
      write("Your stunned body cannot move!\n");
      return 1;
      }
    }
  }
}

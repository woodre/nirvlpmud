#define TO this_object()
#define ENV environment
#define ENVTO environment(this_object())

id(str) { return str == "frozen"; }
get() { return 1; }
drop() { return 1; }

init() {
#ifndef __LDMUD__
  add_action("stun_move"); add_xverb("");
#else
add_action("stun_move","",3);
#endif
}

destruct_stun(num) {
  string dmess;
  dmess = "You are no longer frozen.\n";
  if(!num) {              
    tell_object(ENVTO, dmess);
    destruct(TO); return 1; }
  call_out("destruct_stun", num);
  return 1;
}

stun_move(str) {
  if(ENVTO) {
    if(living(ENVTO)) {     
      if(ENVTO->query_level() < 20) {
      write("Your frozen body cannot move!\n");
      return 1;
      }
    }
  }
}

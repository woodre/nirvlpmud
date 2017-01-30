id(str) { return str == "torch"; }
long() {
   write("A blazing torch.  It is secured to the wall.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("torch",40);
}

torch() {
tell_room(environment(this_object()),
 "The torch flickers softly, casting strange shadows across the room.\n");
   call_out("torch",40);
   return 1;
}

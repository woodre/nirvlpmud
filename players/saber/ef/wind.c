id(str) { return str == "wind"; }
long() {
  write("A savage wind.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("wind",20);
}

wind() {
tell_room(environment(this_object()),
   "The wind howls savagely as it passes by, chilling you to the bone.\n");
call_out("wind",20);
   return 1;
}

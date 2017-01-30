id(str) { return str == "breeze"; }
long() {
  write("A gentle breeze.\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 100;
}

reset(arg) {
   if(arg) return;

call_out("breeze",20);
}

breeze() {
tell_room(environment(this_object()),
   "The breeze tugs gently at your hair.\n");
call_out("breeze",random(200) + 25);
   return 1;
}

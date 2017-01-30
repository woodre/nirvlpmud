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
if(!environment(this_object())) return 1;
tell_room(environment(this_object()),
   "The breeze tugs gently at your hair.\n");
call_out("breeze",20);
   return 1;
}

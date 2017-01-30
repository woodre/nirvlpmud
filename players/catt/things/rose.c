id(str) { return str == "rose"; }
get() { return 1; }
short() { return "A small red rose"; }
long() {
write("A beautiful rocky mountain red rose from the northern reaches.\n" +
      "It is a rare beauty, not unlike it's intended possessor. Handle\n" +
      "it carefully for something such as this, like love, is often fragile\n"+
      "and can break easily. Smile for this token was given in love.\n");
return 1; }
reset(arg) {
  if(arg) return;
}
init() {
add_action("beam","beam");
   add_action("frown","frown");
}
beam() {
if(this_player()->query_real_name() == "wendy") {
write("The rose blooms with love and tenderness.\n");
say("The red rose from the northern reaches blooms\n" +
     "with love and tenderness towards its mistress\n");
}}
frown() {
if(this_player()->query_real_name() == "wendy") {
write("The rose wilts and weeps for it's mistresses sorrow.\n");
shout("The rose wilts and weeps for it's mistresses sorrow\n");
destruct(this_object());
}}

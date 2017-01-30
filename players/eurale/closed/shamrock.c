#define TP this_player()
#include "/players/eurale/closed/ansi.h"

id(str) { return str == "shamrock"; }

reset() {}

long() { write(
  "This magical shamrock can do a number of things.  It can:\n"+
  "    a.  heal\n"+
  "    b.  teleport back to test room  (test)\n"+
  "    c.  change login to test room (login)\n"); }

short() { return HIG+"A shamrock"+NORM; }

init() {
  add_action("heal","heal");
  add_action("drop_object","drop");
  add_action("go_testroom","test");
  add_action("change_login","login");
}


heal(arg) {
  write("You heal yourself.\n");
  call_other(this_player(),"heal_self",600);
  return 1; }

get() { return 1; }

query_weight() { return 0; }

query_value() { return 5000; }

drop_object(str) {
write("The shamrock disappears.\n");
destruct(this_object());
return 1; }

go_testroom() {
  write("You close your eyes and fly to the testroom!\n");
  TP->move_player("in a cloud of dust#players/eurale/testroom.c");
  return 1; }

change_login() {
if(TP->query_real_name() == "euboy") {
  TP->set_home("/players/eurale/testroom.c");
  TP->save_me();
  return 1; }
else {
  write("You try to change your login but fail miserably!\n");
  return 1; }
}

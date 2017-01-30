#include "room.h"

object army,ob;

int is_pass;
int is_key;
#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
     is_pass = 1;
is_key = 1;
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/burns.c");
      transfer(army, this_object());
  army = clone_object("players/hawkeye/monster/hotlips.c");
move_object(army,this_object());
}
    }
ONE_EXIT("/players/hawkeye/room/mess.c", "east",
       "Officer's Club",
"This is the Officer's Club of the 4077th. Don't let the name \n" +
"fool you, this club allows enlisted men also. You should be\n" +
"safe for now\n",1)
init() {
    ::init();
add_action("search","search");
add_action("ask","ask");
}
ask(str) {
if(!str) {
write("Ask What?\n");
return 1;}
if(str == "burns") {
write("Why are you bothering my you little puke. If you want something look\n" +
"around. It's here somewhere.\n");
write("Rose is the one you need to talk too for real help.\n");
return 1;
}
}
/*
search() {
object pass;
if(present("burns",environment(this_player()))) {
write("Major Burns will not let you search.\n");
return 1;
}
else {
if(is_pass) {
write("Searching around, you find a tattered pass, it is well worn but\n" +
"should do the trick.\n");
pass= clone_object("players/hawkeye/quest/hqpass.c");
move_object(pass,this_player());
 }
if(!is_pass) write("You find nothing special.\n");
is_pass = 0;
return 1;
}
}
*/

search() {
if(present("burns")) {
  write("Major Burns will not let you search.\n");
  return 1; }
else {
 if(is_key) {
   write("Searching around, you find a small rusty key.\n");
   move_object(clone_object("players/hawkeye/quest/key.c"),
      this_player());
   is_key = 0;
   return 1; }
 if(!is_key) {
   write("You find nothing special.\n");
   return 1; }
return 1; }
}

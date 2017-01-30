/*
Brittany's Castle 
Created: 1-21-00
*/

#define DEST "/room/forest8.c"
#define KADATH "/players/brittany/kadath/kadath1.c"

void reset(int arg) {
  move_object(this_object(), DEST);
  /* Autoloads here */

  /******************/

  /* Quest Objects  */

  /******************/
}

int id(string str) {
  return str=="globe";
}

string short() {
  return "NeTHerLand Globe";
}

void long() {
  write("Put your description here.\n");
}

void init() {
  add_action("cmd_spin","spin");
}

cmd_spin(str) {
  if(!str) {
    notify_fail("Spin what?\n");
    return 0;
  }
  if(str=="globe to kadath") {
    write("You spin the globe to kadath blah blah blah.\n");
    say(this_player()->query_name()+" spins the globe to kadath and then disappears.\n");
    move_object(this_player(),KADATH);
    return 1;
  }
/* Repeat this if statement for each new area
  if(str=="globe to inferno") {
    write("You spin the globe to inferno blah blah blah.\n");
    say(this_player()->query_name()+" spins the globe to inferno and then disappears.\n");
    move_object(this_player(),INFERNO);
    return 1;
  }
*/

  write("Spin globe to where?\n");
  say(this_player()->query_name()+" looks confused.\n");  
  return 1;
}

int is_castle() { return 1; }
 
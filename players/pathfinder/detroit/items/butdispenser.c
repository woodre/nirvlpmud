id(str) { return str == "dispenser"; }
 
short() { return "A button dispenser"; }
 
long() {
  write("This machine dispenses buttons of the City of Detroit.  These are\n"+
        "free so take one and pass it around.  Just 'push button' to get one.\n");
       }
       
query_weight() { return 10000; }
 
get() { return 1; }
init() {
  add_action("push_button", "push");
  }
  
push_button(str) {
  object ob;
  if(!str || str != "button") {
    write("You push the machine in vain.\n");
    say(capitalize(this_player()->query_name())+" pushes the machine in vain.\n");
    return 1;
    }
  write("You push the button to the machine and hear something hit the\n");
  write("dispenser tray.  You pick up the button and put it on your shirt.\n");
  say(capitalize(this_player()->query_name())+" pushes the button, reaches in the tray\n");
  say("and pins a button of the City of Detroit to their shirt.\n");
  ob = clone_object("players/pathfinder/detroit/items/button");
  move_object(ob, this_player());
  return 1;
}

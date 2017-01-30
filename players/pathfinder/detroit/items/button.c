inherit "obj/treasure";
 
id(str) { return str == "button" || str == "pin"; }
 
short() {
  return "A pretty little button of Detroit";
  }
  
long() {
  write("A Pretty little button of Detroit(the good parts).  Along with a\n");
  write("sign which says 'push button' to hear the sounds of Detroit.  You\n");
  write("can pin a button on someone else by 'pin <person>'.\n");
  }
 
get() { return 1; }
  
drop () {destruct(this_object()); write("The button turns to ashes as it hits the ground.\n"); return 1; }
init() {
  add_action("push_it", "push");
  add_action("pin_someone", "pin");
  }
  
push_it(str) {
  if(!str || str != "button") {
    write("You try to push and fail.\n");
    say(capitalize(this_player()->query_name())+" pushes vainly at nothing and falls\n");
    say("flat on their face!\n");
    return 1;
    }
  write("You push the button valiantly as bullets start spraying out of the button\n");
  write("heading at everyone in the room as they scurry for cover.  You smile\n");
  write("biggly in pride.\n");
  say(capitalize(this_player()->query_name())+" pushes their button valiantly.\n");
  say("You scurry for cover as bullets start wizzing by your head in a blindingly\n");
  say("fast way.  As you get up from your cover you notice a big wet spot from\n");
  say("where your fear overcame you.\n");
  return 1;
}
 
pin_someone(str) {
  object plyr,ob;
  
  if(!str) {
    write("Pin it on someone!\n");
    say(capitalize(this_player()->query_name())+" tries to pin a button on thin air!\n");
    return 1;
    }
  plyr=find_living(str);
  if(!plyr) {
    write("You can't pin a button on yourself!\n");
    return 1;
  }
  if(!environment(this_player())) {
    write(capitalize(str)+" is not in the room.\n");
    say(capitalize(this_player()->query_name())+" tries to pin a pin onto someone that isn't here!\n");
    return 1;
    }
if(present("button",plyr)) {
  write(capitalize(str)+" already has a button.\n"); return 1; }
  write("You proudly pin a button of Detroit on "+capitalize(str)+".\n");
  say(capitalize(this_player()->query_name())+" proudly pins a button of Detroit on "+capitalize(str)+".\n");
  ob=clone_object("players/pathfinder/detroit/items/button");
  move_object(ob,plyr);
  return 1;
}


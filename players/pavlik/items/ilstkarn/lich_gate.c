#include <ansi.h>
#define ME capitalize(this_player()->query_name())

string *names;

reset(arg){
 if(arg) return;
 names = ({ });
}

id(str){
  return str == "gate" || str == "dimensions gate" || str == "lich_gate" ||
  str == "through gate" || str == "into gate" || str == "in gate";
}

short(){
  return "Dimensions Gate (open)";
}

long(){
  write(
  "The Dimensions Gate is a magical gateway to the world.  The enchanted\n"+
  "portal appears to be only a shimmering pool of light on the wall.  If\n"+
  "you step through the gate it will return you to the surface world.\n");
  return;
}

clean_up() { return 0; }
query_weight() { return 999; }
query_value() { return 0; }
get() { return 0; }

add_name(i) { names += ({ i }); }
remove_name(i) { names -= ({ i }); }
query_names() { return names; }

init(){
 add_action("enter","enter");
 add_action("enter","step");
}

enter(str) {
  if(id(str)) {
    if(!present("lancoz_lich", environment(this_object())) ||
    this_player()->query_ghost()) {
      write("You step into the Dimensions Gate.\n");
      say(ME+" steps into the Gate of Dimensions.\n");
      move_object(this_player(), "players/pavlik/ilstkarn/path"+random(9));
      command("look", this_player());
      return 1;
    }
    else {
      string myname;
      int i;
      myname = this_player()->query_real_name();
      for(i=0; i<sizeof(names); i++) {
        if(names[i] == myname) {
          write("The Lich sneers at you and steps aside.\n");
          write("You step into the Dimensions Gate.\n");
          say(ME+" steps into the Gate of Dimensions.\n");
          move_object(this_player(), "players/pavlik/ilstkarn/path"+random(9));
          command("look", this_player());
          names -= ({ myname });
          return 1;
        }
      }
      write(
      "The evil Lich steps before the gate and points a bony finger at you.\n"+
      GRN+"Lancoz"+NORM+" hisses: You want to enter this gate do You?\n");
      write(
      GRN+"Lancoz"+NORM+" hisses: First you must give me somthing valuable,\n"+
      "then you can enter, if you dare!\n");
      return 1;
    }
  }
}


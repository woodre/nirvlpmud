

#include "std.h"

int found;

reset(arg) {
   if(!arg)
     set_light(1);
   found = 0;
}

id(str) { return str == "bush" || str == "bushes"; }

short() { return "A shelf on the side of the mountain"; }

long(str) {
     if(str == "bush" || str == "bushes") {
       if(found == 0) {
         write("A clump of bushes sitting lazily next to the rock wall.\n");
         return 1;
       } else
       write("A clump of bushes thrown down next to the entrance south.\n");
       return 1;
     }
     if(found == 0) {
       write("You have reached a small shelf on the side of the mountain.\n");
       write("Looking out you can see a vast valley and a large castle\n");
       write("to the northeast.  There is a large clump of bushes to the south.\n");
       write("   There are two obvious exits:  up and down\n");
       return 1;
     }
    write("You have reached a small shelf on the side of the mountain.\n");
    write("Looking out you can see a vast valley and a large castle\n");
    write("to the northeast.  You also notice a small hole that lies\n");
    write("behind you and leads into the mountain.  A clump of bushes lies\n");
    write("next to the entrance south.\n");
    write("   There are three obvious exits:  south, up, and down\n");
}

init() {
    add_action("south","south");
    add_action("up","up");
    add_action("down","down");
    add_action("move_bushes","move");
    add_action("search_room","search");
}

search_room(str) {
     if(!str) {
       write("Search what?\n");
       return 1;
     }
     if(str == "room") {
       write("You find an entrance behind the bushes to the south.\n");
       say(capitalize(this_player()->query_name())+" finds a hidden "+
          "entrance behind the bushes to the south.\n");
       found = 1;
       return 1;
     }
     if(str == "bush" || str == "bushes") {
       command("move bushes", this_player());
       return 1;
     }
}

south() {
    if(found == 0) {
      write("What?\n");
      return 1;
    }
    call_other(this_player(),"move_player",
        "south#players/molasar/UNDER/tunnel1");
    return 1;
}

up() {
    call_other(this_player(),"move_player",
        "up#players/molasar/UNDER/steep1");
    return 1;
}

down() {
    call_other(this_player(),"move_player",
         "down#players/molasar/UNDER/steep2");
    return 1;
}

move_bushes(str) {
     if(!str) {
       write("Move what?\n");
       return 1;
     }
     if(str == "bush" || str == "bushes") {
       write("You move the bushes revealing an entrance into a tunnel.\n");
       say(capitalize(this_player()->query_name())+" moves some bushes to "+
          "the south revealing a hidden entrance.\n");
       found = 1;
       return 1;
     }
}





#include "std.h"

id(str) { return str == "mechanism" || str == "rock" || str == "slab" 
              || str == "slab of rock"; }

int opened, inserted;

reset(arg) {
     if(!arg)
       set_light(0);
        opened = 0;
        inserted = 0;
}

init() {
     add_action("insert_rod","insert");
      add_action("turn","turn");
     add_action("west","west");
     add_action("north","north");
}

insert_rod(str) {
     object ob;
     if(str == "rod into mechanism") {
        if(!present("brass rod", this_player())) {
          write("You do not have the required rod!\n");
          return 1;
        }
        if(inserted == 1) {
           write("There is already a rod in the mechanism.\n");
           return 1;
        }
        write("You insert the rod into the mechanism.\n");
        say(capitalize(this_player()->query_name())+" inserts a rod into "+
           " the mechanism.\n");
        ob = present("brass rod", this_player());
        destruct(ob);
        inserted = 1;
     } else
       write("Insert what into what?\n");
       return 1;
}

turn(str) {
     if(!str) {
       write("Turn what?\n");
       return 1;
     }
     if(str == "rod") {
       if(inserted == 0) {
          if(!present("rod", this_player())) {
            write("You do not have a rod.\n");
            return 1;
          }
          write("You turn the rod lazily in your hands.\n");
          return 1;
       }
       if(opened == 1) {
          write("The slab has been moved.  You can't budge the rod.\n");
          return 1;
       }
       write("You turn the rod, causing the slab to move.\n");
       say(capitalize(this_player()->query_name())+" turns the rod "+
          "causing the slab of rock to move.\n");
       tell_room(environment(this_player()), "The rod snaps due to all the "+
           "force exerted on it.\n");
       opened = 1;
       inserted = 0;
       return 1;
     }
}

north() {
      call_other(this_player(),"move_player",
                     "north#players/molasar/UNDER/tunnel21");
      return 1;
}

west() {
     if(opened == 0) {
       write("A stone slab blocks your way.\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "west#players/molasar/UNDER/tunnel23");
     write("You hear the stone slab close behind you.\n");
     say("The stone slab closes after "+capitalize(this_player()->query_name())+
         " passes through.\n");
     opened = 0;
     return 1;
}

short() { return "A cavernous room"; }

long(str) {
     if(str == "mechanism") {
       if(inserted == 0) {
          write("A tarnished brass mechanism evidently used in moving the slab\n");
          write("which blocks your passage to the west.  Upon further examination\n");
          write("you notice a small hole in the center where a rod can be inserted.\n");
          return 1;
       } else
       write("A tarnished brass mechanism with a rod inserted into the center.\n");
       write("You should be able to turn the rod to work the mechanism.\n");
       return 1;
     }
     if(str == "slab" || str == "rock" || str == "slab of rock") {
       if(opened == 0) {
         write("A huge slab of rock.\n");
         return 1;
       } else
       write("A huge slab of rock next to an opening to the west.\n");
       return 1;
     }
     if(opened == 1) {
       write("A large cavernous room.  The ceiling ballons up to at least 30\n");
       write("feet in height.  Many huge rocks and outcroppings lie around \n");
       write("the room.  There is an especially large rock next to the\n");
       write("opening to the west.  Looking more closely in that area you\n");
       write("notice a mechanism next to it.\n");
       write("   There are two obvious exits:  north and west\n");
       return 1;
     }
     write("A large cavernous room.  The ceiling ballons up to at least 30\n");
     write("feet in heigth.  Many huge rocks and outcroppings lie around the\n");
     write("room.  There is an especially large rock next to the west wall.\n");
     write("Looking more closely in that area you notice some sort of\n");
     write("mechanism next to the slab of rock.\n");
     write("   There is one obvious exit:  north\n");
}


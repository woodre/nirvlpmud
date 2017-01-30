#include "/players/linus/def.h"
inherit "/room/room.c";
 reset(arg) {
    { 
     if(!find_living("Linus_owns_this_tigger")) {
      MO(CO("/players/linus/Newbie/NPC/Tigger.c"),TO);
    }
     set_light(1);
     short_desc = GRN+"The hundred acre wood"+NORM;
     long_desc = GRN+
  "Tall trees stretch to the sky in all directions, standing on a\n"+
  "carpet of green grass.  A small dirt footpath meanders around the\n"+
  "trees.  A small walkway can be seen leading to a small door, which\n"+
  "is in a large maple tree.  A small roof stretches out to cover the\n"+
  "doorway, and a pair of mailboxes stand to the side of the walkway.\n"+
  "The names 'Kanga' and 'Roo' are scribbled onto the sides of them.\n"+NORM;

    items = ({
         "tree","A large maple tree",
         "trees","Mostly oak trees, but there are others growing here too",
         "grass","Tall green grass",
         "mailboxes","Small wooden mailboxes.  The names Kanga and Roo are written on the sides",
         "boxes","Small wooden mailboxes.  The names Kanga and Roo are written on the sides",
         "mailbox","A small wooden mailbox with a name scribbled on the side",
         "footpath","Brown dirt where grass will no longer grow",
         "path","Brown dirt where grass will no longer grow",
         "walkway","Hard packed dirt where grass no longer grows",
         "way","Hard packed dirt where grass no longer grows",
         "roof","A small shingled roof that protects the doorway",
         "doorway","A small wood-framed doorway that houses a small wooden door",
         "door","A small door that is made from wood.  You could probably 'enter' the 'house' through this door"  }); 
    dest_dir = ({
         NEWB+"n2.c","south",
         NEWB+"n4.c","north"
          });
}
}
init() {
 ::init();
 add_action("enter_house","enter");
 add_action("Listen","listen");
 add_action("read_stuff","read");
}
enter_house(string str){
   if(!str || str!="house") { FAIL("Enter what?\n"); return 0; }
  write("You open the door and enter the house.\n");
  TP->move_player("into the house#"+NEWB+"n3a.c");
 return 1;
}
Listen() {
 write("The chirping songs of birds from within the forest can be heard.\n");
 return 1;
}
read_stuff(string str) {
 if(!str || str!="mailboxes" && str!="mailbox" && str!="boxes" && str!="box") { FAIL("Read what?\n"); return 0; }
 if(str=="mailboxes" || str=="mailbox" || str=="boxes" || str=="box") {
     write("The mailboxes read: Kanga and Roo.\n");
     return 1;
}
}

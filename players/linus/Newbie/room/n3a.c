#include "/players/linus/def.h"
inherit "/room/room.c";
 reset(arg) {
   if(!present("kanga",TO)) {
   MO(CO("/players/linus/Newbie/NPC/Kanga.c"),TO);
}
   if(!present("roo",TO)) {
   MO(CO("/players/linus/Newbie/NPC/Roo.c"),TO);
}
     set_light(1);
     short_desc = "Inside the tree";
     long_desc  =
 "Light flows in through a small window in the western wall, next to\n"+
 "an open door.  A small wooden table rests in the center of the room,\n"+
 "surrounded by 2 small wooden chairs.  A sink and counter stand next to\n"+
 "the northern wall, making up a small kitchen area. Two beds stand near\n"+
 "the southern wall.  Some toys lay on the smaller of the two beds.\n";
   items = ({
   "window","A small window that offers a superb view of the forest outside",
   "wall","Which wall are you looking at? (the 'northern wall' or the 'western wall')",
   "northern wall","A counter lines the northern wall of the house",
   "sink","A small sink which holds some dishes from last night's supper",
   "dishes","Plates, bowls, and some silverware",
   "plates","Plastic plates with pictures of flowers on them",
   "bowls","Plastic bowls with pictures of flowers on them",
   "silverware","Various eating utensils",
   "door","The door is open and you can exit if you want",
   "counter","A small counter top that holds a sink",
   "beds","The larger bed is made up neatly, where the small one is messy, with a few toys scattered on it",
   "chair","A small wooden chair",
   "chairs","Small wooden chairs",
   "table","A small wooden table with mismatched legs",
   "toys","Stuffed animals, a toy train, and some other toys",
   "train","A brightly painted toy train",
   "animals","Some stuffed animals.  Most are faded with age",
   "western wall","The door and a small window are in the western wall"  });
    dest_dir = ({
         NEWB+"n3.c","exit"
          });
}
init() {
  ::init();
  add_action("smell_cookies","smell");
}
smell_cookies() {
   write("The sweet aroma of cookies baking fills the air.\n");
 return 1;
}

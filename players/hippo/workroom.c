#include <esc.h>
inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "strange place";
   long_desc = format("There are many books all over \
in this place. The man who lives in here \
must be very smart if he can find his \
way in this mess. \
\nThe room itself looks old, but walls are clean \
and well kept. One corner however, opposite the door \
to the toilet, is dirty. A small sign, a few inches above \
the floor in the corner, says: 'Hipbie Hippuk'. \
\n",70);
   set_light(1);
   dest_dir =
   ({
         ":","\n",
         "/players/hippo/rooms/toilet","toilet",
         "/room/church", "church",
         "/room/post","post",
         "/players/bastion/room/limbo", "limbo",
        "/players/hippo/quest_1/brain.c","quest",
       "/players/hippo/rooms/mouth.c","mouth",
      "/room/adv_inner","wizboard",
    });
}

realm(){return "NT";}

init() {
  ::init();
  add_action("push","push");
}

push(string str) {
  if(str=="button") {
    print("You push the red button \
and wait for womething to happen. \
However, nothing happens (yet?)! \
");
}
return;
}

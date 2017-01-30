#include "def.h"

inherit AROOM;

int boulder;

reset(arg) {
  ::reset();
  boulder=1;
  if(arg) return;
  set_light(1);
  short_desc="Mountains";
  long_desc=
"  Snow caps the surrounding peaks and a crisp chill permeates the air.\n"+
"High atop the mountains, you get a magnificent view of the chasm\n"+
"to the east and the hills to the south.  A huge boulder, precariously\n"+ 
"close to falling, sits atop a steep slope.  A path to the northwest\n"+
"leads further up the mountain.\n";
  items=({
    "snow","Fresh, icy snow covers the nearby peaks like chocolate\n"+
           "on a sundae",
    "peaks","The turbulent chain of mountains looks like it becomes\n"+
            "impassible to the north and west",
    "mountains","The turbulent chain of mountains looks like it becomes\n"+
            "impassible to the north and west",
    "chasm","You make out a bridge going over a chasm to the east",
    "hills","The steap slopes of the mountains turn into rolling hills\n"+
            "to the south",
    "boulder","A huge boulder, slightly rounded by the elements, sits atop a cliff\n"+
              "which faces the rising sun.  You think you could <"+HIM+"push"+NORM+"> it to the\n"+
              "north or to the south",
  });
  dest_dir=({
    PATH+"m1b","northwest",
    PATH+"m2","east",
    PATH+"m4","south"
  });
}
long(str) {
  if(str=="chasm"||str=="bridge")
    view_room(PATH+"m2.c");
  else
  if(str=="hills")
    view_room(PATH+"m4.c");
  else
  if(str=="boulder" && !boulder)
    write("There is no boulder here.\n");
  else
  ::long(str);
}
init() {
  ::init();
  add_action("cmd_push","push");
}
cmd_push(str) {
  if(!boulder) return 0;
  notify_fail("Push <what> <where>?\n");
  if(str=="boulder south") {
    boulder_attack("m4");
    return 1;
  }
  if(str=="boulder east") {
    boulder_attack("m2");
    return 1;
  }
}
boulder_attack(str) {
  object area, target;
  if(TP->query_attrib("ste") < random(40)) {
    write("You push at the boulder, but you fail to move it.\n");
    say(TPN+" pushes at the boulder, but fails to move it.\n");
    return 1;
  }
  boulder=0;
  write("You push the huge boulder down the cliff.  ");
  say(TPN+" pushes the huge boulder down the cliff.  ");
  tell_room(this_object(),"It swiftly gathers\n"+
        "speed, becoming a deadly missile of destruction by the time\n"+
        "it reaches the bottom of the mountain.\n");
  items[11]="There is no boulder";
  area=master->query_room(PATH+str);
  target=first_inventory(area);
  tell_room(area,"A rolling boulder thunders through the room.\n");
  while(target) {
    if(target->is_player() && target->query_attrib("ste")<random(35)) {
      tell_room(area,target->query_name()+" is crushed!\n");
      target->hit_player(50);
    }
    target=next_inventory(target);
  }
}

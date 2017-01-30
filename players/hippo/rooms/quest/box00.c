#include "/players/hippo/bs.h"
inherit "/players/hippo/rooms/quest/random.c";
reset(arg) {
  if(arg) return;
}

id(str) { return str=="box"; }

long() {
  write("You have to push this box to the same colored room."+BS+
        "If you think this is easy, you are wrong!"+BS);
}

short() {return "a "+
   color+
   " box";}

init() {
  add_action("do_push","push");
}

do_push(str) {
  string nextroom, tmp, str1, str2;
  int i;
  if (!str) return 0;
  if (sscanf(str, "box %s", tmp)==1) str=tmp;
  str1=file_name(environment(this_object()));
  sscanf(str1, "players/hippo/rooms/quest/qroom%d.c", i);
  if(str=="west") i=i-1;
  else
  if(str=="east") i=i+1;
  else
  if(str=="north") i=i+10;
  else
  if(str=="south") i=i-10;
  else {
    notify_fail("You have to push the box. If you don't wanna push "+BS+
                "the box, don't push at all"+BS);
    return 1;
  }
  nextroom="/players/hippo/rooms/quest/qroom"+i;
  call_other(nextroom, "???", 0);
  move_object(this_object(), nextroom);
  write("The box scrapes loudly on the floor as you push it.\n");
  say("The box scrapes loudly on the floor as "+
      this_player()->query_name()+" pushes it to the "+str+".\n");
  return 1;
}

get() { return 0; }

drop() { return 1; }

#include "/players/feldegast/defines.h"
#include "def.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  short_desc="Damp cave";
  long_desc=
"  This isn't so much a cave as a long hole in the rock, forcing you\n\
to hunch over to move deeper inside.  Near the end of it, you see a\n\
faint light coming from a crack in the rock.\n";
  dest_dir=({
    PATH+"volcano2","out",
  });
  items=({
    "crack","You FOOLS!  Now it's time to die!!!!!!!!!!",
  });
}
long(str) {
  if(!str || str!="crack") ::long(str);
  else {
    write("You peek through the crack and see:\n");
    call_other(PATH+"valve_room","???");
    view_room(PATH+"valve_room");
  }
}

view_room(str) {
  object targ,ob;
  
  targ=find_object(str);
  write(targ->short()+"\n");
  targ->long();
  ob=first_inventory(targ);  
  while(ob) {
    write(ob->short()+"\n");
    ob=next_inventory(ob);    
  }
  write("\n");
}

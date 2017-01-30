#include "defs.h"

inherit ROOM;

view_room(str);

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Bloated Toad";
  long_desc=
"  Light comes into the room through a leaded glass window looking\n\
out on the Plaza of the Gate.  In the middle of the room is a large\n\
bed with an upholstered headboard.  Next to the window is a desk with\n\
some papers on it.\n";
  items=({
    "window","Nevermind...",
    "bed","The bed looks rumpled and unmade",
    "headboard","It is upholstered",
    "desk","The mahogany desk has several papers on it which you can read",
  });
  dest_dir=({
    PATH+"stav3.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(!str || str!="papers") {
    notify_fail("Read what?\n");
    return 0;
  }
  write(
"Dear brother,\n\
  I give you that title only because I will give you no other.  Our\n\
royal father died without acknowledging you as his son.  I urge you\n\
to remain where you are in the Jal-Hab region, as you will be killed\n\
on sight if you enter the duchy.  I know how much you desire to come\n\
to court, but you shall never have it in my lifetime.  It would under-\n\
mine my rule, and the memory of our father.  I wish you long life and\n\
health...But somewhere out of sight.  You are an embarassment to the\n\
name d'Blood.\n\
\nYours truly,\nBaron Miguel d'Blood\n"
  );
  return 1;
}

void long(string str) {
  if(!str || str!="window") {
    ::long(str);
    return;
  }
  view_room(PATH+"sgate.c");
}

view_room(str) {
  object targ,ob;
  call_other(str,"???");
  targ=find_object(str);
  write(targ->short()+"\n");
  targ->long();
  ob=first_inventory(targ);  
  while(ob) {
    write(ob->short()+".\n");
    ob=next_inventory(ob);    
  }
}

#include "../def.h"
inherit MYROOM;

int hick;
reset(arg) {
  hick=0;
  if (arg) return;
  set_light(1);
  short_desc="Overlooking a Farm";
  long_desc=
"    This is a small clearing by the roadside overlooking a\n"+
"farm downhill from where you are.  Although the slope here\n"+
"is too steep to go straight down, a path to the northeast\n"+
"appears to lead down.  A small sign is nailed to an oak tree.\n";
  items=({
    "road","The road is to the south",
    "farm","A cluster of buildings in a holler surrounded by trees",
    "slope","The rocky slope goes down at a 75 degree angle",
    "sign","A wooden sign made out of a wide board and etched with letters",
    "path","A gravel path heads down the slope at an angle"
  });
  dest_dir=({

    PATH+"Farm/farm1","northeast"
  });
}   
init() {
  ::init();
  add_action("cmd_northeast","northeast");
  add_action("cmd_read","read");
  add_action("cmd_search","search");
}
cmd_northeast() {
  if(!hick) {
    write("A woman steps out of the bushes holding a crossbow\n"+
          "and blocks the path.\n");
    move_object(clone_object(PATH+"Farm/maggie"),this_object());
    hick=1;
    return 1;
  }
  if(present("hick")) {
    write("Maggie fires a warning shot over your head.\n");
    call_out("threaten",4,this_player());
    say("Maggie fires a bolt over "+this_player()->query_name()+"'s head with her crossbow.\n");
    return 1;
  }
}

threaten(object target) {
  if(!present("maggie",this_object())) return;
  say("Maggie says: Leave now or I'll shoot.\n");
  call_out("threaten2",4,target);
}

threaten2(object target) {
  if(present(target,this_object())) {
    say("Maggie says: Don't say I didn't warn you!\n");
    present("maggie",this_object())->attack_object(target);
  }
}

cmd_read(str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The sign says: 'NO TRESPASSING'.\n");
  say(this_player()->query_name()+" reads the sign.\n");
  return 1;
}
cmd_search() {
  write("Upon careful examination, you notice someone hiding further\n"+
         "down the path.\n");
  return 1;
}

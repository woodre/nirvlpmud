#include "defs.h"

inherit ROOM;

int summoned;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This large cavern is half filled by a natural spring of polluted\n\
green water.  The steam rising up from the pool has a sickly smell to\n\
it that makes you feel ill.\n";
  items=({
    "cavern", "reflexive",
    "spring", "The water appears to be polluted by something noxious that\n"+
              "makes you feel ill simply being near",
    "pool", "The water appears to be polluted by something noxious that\n"+
              "makes you feel ill simply being near",
    "water", "The water appears to be polluted by something noxious that\n"+
              "makes you feel ill simply being near",
    "steam", "The steam fills the cavern, obscuring the back cave walls",
  });
  dest_dir=({
    PATH+"castle10.c","west",
  });
}

void init() {
  ::init();
  add_action("cmd_stupid", "bathe");
  add_action("cmd_stupid", "dive");
  add_action("cmd_summon", "toss");
}

int cmd_stupid(string str) {
  write(GRN+"The noxious water makes you feel ill.\n"+NORM);
  say(TPN+" "+query_verb()+"s in the water.\n");
  TP->add_hit_point(-random(10));
  return 1;
}

int cmd_summon(string str) {
  object ball;
  notify_fail("Toss what into what?\n");
  if(str!="ball into pool" &&
     str!="ball into water")
    return 0;
  ball=present("powdery ball",TP);
  if(summoned) {
    notify_fail("You cannot do that.\n");
    return 0;
  }
  if(!ball) {
    notify_fail("You don't have that.\n");
    return 0;
  }
  destruct(ball);
  TP->add_weight(-1);
  write("You toss the powdery white ball into the festering pool.\n");
  say(TPN+" tosses something into the water.\n");
  call_out("summon",3,0);
  return 1;
}

void summon(int x) {
  switch(x) {
    case 0:
      tell_room(this_object(),"The water begins to roil and bubble.\n");
      break;
    case 1:
      tell_room(this_object(),"The cavern is quickly obscured by a thick cloud of steam.\n");
      break;
    case 2:
      tell_room(this_object(),"The water begins to "+HIG+"glow"+NORM+".\n");
      break;
    case 3:
      tell_room(this_object(),"A voice hisses: "+BOLD+"WhY HaVE YoU BrOuGHt mE BaCK?\n"+NORM);
      move_object(clone_object(MON_PATH+"plaguelord.c"),this_object());
      return;
      break;
  }
  call_out("summon",5,++x);
}

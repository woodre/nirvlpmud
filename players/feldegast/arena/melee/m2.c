#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Bridge";
  long_desc=
"  An ancient stone bridge spans a chasm here, providing the only way\n"+
"across.  Although it looks like it could once support a wagon and a\n"+
"full team of horses, it now looks rickety and unstable.  Across the\n"+
"bridge and to the west you see a looming mountain, and to the east\n"+
"the land rises to an unusually steep plateau.\n";  
  items=({
    "chasm","Carl Nalut was here",
    "wagon","It looks like a player isn't reading the description carefully\n"+
            "enough.  I said 'once'",
    "bridge","The support columns look brittle and unstable, while the wooden\n"+
             "planks look worn and fragile",
    "mountain","Viva la mountaineers",
    "plateau","Nadia Mouelhi is a BABE!",
  });
  dest_dir=({
    PATH+"m1","west",
    PATH+"m3","east",
  });
}
long(str) {
  if(str=="chasm") view_room(PATH+"m2b");
  else if(str=="mountain") view_room(PATH+"m1");
  else if(str=="plateau") view_room(PATH+"m3");
  else ::long(str);
}
init() {
  ::init();
  add_action("cmd_fall","east");
  add_action("cmd_fall","west");
}
cmd_fall() {
  if(TP->query_attrib("luc")+TP->query_attrib("ste") > random(50))
    return 0;
  write("A board breaks beneath your foot and you plummet into the chasm\n"+
        "below.\n\n");
  say("A board breaks beneath "+TPN+"'s foot and "+TP->query_pronoun()+" plunges\n"+
      "into the chasm below.\n\n");
  tell_room(PATH+"m2b","\n"+TPN+" falls from the bridge above and lands with a *THUD*.\n");
  move_object(TP,master->query_room(PATH+"m2b"));
  TP->hit_player(10+random(40));
  return 1;
}

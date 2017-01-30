#include "def.h"

inherit AROOM;

int boulder; /* Whether the boulder is up or not. */

reset(arg) {
  ::reset(arg);
  if(boulder) {
    tell_room(this_object(),"The broken boulder pieces itself together and flies back into\n"+
          "it's place atop the pinnacle.\n");
    boulder=0;
  }
  if(!present("table",this_object()))
    move_object(clone_object(PATH+"Obj/table.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Plateau";
  long_desc=
"  High above the surrounding terrain, this plateau offers an excellent\n"+
"vantage of the bridge to the west, the ruins to the southwest, and\n"+
"even the forest to the south.  Amidst three windblown pinnacles sits\n"+
"a carefully crafted stone table.  Atop one of the pinnacles, a boulder\n"+
"sits precariously.\n";  
  items=({
    "terrain","A beautiful panorama of the mountains to the west, and the"+
              "rolling hills to the southwest, and the river which passes"+
              "just to the east",
     "plateau","Smooth rock surrounded by towering cliffs",
     "bridge","view_room",
     "ruins","view_room",
     "forest","view_room",
     "pinnacles","Three pinnacles soar twenty to thirty feet into the air",
     "boulder","The boulder sits precariously atop one of the pinnacles."+
               "You could <"+HIY+"push"+NORM+"> it off if you wanted to",
  });
  dest_dir=({
    PATH+"m2","west",
    PATH+"m6","south"
  });
}
long(str) {
  if(str=="bridge") view_room(PATH+"m2");
  else if(str=="ruins") view_room(PATH+"m5");
  else if(str=="forest") view_room(PATH+"m6");
  else ::long(str);
}
init() {
  ::init();
  add_action("cmd_push","push");
}
cmd_push(str) {
  object ob;
  object next;
  notify_fail("Push what?");
  if(!str) return 0;
  if(str!="boulder") return 0;
  if(boulder) {
    write("It's not there anymore.\n");
    return 1;
  }
  if(TP->query_attrib("str") < 10+random(20)) {
    write("You push and struggle, but fail to move the boulder.\n");
    say(TPN+" climbs up and tries to push down the boulder.\n");
    return 1;
  }
  write("You give a final shove to the boulder before you ungracefully\n"+
        "plummet back down to the ground.\n");
  say(TPN+" gives a final shove to the boulder before falling ungracefully\n"+
      "back down to the ground.\n");
  tell_room(this_object(),"With a loud CRACK, the boulder shifts out of its place and plummets\n"+
                          "to the ground, shattering into thousands of head-sized boulders which\n"+
                          "fly around the area like shrapnel!\n");
  boulder=1;
  ob=first_inventory(this_object());
  while(ob) {
    next=next_inventory(ob);
    if(ob->is_player() && ob->query_attrib("ste")< random(40)) {
      tell_room(this_object(),
        ob->query_name()+" is struck by a fragment!\n");
        ob->hit_player(random(40));
      if(ob->query_attrib("ste") < random(40)) {
        tell_room(this_object()," "+ob->query_name()+" falls off of the plateau!\n");
        move_object(ob,random(2)?(PATH+"m2"):(PATH+"m6"));
        tell_room(environment(ob),ob->query_name()+" falls out of the sky with a loud *THUD*\n");
      }
    }
    ob=next;
  }
  return 1;
}

      


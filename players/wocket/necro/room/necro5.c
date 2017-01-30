#include "../defs.h"
inherit ROOM;

reset(int arg){
  if(!present("boneportal",this_object())){
    move_object(clone_object(OBJ+"/misc/boneportal.c"),this_object());
  }
  if(arg) return;
    is_pk = 1;
    set_light(1);
    add_property("no_follow");
    short_desc= BOLD+"Portal of the Dead"+OFF;
    long_desc="  "+
       "A small room at the end of a long hallway, with white marble walls,\n"+
       "interlaced with deep blue veins.  A soft light emanates throughout the\n"+
       "room, casting gentle shadows across the floor, and a portal made from\n"+
       "bones of an ancient dragon stands at the pinnacle, beckoning travelers\n"+
       "to enter it.\n";

    items=({
     "dragon","The dragon died long ago at the hands of Sagal",
     "bone","Bone from an ancient dragon makes up the portal",
     "energy","The energy within the bone portals shifts in color constantly",
     "walls","They give a soft reflection through the marble",
     "floor","They are a dull grey of worn stone",
     "light","It is a soft white that glows from the portal",
     "shadows","They are soft and wavy",
     "south","South is the Necromancer Stronghold",
     "nirvana","Nirvana is full of life begging to be put down",
     "veins","They run though the marble walls with a deep blue",
     "bones","They line the portal",
     "pinnacle","The portal of bone stands at it",
   });

    dest_dir=({
      PATH+"/room/necro2.c","south",
    });
}

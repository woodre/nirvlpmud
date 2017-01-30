#include "../defs.h"

inherit ROOM;

object j;

void reset(int arg)
{
  if(!j) {
    j=clone_object(NPCDIR+"janoc.c");
    move_object(j,this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc=RED+"The Pyromancer's Study"+NORM;
  long_desc=
"  Living flame envelopes the room, searing your lungs and singeing\n\
your eyebrows.  Looking closer, you see that the flames have been\n\
carefully crafted into a crackling parody of common items such as\n\
a sofa, a sitting table, and a workbench.  At the center of the\n\
chamber is a firepit which glows white hot.\n";
  dest_dir=({
    ROOMPATH+"tower5.c","northeast",
  });
}

void init() {
  ::init();
  call_out("protect",2,this_player());
}

void protect(object target) {
  if(j) {
    tell_object(target,HIW+"The firepit glows intensely bright.\n"+NORM+
                       "Janoc says: I can protect you from the flames, but only for a time.\n"+
                       "            Be quick about your business.\n");
  }
  call_out("flames",5+random(10),target);
}

void flames(object target) {
  if(!present(target)) return;
  if(j)
    target->hit_player(random(10));
  else
    target->hit_player(random(100));
  tell_object(target,HIR+"The flames rise up and scorch you.\n"+NORM);
  call_out("flames",5+random(10),target);
}
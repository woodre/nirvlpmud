#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  move_object(clone_object(OBJDIR+"guildboard.c"),this_object());
  set_light(1);
  short_desc="A comfortable lounge";
  long_desc=
"  This is a comfortable lounge where magic-users gather to discuss\n\
their experiments and relax after a busy day blowing stuff up in new\n\
and unusual ways.  Creaky leather couches are scattered around several\n\
sturdy, yet well-worn coffee tables.  On either end of the room are\n\
brick fireplaces, keeping the atmosphere warm and toasty.\n";
  items=({
    "couches","The couches are made out of black leather that creaks when\n"+
              "you settle into them",
    "tables","You notice all of the coffee circles on them.  For some reason\n"+
             "sorcerers mistakenly believe that they don't really need coasters",
    "fireplaces","Large brick fireplaces with assorted fire-tending instruments nearby",
  });
  dest_dir=({
    ROOMPATH+"tower3.c","south",
  });
}

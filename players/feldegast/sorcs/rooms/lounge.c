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
sturdy, yet well-worn coffee tables.  A shiny brass lamp sits upon\n\
one of the tables.  On either end of the room are brick fireplaces,\n\
keeping the atmosphere warm and toasty.\n";
  items=({
    "couches","The couches are made out of black leather that creaks when\n"+
              "you settle into them",
    "tables","You notice all of the coffee circles on them.  For some reason\n"+
             "sorcerers mistakenly believe that they don't really need coasters",
    "fireplaces","Large brick fireplaces with assorted fire-tending instruments nearby",
    "lamp", "The shiny brass lamp looks like it could use a good polish",
  });
  dest_dir=({
    ROOMPATH+"tower3.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_polish","polish");
}

int cmd_polish(string str) {
  if(str!="lamp") {
    notify_fail("Polish what?\n");
    return 0;
  }
  if(present("rag",this_player())) {
    write("\nAs you polish the lamp with the rag it begins to shine incredibly\n"+
          "bright.  When you can see again, you are somewhere else.\n\n");
    say(TPN+" disappears into the lamp.\n");
    move_object(TP,ROOMPATH+"bottle.c");
    command("look",TP);
    say(TPN+" arrives.\n");
    return 1;
  }
  write("You try to shine the lamp with your hands, but you just get\n"+
        "fingerprints all over it.\n");
  say(TPN+" tries to polish the lamp.\n");
  return 1;
}


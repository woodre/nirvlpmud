#include "../defs.h"

inherit ROOM;

void reset(int arg)
{
  if(!present("calthia"))
    move_object(clone_object(NPCDIR+"calthia.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=HIR+"Pr"+HIY+"is"+HIG+"ma"+HIM+"tic "+HIB+"Cham"+HIC+"ber"+NORM;
  long_desc=
"  You look about this room and are immediately disoriented by count-\n\
less reflections of yourself passing into infinity.  The furniture is\n\
constructed of glass, mirrors, and colored light.  Although you can\n\
see your face in the floor, beneath your feet you feel a plush rug.\n\
Through a 'window', you see a rainbow colored nebula against a field\n\
of stars.  You are completely uncertain of what is real and what is\n\
not.\n";
  items=({
    "reflections","special",
    "reflection","special",
    "mirrors","special",
    "mirror","special",
    "furniture","A pair of surprisingly comfortable 'glass' sofas face each\n"+
                "other in the center of the room.  Although you sense that there\n"+
                "are other objects just outside your field of view, you can\n"+
                "never quite make them out",

    "window","The window has no borders nor glass.  It seems to be a simple square\n"+
             "leading out into the vastness of space",
    "nebula","A thing of astonishing and undescribable beauty",
    "stars","You do not recognize any familiar constellations",
  });
  dest_dir=({
    ROOMDIR+"tower4.c","leave",
  });
}
void long(string str) {
  if(!str || (str!="mirrors" && str!="reflections")) {
    ::long(str);
    return;
  }
  command("look at "+(string)this_player()->query_real_name(),this_player());
}
void init() {
  ::init();
  add_action("cmd_enter","enter");
}
int cmd_enter(string str) {
  if(!str || str!="window") {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("\n\nYou step through the window and out into cold space...You gasp\n"+
        "vainly for air that will not come as you plummet an unknown\n"+
        "distance...\n\n\n\tFalling...\n\n\t\tFalling...\n\n\n\t\t\tFalling...\n\n\n"+
        "\t\t\t...Until you finally land with a THUMP.\n");
  if(present("calthia"))
    call_out("tsk",2);
  return 1;
}

void tsk() {
  tell_room(this_object(),"\nCalthia tsks softly as she looks at you with an amused\n"+
                          "twinkle in her eyes.\n");
}

  
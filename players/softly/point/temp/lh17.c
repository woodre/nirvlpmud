#include "/players/softly/closed/ansi.h"
inherit "/players/softly/point/rooms/std_lh.c";

#define NAME (string)this_player()->query_real_name()

string *readers;

  reset(arg) {
  object p;
  if(arg) return;
    if(p = present("blackbeard", this_object()))
    {
      move_object(p, "/room/void");
      destruct(p);
    }
  ::reset();

long_desc =
"  A thin iron railing that once surrounded the outer edge of\n"+
"the platform has rusted through leaving a dangerous opening.\n"+
"There is a brass sign which seems out of place is mounted on\n"+
"the broken railing.  The large blinking beacon illuminates the\n"+
"area intermittently.  The platform surrounds the center door.\n";

items = ({
  "sign", "The sign seems to have been placed here\n\
recently.  Perhaps you could read it",
  "door",
"A wooden hinged door opens easily. ",
"lighthouse",
"The tall red and white striped lighthouse stands on\n\
 large bounders that rise from the sea.  It might be\n\
 reachable over the rocks",
"beacon",
"Although the lighthouse has been long abandoned,\n\
 the large yellow light still shines toward the\n\
 southeast, warning ships away from the rocks",
"scaffolding",
"An iron structure holds the beacon above the platform",
"platform",
"A surface extends outward six feet in all directions",
"railing",
"The railing intended to prevent falling has rusted through",
"opening",
"Beyond the gap in the railing lies danger",
  });


dest_dir = ({
  "/players/softly/point/rooms/lh12.c","north",
  "/players/softly/point/rooms/lh18.c","west",

  });
}

void init()  {
 ::init();
add_action("jump","jump");
add_action("fall","fall");
add_action("read","read");
}
status jump()  {
write("You jump through the broken railing into the unknown.\n");
say(this_player()->query_name()+" suddenly jumps through the broken railing.\n");
call_other(this_player(),"move_player","jump#/players/softly/point/temp/falling.c");
  return 1;
}

status fall()  {
write("You slip and with no railing to catch you, fall into the unknown.\n");
say(this_player()->query_name()+" slips and falls over then edge.\n");
call_other(this_player(),"move_player","fall#/players/softly/point/temp/falling.c");
  return 1;
}

status read(string str)
{
    if(str == "the sign" || str == "sign" || str == "plaque" || str == "brass plaque")
    {
      write("You read the brass sign.\n\n"
+ YEL +
         "     |================================| \n"+
         "     |         C A U T I O N          | \n"+
         "     |                                | \n"+
         "     | Please stay away from the edge.| \n"+
         "     | Many have jumped or fallen.    | \n"+
         "     | Parents, watch your children.  | \n"+
         "     |                                | \n"+
         "     |      YOU COULD BE KILLED!      | \n"+
         "     |================================| " + NORM +
"\n\n");
      return 1;
    }
}

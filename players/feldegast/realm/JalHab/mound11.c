#include "defs.h"

inherit MNDROOM;

int columns;

void reset(int arg)
{
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  Two massive columns of solid stone divide this room in half. The\n\
floor here is worn smooth, perhaps indicating that it is a major\n\
freeway through the Myrmidar's underground kingdom.  Two large\n\
openings at both ends of this cavern lead into other caves.\n";
    dest_dir=({
      PATH+"mound12.c","northwest",
      PATH+"mound12.c","northeast",
      PATH+"mound10.c","southwest",
      PATH+"mound10.c","southeast",
    });
    items=({
      "columns","Examining the two columns more closely, you realize that they\n"+
                "are weaker than they appear",
      "floor", "It has been worn smooth by the passing of many feet",
      "openings", "The openings, each about six feet in diameter, cut through\n"+
                  "the sandstone",
      "cavern", "The cavern is about twenty meters long but merely five\n"+
                "meters wide.  The ceiling is held up by two columns",      
    });
    columns=2;
  }
  if(!present("myrmidar"))
    move_object(clone_object(MON_PATH+"myrm-worker"),this_object());
}

void init()
{
  ::init();
  add_action("cmd_push","push");
  add_action("cmd_push","topple");
}

int cmd_push(string str)
{
  if(!str) {
    notify_fail("Push what?\n");
    return 0;
  }
  if(str=="columns") 
  {
    write("You can only push one at a time.\n");
    return 1;
  }
  if(str!="column")
  {
    notify_fail("Push what?\n");
    return 0;
  }
  if(columns<=0)
  {
    write("The columns have already been toppled.\n");
    return 1;
  }
  if(random((int)this_player()->query_attrib("str")) < 15)
  {
    write("You push against the column, but fail to topple it.\n");
    say(TPN+" tries to push over a column and fails.\n");
    return 1;
  }
  write("Pushing against the column with all your might, you finally\n"+
        "manage to knock it over, blocking an entrance.\n");
  say(TPN+" pushes over a column, blocking an entrance.\n");
  columns--;
  switch(columns) {
    case 1: long_desc=
"  A massive column of solid stone divides this room in half.  The\n\
floor here is worn smooth, perhaps indicating that it is a major\n\
freeway through the Myrmidar's underground kingdom.  Two large openings\n\
at both ends of this cavern lead into other caves.  One of the openings\n\
is blocked by a pile of rocks.\n";
      items=({ 
               "floor", "It has been worn smooth by the passing of many feet",
               "openings", "The openings, each about six feet in diameter, cut through\n"+
                           "the sandstone",
               "cavern", "The cavern is about twenty meters long but merely five\n"+
                         "meters wide"

            });

             break;
    case 0: long_desc=
"  The Myrmidar mound is a labyrinthine maze of twisting tunnels that seem\n\
to connect at random.  The tunnels are cool and humid, with a slightly sweet\n\
odor to them.  The floor here is strewn with rubble.  Both of the openings to\n\
the north have been blocked.\n";
             (PATH+"mound12.c")->set_dest_dir(({
                                PATH+"mound13.c","west",
                                PATH+"mound17.c","east"
                              }));

             items=({ });
             break;
  }
  dest_dir-=({ dest_dir[0] });
  dest_dir-=({ dest_dir[0] });

  return 1;
}


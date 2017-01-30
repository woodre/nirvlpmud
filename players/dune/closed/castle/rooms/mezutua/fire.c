inherit "room/room";
#include "definitions.h"


int solved;

void init()
{
  add_action("position","position");
  add_action("position","place");
  add_action("position","put");
  ::init();
  if(solved) move_object(TP, CASTLEROOM+"/fire2.c");
}


reset(arg)
{
  solved = 0;

  if (!present("wraith"))
  {
    move_object(clone_object(CASTLEMONSTER+"/wraith.c"), this_object());
  }

  if(!arg)
  {
    set_light(0);
    short_desc=("Door of Fire");
    long_desc=
"     Towering above you stand a huge set of obsidian doors. Upon them,\n"+
"straight in the middle, protrudes a stone claw. On the floor, four feet away,\n"+
"a sphere of dazzling amber rests upon a metal chain. Higher on the door,\n"+
"several words are scratched into a stone plaque. Upon the ground, several\n"+
"pieces of bone dot the obsidian floor, like the stars dot the night sky.\n";

    dest_dir=({
CASTLEROOM+"/smoke8.c","south"  ,
    });

    items=({
"doors", "     The door measures fourteen feet high, eight feet wide",
"door",  "     The door measures fourteen feet high, eight feet wide",
"claw",  "     The claw reaches out from the door as if to grab something",
"bones", "     As you look more closely at the bones, you see that they\n"+
         "spell out the following words:\n"+
         "   Unlike the sphere from ground to wall,\n"+
         "   The four orbs must land short from tall.\n"+
         "   But which must happen first of all?",
"bone",  "     As you look more closely at the bones, you see that they\n"+
         "spell out the following words:\n"+
         "   Unlike the sphere from ground to wall,\n"+
         "   The four orbs must land short from tall.\n"+
         "   But which must happen first of all?",
"sphere","     The amber inside the sphere swirls with deviations in color, giving\n"+
         "it a mystical look. The sphere sits on an indentation in the floor, and\n"+
         "is connected to a long metal chain. The sphere looks as if\n"+
         "it is positionable.",
"chain", "     The chain is long enough to allow the sphere to reach the claw",
"plaque","     When gems and jewels fill you with glee,\n"+
         "     Remember that punished you will be,\n"+
         "     If you touch the treasure you see",
    });
  }
}


int position (string str)
{
  string blah, type;

  type = "nobody_would_ever_id_this";

  if  (!str)
  {
    write("Position what into what?\n");
    return 1;
  }

  if (str == "sphere into claw" ||
      str == "sphere in claw"   ||
      str == "sphere on claw"   ||
      str == "sphere onto claw")
  {
    if      (present("katana_orb")) type = "katana_orb";
    else if (present("kitana_orb")) type = "kitana_orb";

    if (present(type)          &&
        present("heart_orb")   &&
        present("mirror_orb")  &&
        present("spider_orb"))
    {
      destruct(present(type));
      destruct(present("mirror_orb"));
      destruct(present("heart_orb"));
      destruct(present("spider_orb"));

      write(
"     You position the sphere into the claw. Suddenly the claw clamps\n"+
"down on the sphere and begins to retract back into the door... as if\n"+
"the door did not have substance. The claw and sphere soon disappear\n"+
"into the door, which slowly swings open. Inside the doors you see a\n"+
"stairway leading down to a lake of fire.\n");
      write_file("/players/dune/log/QUEST_ROOM", this_player()->
        query_real_name()+" (level "+this_player()->
        query_level()+") opened the Fire Door of Mezutua."+
        " ("+ctime()+")\n");
      solved = 1;
      init();
      return 1;
    }

    write(
      "The sphere clamps into the claw perfectly.\n"+
      "A beam from the sphere flashes out and scans the floor.\n"+
      "The beam and the sphere then fade. Shortly thereafter,\n"+
      "the sphere falls back onto the ground. Nothing happened.\n"+
      "Perhaps something(s) needs to be dropped onto the floor\n"+
      "so that the beam can find it next time.\n");

    return 1;
  }

  if (sscanf(str, "sphere%s", blah))
  {
    write("Nothing happens. Perhaps you chose to position the sphere\n"+
          "into the wrong object.\n");
    return 1;
  }

  if (sscanf(str, "sphere"))
  {
    write("Position sphere into what?\n");
    return 1;
  }

  write("This is not positionable.\n");
  return 1;
}

inherit "room/room";
reset(arg)
  {

  if(!arg)
  {
  set_light(1);
  short_desc="Looming Wall";
  long_desc=
    "The west wall of the castle looms over you here, impressing\n"+
    "a part of the castle gloom on the pale light of day. A short \n"+
    "set of stone steps lead down to a closed door in the wall.\n"+
    "An orchard is visible to the west.\n";

  items=({
    "steps", "Though they are worn, the steps seem to be dry, sure footing.",
    "door","The door is of metal bound wood planks, it would take \n"+
    "something heavy to 'batter' the door down.",
  });

  dest_dir=({
    "/players/arrina/grounds/orchard.c","west",
  });
  }
  }


init()
  {
::init();
    add_action("batter_door","batter");
    add_action("open_door","open");
  }

    batter_door()
      {
      if(present("log",this_player()))
      {
        write("You lumber down the steps and bash the door in with \n"+
          "the heavy log!\n");
        say( (this_player()->query_name()) + " lumbers down the steps"+
          "with a log and bashes the door in!\n");
    dest_dir+=({"/players/arrina/newbie/newbie1.c","down",});
init();
    return 1;
      }
        else
      {
        write("You charge down the steps and crash your shoulder off \n"+
              "the door. The rebound knocks you flat!\n");
        say( (this_player()->query_name()) + " charges down the steps \n "+
              "and crashes headlong into the door!\n"+
             (this_player()->query_name()) + " bounces off the door and falls flat!\n");
                return 1;
       }
        return 0;
        }

open_door()
        {
        write("You push at the door. It seems sturdy\n"+
               "and barred on the other side\n.");
        say( (this_player()->query_name()) + "pushes at the door.\n"+
             " It doesn't budge.\n");
        return 1;
        }



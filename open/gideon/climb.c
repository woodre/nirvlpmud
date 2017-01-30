inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
        set_light(1);
        short_desc = "Boot Camp Wall Climb Obstacle";
        long_desc =
  "The swing across was a quick one. Here there stands another\n"+
  "obstacle. It's a tall wall with nothing to help you up\n"+
  "or over to the other side. Maybe you should attempt to\n"+
  "climb the wall.\n";

items =

({
        "wall",
        "The wall is very tall and sturdy, it appears you could climb over it",
        "obstacle",
        "The obstacle is a high wall that you need to climb over",
});

dest_dir =
({

});
}


init()
{
        ::init();
        
        add_action("climb", "climb");
}

climb(str)
{
        if(!str)
        {
                write("What would you like to climb?\n");
                return 1;
        }
        
        if(str != "over wall")
        {
                write("You cannot climb on that!\n");
                return 1;
        }
        
        if(str == "over wall")
        {
             call_other(this_player(), "move_player","climbs up#players/gideon/bootcamp/rooms/room4.c");
                say(this_player()->query_name()+" climbs over the wall.\n");
                return 1;
        }
}

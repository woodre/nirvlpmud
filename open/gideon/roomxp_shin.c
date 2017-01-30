inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
        set_light(1);
        short_desc = "Boot Camp Bobwire Obstacle";
        long_desc =
  "The sun is beating down rather hard, the sweat pours from your skin.\n"+
  "In front of you is a long strech dug into the ground. It's\n"+
  "filled with fresh, wet mud. There is a low bobwire that is\n"+
  "strected over every inche of the mud pit.\n";

items =

({
        "mud",
        "The mud pit is covered with bobwire",
        "pit",
        "The mud pit is covered with bobwire",
        "bobwire",
        "The bobwire is very low to the ground, you need to crawl under it",
        "obstacle",
        "The mud pit has low bobwire over it, maybe you should crawl under it",
});
dest_dir =
({

});
}


init()
{
        ::init();
        
        add_action("crawl", "crawl");
}

crawl(str)
{
        if(!str)
        {
                write("What would you like to crawl under?\n");
                return 1;
        }
        
        if(str != "under bobwire")
        {
                write("You cannot crawl under that!\n");
                return 1;
        }
        
        if(str == "under bobwire")
        {
            call_other(this_player(), "move_player","crawls under#players/gideon/bootcamp/rooms/room5.c");
            say(this_player()->query_name()+" crawls under the bobwire.\n");
            call_other(this_player(), "add_exp", 1123);
                return 1;
        }
}

inherit "room/room";

reset(arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "A small platform";
    long_desc = "You find yourself standing on a tiny platform\n"+
                "suspended in space !  All around you stars and\n"+
                "galaxies shine very bright.  The stars have never\n"+
                "seemed so bright ! It's almost as if you could reach\n"+
                "out and touch one !\n";
}
 
init(str)
{
    ::init();
    add_action("touch_star", "touch");
}

touch_star(str)
{
    if(str == "star")
    {
      say(call_other(this_player(), "query_name") + " touches a star and floats off with it !!\n");
      write("You touch a star and it pulls you out into deep space !!!\n");
      call_other(this_player(), "move_player", "touch#players/morgoth/CASTLE/deep_space");
      return 1;
      }
}

realm() {return "NT";}

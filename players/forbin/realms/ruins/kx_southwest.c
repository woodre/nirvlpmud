/*  Forbin | Create date:  mar2002.02 | Last mod:  sep2002.06  */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/verte_room.c";

reset(arg) 
{
  if(arg) return;

short_desc = ""+GRN+"Keats"+NORM+" | "+MAG+"Windsor in Exile"+NORM+" Boulevard "+GRN+"X"+NORM+" Jacktown Road";
long_desc =  "  This is the circluar intersection of Windsor in Exile\n"+
             "Boulevard which runs east-west just south of the city of\n"+
             "Keats, and Jacktown road, which skirts the city's western\n"+
             "edge.  Both streets dump into the large circle, Jacktown\n"+
             "from the north and the Boulevard from the east.  At the\n"+
             "western edge of the circle stands a wide set of stairs and\n"+
             "a waist high stone platform.  Set atop the platform is a\n"+ 
             "pair of huge pillars.  A grassy path leads to the southwest\n"+
             "past a large sign.\n";
set_light(1);

add_property("NT");

items = ({
  "intersection","The is the intersection Jacktown Rd and Windsor in Exile Blvd",
  "boulevard","Windsor in Exile Boulevard runs west towards the farcaster",
  "road","Jacktown Road runs north from here",
  "street","The is the intersection Jacktown Rd and Windsor in Exile Blvd",
  "streets","The is the intersection Jacktown Rd and Windsor in Exile Blvd",
  "city","The city of Keats towers above you to the northeast",
  "keats","The city of Keats towers above you to the northeast",
  "circle","A circular intersection",
  "path","Leading southwest toward the flame forest, you could 'hike' along it",
  "sign","A sign.  It might be a good idea to 'read' it",
  "stairs","Made of stone, they are deep and in good shape",
  "platform","Standing about waist high, it is made of stone and is huge",
  "pillars","These pillars are remarkable. They stand nearly as tall as the huge pines\n"+
            "that encircle the grove and their girth is that of at least six men. Looking\n"+
            "carefully at them you notice several runes covering the base of each. They\n"+
            "stand apart by ten feet",
  "runes","You look carefully at them, and decide they might be readable",
});
dest_dir = 
({
  "/players/forbin/hyperion/keats/RMS/kstreetwest_south.c","north",
  "/players/forbin/hyperion/keats/RMS/kstreetsouth_west.c","east",
});
}
short() {return ""+MAG+"Hyperion"+NORM+" "+HIW+"|"+NORM+" City of "+GRN+"Keats"+NORM+"";}
okay_follow(){ return 1;}

init() 
{ 
    ::init(); 
  add_action("street_not_open_yet","north");
  add_action("follow_path","hike");
  add_action("warn_player","read");
  add_action("invoke_it", "invoke");
}

street_not_open_yet()
{
  write("This street has been roped off due to a visit of the Hyperion Consul.\n");
    return 1;
}

pathway()
{
  write("You begin to hike towards the flame forest far to the southwest.\n");
  TPMP("down the path#/players/forbin/hyperion/flame_forest/RMS/RMS_nostorm/ffinout_keats.c");
    return 1; 
}

follow_path(arg)
{
  if(!arg)
  {
    FAIL("Hike along what?\n");
      return 0;
  }
  if(arg == "path") return pathway();
  if(arg == "along path") return pathway();
  FAIL("That is not you can walk along.\n");
    return 0;
}

warn_player(arg)
{
  if(arg != "sign" && arg != "runes")
  {
    FAIL("What would you like to read?\n");
     return 0;
  }
  if(arg == "sign")
  {
    write("   The Flame Forest can be a very dangerous    \n"+
          "   place.  It would be very ill-advised to     \n"+
          "   enter without the proper equipment.  The    \n"+
          "   city of Keats is not responsible for those  \n"+
          "   who choose to venture without the guidance  \n"+
          "   of seasoned professional outfitters.        \n"+
          "          "+HIR+"YOU HAVE BEEN WARNED!!!"+NORM+"           \n");
      return 1;
  }
  if(arg == "runes")
  {
    write("You begin to try and translate the runes...\n");
    call_out("finish_read", 3, this_player()); 
    return 1;   
  }
}

finish_read(object ob)
{
  if(!present(ob)){ return 1; }	
  tell_object(ob,	"You find that you can now 'invoke runes', using them as\n"+
                  "a portal of some sort.\n");
}

invoke_it(string str)
{
  if(!str) { write("invoke what?\n"); return 1; }	
  if(str == "runes")
  {
    write(" The pillars shimmer, energy begins to criss-cross between them....\n");
    write(""+HIY+"             _________             _________\n");
    write("             |       |             |       |\n");
    write("             |       |             |       |\n");
    write("             '| ||| |'             '| ||| |'\n");
    write("              | ||| |///////////////| ||| |\n"); 
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("              | ||| |///////////////| ||| |\n");
    write("             _|_____|_............._|_____|_"+NORM+"\n\n");
    write("You step through and....\n\n");     	
    write("      Find yourself elsewhere.....\n\n");
    say(TPN+" disappears suddenly.\n");
    move_object(TP, "/players/forbin/hyperion/ruins/RMS/r01.c");
    tell_room(environment(TP), TPN+" arrives.\n", ({TP}));
    command("look", TP);
    write_file("/players/forbin/logs/ruins.log", ctime()[4..15]+" "+ctime()[20..23]+" "+TPN+" ["+TPL+"+"+TPXL+"] climbed the fence.\n");

      return 1;
  }
  write("invoke what?\n");   
    return 1;
}
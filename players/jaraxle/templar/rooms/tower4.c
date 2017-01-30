#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = "East Tower";
long_desc =
  "   The stairway opens up to a large open room at the\n"+
  "top of the tower.  Four very large windows grace the\n"+
  "room. Each window looks over a different part of the\n"+
  "village of Nirvana.  Large flags can be seen briefly\n"+
  "through the windows as they wave in the wind.\n";
items = ({
  "tower","Made of solid stone, the tower rises high above the castle",
  "room","Made of solid stone, the tower rises high above the castle",
  "stairway","A thick wooden stairway leeding down through the tower",
  "windows","Four large windows.  Each window looks over a different area\nof Nirvana. You may "+HIY+"look over the church"+NORM+", "+HIY+"green"+NORM+", "+HIY+"lockers"+NORM+", or\nthe "+HIY+"shop"+NORM+"",
  "window","Four large windows.  Each window looks over a different area\nof Nirvana. You may "+HIY+"look over the church"+NORM+", "+HIY+"green"+NORM+", "+HIY+"lockers"+NORM+", or\nthe "+HIY+"shop"+NORM+"",
  "opening","A large opening into the top of the tower",
  "flags","Flags representing the Knights Templar",
  "nirvana","   Welcome to Nirvana\n\n\n                               An LpMud version 3.1.02-DR\n                               running a modified 2.44 mudlib.\n                               established February 26, 1991",
});

MOCO("/players/jaraxle/templar/items/telescope.c"),TO);
dest_dir = ({
  "/players/jaraxle/templar/rooms/tower3.c","down",
});

}

init(){
        ::init();

this_player()->set_fight_area();
   add_action("lok","look");
}


lok(arg){
if(!present("KnightInvite", this_player()) && this_player()->query_level() < 20){
                       tell_object(this_player(),
                                "Your ties blind you to the sight of the land!\n");
                      return 1;
              }
if(arg == "over the church"){
write("\nYou look out beyond the castle towards the "+HIW+"Village Church"+NORM+"...\n\n");
      move_object(this_player(), "/room/church.c");
      command("look", TP);
  move_object(this_player(), this_object());
return 1; }
if(arg == "over the green"){
  write("\nYou look out beyond the castle towards the "+GRN+"Village Green"+NORM+"...\n\n");
      move_object(this_player(), "/room/vill_green.c");
      command("look", TP);
  move_object(this_player(), this_object());
 return 1; }
if(arg == "over the shop"){
 write("\nYou look out beyond the castle towards the "+HIB+"Village Shop"+NORM+"...\n\n");
      move_object(this_player(), "/room/shop.c");
      command("look", TP);
  move_object(this_player(), this_object());
return 1; }

if(arg == "over the lockers"){
 write("\nYou look out beyond the castle towards the "+HIM+"Lockers"+NORM+"...\n\n");
      move_object(this_player(), "players/catwoman/tl.c");
      command("look", TP);
  move_object(this_player(), this_object());
return 1; }
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

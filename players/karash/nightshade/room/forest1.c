inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("rothe"))
{
ob=clone_object("players/nightshade/mons/rothe");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = "Deep Forest";
     long_desc =
"The forest thins out here some which allows you to see a small cave to the west.\n";
      dest_dir = 
      ({ "/players/nightshade/room/forest7", "south",
    "players/nightshade/room/forest2", "east",
 "players/nightshade/room/c1", "west",
      });
}

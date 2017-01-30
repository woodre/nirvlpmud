inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = "Deep Forest";
     long_desc =
"Here the might Bronzewoods are mixed together with both hornwood\n"+
"and Phost trees. The Hornwoods trunk and branches are unusually\n"+
"straight and the bark is a jet black. The Phost trees are shaggy\n"+
"looking and have leaves that are very broad. The Phost also gives\n"+
"off a soft glow when it has been dead for awhile. A branch might\n"+
"make a decent torch.\n";
      dest_dir = 
      ({ "/players/nightshade/room/forest16", "south",
    "players/nightshade/room/forest11", "east",
 "players/nightshade/room/forest4", "north",
"players/nightshade/room/trail4", "west",
      });
}
monster()
{
object mon;
if(!present("knight"))
{
mon=clone_object("players/nightshade/mons/knight");
move_object(mon, this_object());
}
}

inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
monster();
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
      ({ "/players/nightshade/room/forest14", "south",
    "players/nightshade/room/forest9", "east",
 "players/nightshade/room/forest2", "north",
"players/nightshade/room/forest7", "west",
      });
}
monster()
{
object x;
if(!present("rothe"))
{
x=clone_object("players/nightshade/mons/rothe");
move_object(x, this_object());
}
}

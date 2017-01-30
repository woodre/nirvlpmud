inherit "players/nightshade/new_room";
object penis;
reset(arg){
   if(arg) return;
if(!present("notice"))
{
penis=clone_object("players/nightshade/misc/notice2");
move_object(penis, this_object());
}
        set_light(1);
        short_desc = "Road to Ledsville";
     long_desc =
"This is a small, well used cobblestone road leading into Ledsville.\n"+
"A little ways to the south is an interesting looking fountain while\n"+
" to the southwest is an Alchelmy shop and to the southeast is a small\n"+"Magic shop.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad2", "south",
      "players/nightshade/room/trail8", "north",
      });
}

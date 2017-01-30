inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("troll"))
{
ob=clone_object("players/nightshade/mons/troll");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"The cave is damp and slightly dark. The walls are slimy and covered\n"+
"with an odd species of fungi which glows a faint gold color.\n";
      dest_dir = 
({
"players/nightshade/room/c6", "north",
   "players/nightshade/room/c10", "south",
      });
}

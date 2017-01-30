inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("black_opal"))
{
ob=clone_object("players/nightshade/misc/black_opal");
move_object(ob, this_object());
}
if(!present("moonstone"))
{
ob=clone_object("players/nightshade/misc/moonstone");
move_object(ob, this_object());
}
if(!present("topaz"))
{
ob=clone_object("players/nightshade/misc/topaz");
move_object(ob, this_object());
}
if(!present("onyx"))
{
ob=clone_object("players/nightshade/misc/onyx");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"Hephestus keeps his bountiful treasure in this large room. As\n"+
"you look around you see vast chunks of rock that has been melted\n"+
"by the reds incredible breath. If you are here you must be very\n"+
"lucky or very brave.\n";
      dest_dir = 
({
"players/nightshade/room/c27", "south",
      });
}

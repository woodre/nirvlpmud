inherit "players/nightshade/new_room";
object ob;
reset(arg)
{
if(!present("monster"))
{
ob=clone_object("players/nightshade/mons/nameless");
move_object(ob, this_object());
}
if(arg) return;
set_light(1);

short_desc = "Beach";
long_desc =
"The beach continues southeast and back southwest. The white, clean\n"+
"sand squeeks as you walk along in it. Driftwood and jellfyfish are"+
"scattered in different places. A trail breaks off from the beach and\n"+
"leads south and east into the forest.\n";
dest_dir = ({
"players/nightshade/room/i7", "southwest",
"players/nightshade/room/i5", "northeast",
"players/nightshade/room/i9", "south",
"players/nightshade/room/i12", "east",
});
}

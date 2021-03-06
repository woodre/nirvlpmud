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
"The beach continues northeast and back southwest. The white, clean\n"+
"sand squeeks as you walk along in it. Driftwood and jellfyfish are"+
"scattered in different places. A trail breaks off from the beach and\n"+
"leads north and west into the forest.\n";
dest_dir = ({
"players/nightshade/room/i3", "northeast",
"players/nightshade/room/i1", "southwest",
"players/nightshade/room/i13", "west",
"players/nightshade/room/i11", "north",
});
}

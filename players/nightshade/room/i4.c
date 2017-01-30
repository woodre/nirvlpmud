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
"The beach continues northwest and back southeast. The white, clean\n"+
"sand squeeks as you walk along in it. Driftwood and jellfyfish are"+
"scattered in different places. A trail breaks off from the beach and\n"+
"leads west and south into the forest.\n";
dest_dir = ({
"players/nightshade/room/i5", "northwest",
"players/nightshade/room/i3", "southeast",
"players/nightshade/room/i11", "south",
"players/nightshade/room/i12", "west",
});
}

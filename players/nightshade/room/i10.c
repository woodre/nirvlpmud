inherit "players/nightshade/new_room";
object ob;
reset(arg)
{
if(!present("guard"))
{
ob=clone_object("players/nightshade/mons/elven_guard");
move_object(ob, this_object());
}
if(arg) return;
set_light(1);

short_desc = "Base of Tree";
long_desc =
"This is a rather large clearing you realize. A huge vallenwood tree\n"+
"dominates the middle of it. An elven guard stands ready for any action.\n"+
"As you look up you see hundreds of wooden bridges connecting the limbs\n"+
"together in a huge network. Way up in top most branches, you notice a rather\n"+
"with many guards outside it. Maybe you could climb the tree.\n";
dest_dir = ({
"players/nightshade/room/i13", "south",
"players/nightshade/room/i12", "north",
"players/nightshade/room/i11", "east",
"players/nightshade/room/i9", "west",
});
}
init()
{
::init();
add_action("do_climb", "climb");
}
do_climb(str)
{
if(!str) return 0;
if(str == "tree")
{
write("You struggle but manage to find a way up.\n");
this_player()->move_player("up the tree#players/nightshade/room/tree1");
return 1;
}
}

inherit "players/nightshade/new_room";
object ob;
reset(arg)
{
if(!present("elf"))
{
ob=clone_object("players/nightshade/mons/elf");
move_object(ob, this_object());
}
if(arg) return;
set_light(1);

short_desc = "Inland Forest";
long_desc =
"This is a small forest on the island. The trees are tall and thick.\n"+
"You wonder how such large trees can grow in such a limited environment.\n"+
"Must be magic you mumble. To the south is a small clearing with a very\n"+
"large tree growing in the middle. You can see a rather large house buillt\n"+
"into the limbs. You notice a large cave hidden behind the large\n"+
"trunk and low-hanging branches of the trees.\n";
dest_dir = ({
"players/nightshade/room/i10", "south",
"players/nightshade/room/i5", "north",
"players/nightshade/room/i4", "east",
"players/nightshade/room/i6", "west",
});
}
init()
{
::init();
add_action("do_enter", "enter");
}
do_enter(str)
{
if(!str) return;
if(str == "cave")
{
write("You cautiously enter the cave.\n");
this_player()->move_player("leaves into the cave#players/nightshade/room/vamp_cave");
return 1;
}
}

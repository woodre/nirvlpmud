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
"Must be magic you mumble. To the west is a small clearing with a very\n"+
"large tree growing in the middle. You can see a rather large house buillt\n"+
"into the limbs.\n";
dest_dir = ({
"players/nightshade/room/i10", "west",
"players/nightshade/room/i4", "north",
"players/nightshade/room/i2", "south",
"players/nightshade/room/i3", "east",
});
}

inherit "players/nightshade/new_room";
reset(arg)
{
if(arg) return;
set_light(1);

short_desc = "Beach";
long_desc =
"The beach continues northwest and back southwest. The white, clean\n"+
"sand squeeks as you walk along in it. Driftwood and jellfyfish are"+
"scattered in different places. A trail breaks off from the beach and\n"+
"leads west into the forest.\n";
dest_dir = ({
"players/nightshade/room/i4", "northwest",
"players/nightshade/room/i2", "southwest",
"players/nightshade/room/i11", "west",
});
}

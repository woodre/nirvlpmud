inherit "players/nightshade/new_room";
reset(arg)
{
if(arg) return;
set_light(1);

short_desc = "Beach";
long_desc =
"The beach continues southeast and back northeast. The white, clean\n"+
"sand squeeks as you walk along in it. Driftwood and jellfyfish are"+
"scattered in different places. A trail breaks off from the beach and\n"+
"leads east into the forest.\n";
dest_dir = ({
"players/nightshade/room/i6", "northeast",
"players/nightshade/room/i8", "southeast",
"players/nightshade/room/i9", "east",
});
}

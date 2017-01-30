inherit "players/nightshade/new_room";
reset(arg) {
if(arg) return;
 set_light(1);
short_desc  = "Cave Mouth";
long_desc= 
"Large groups of rocks block your way in other directions so it\n"+
"seems the only way to go would be into the cave to the south or\n"+
"to follow the small stone trail to the east.\n";
dest_dir=
({
"players/nightshade/rum/7", "east",
"players/nightshade/rum/4", "south",
});
}

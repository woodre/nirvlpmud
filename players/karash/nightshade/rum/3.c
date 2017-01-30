inherit "players/nightshade/new_room";
reset(arg) {
if(arg) return;
   set_light(1);
   short_desc = "T-intersection";
   long_desc = 
"There is a torch hanging in a cast iron holder firmly attached to the wall in\n"+
"front of you. The stony path leads off the the east and to the west. Although\n"+
"the torch does brighten things a bit that is not what is causing the illumination.\n";
dest_dir = 
({
"players/nightshade/rum/2", "south",
"players/nightshade/rum/9", "east",
"players/nightshade/rum/4", "west",
});

items =
({
"torch", "An ordinary torch",
"holder", "An ordianry torch holder",
});
}

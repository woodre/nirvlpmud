inherit "/players/nightshade/new_room";
reset(arg) {
if(arg) return;
   set_light(1);
   short_desc = "Cave Trail";
   long_desc  = 
"Smooth, grey walls close you in as you walk down this slightly lit trail.\n"+
"It seems to be well used which affords you some security. Up ahead the trail\n"+
"gets brighter.\n";
dest_dir=
({
"players/nightshade/rum/3", "north",
"players/nightshade/rum/1", "south",
});
}

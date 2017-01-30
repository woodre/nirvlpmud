inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc =
"The wall makes its way east and west. Looking over on the outside, you see\n"+
"a deer drinking water from a small stream. Suddenly a froghemoth reaches up\n"+
"with its tentacles and sucks the deer into the water to be gone forever. \n"+
"Other than that. Nothing has much interest. A short figure stands to the\n"+
"east watching out over the forest.\n";
dest_dir =
({
"players/nightshade/room/castle/castle13", "east",
"players/nightshade/room/castle/castle15", "west",
});
}

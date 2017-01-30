inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "In tower";
   long_desc = 
"From up here you can see far and wide. On the horizon to the east you can\n"+
"see the tall spires of many mountains reaching up into the sky. There also\n"+
"is a cloud of dust that seems to be moving in this direction. You over hear\n"+
"the archers talking to each other about a war that will probably come about\n"+
"pretty soon. It makes you nervous.\n";
dest_dir = 
({
"players/nightshade/room/castle/castle11", "down",
});
}

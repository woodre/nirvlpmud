inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Caemlyn Wilderness";
long_desc =
"   Scattered wild rose and ferns mix with brush on both\n"+
"sides of the narrow path.  A large, lichen covered rock\n"+
"rests beside the path to the east.  Several narrow, dark\n"+
"holes surround the base of the rock.\n";

items = ({
"holes",       "Small rodent holes. They look harmless'",
"rock",        "A very large boulder resting upon the ground. You\n"+
               "can 'climb the boulder' if you are strong enough",
"lichen",      "Small, delicate, lacy leaves of grey and green covering the rock",
"rose",        "Thorny and lanky, growing small blossoms of colorful\n"+
               "petals of red, yellow, and white",
"ferns",       "Lacy green leaves with black stems, growing in small clusters",
"path",        "A well worn dirt path which it seems you must follow",
"brush",       "Bushes with long thorns and thick wild rose trailers",
});

dest_dir = ({
   "/players/fakir/caemlyn/room3.c", "north",
});
}
init()  {
  ::init();
    add_action("climb_boulder","climb");
   
}
climb_boulder(str)  {
if(str != "the boulder") {
notify_fail("You cannot climb that.\n");
return 0; 
}
tell_room("players/fakir/caemlyn/room92.c", this_player()->query_name()+" arrives.\n");
move_object(this_player(),"/players/fakir/caemlyn/room92.c");
command("look",this_player());
return 1;
}



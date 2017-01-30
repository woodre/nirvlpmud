inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Caemlyn Wilderness";
long_desc =
"   Wild roses grow in abundance here, mixed with maidenhair ferns\n"+
"and short bushes of many kinds.  The path skirts the edges of the\n"+
"dense brush.\n";

items = ({
"roses",       "Thorny and lanky, growing small blossoms of colorful\n"+
               "petals of red, yellow, and white",
"ferns",       "Lacy green leaves with black stems, growing in small clusters",
"bushes",      "Mostly dense and thick brush, with sharp thorns...but it\n"+
               "looks like you may be able to 'slip past' the bushes south",
"path",        "A well worn dirt path which it seems you must follow",
"brush",       "Bushes with long thorns and thick wild rose trailers",
});

dest_dir = ({
   "/players/fakir/caemlyn/room90.c", "west",
   "/players/fakir/caemlyn/room2.c", "southeast",
});
}
init()  {
  ::init();
    add_action("slip_past","slip");
}
slip_past(str)  {
if(str != "past bushes") {
notify_fail("You cannot do that.\n");
return 0; 
}
tell_room("players/fakir/caemlyn/room91.c", this_player()->query_name()+" arrives.\n");
move_object(this_player(),"/players/fakir/caemlyn/room91.c");
command("look",this_player());
return 1;
}



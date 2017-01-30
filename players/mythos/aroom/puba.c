inherit "room/room";
reset(arg) {
    move_object(clone_object("/players/mythos/aroom/pub1.c"),this_object()); 
  if(!arg) {
  set_light(1);
    short_desc = "Sake Bar";
    long_desc =
      "You enter a small bar.  The lights are dim and the atmosphere\n"+
      "is quiet.  It is very relaxing here.  Go ahead 'order' the\n"+
      "drinks you wish to fill your needs.  There is a sign\n"+
      "showing you what you can order.\n";

  dest_dir = ({
    "/players/mythos/aroom/village.c","north",
  });
} }

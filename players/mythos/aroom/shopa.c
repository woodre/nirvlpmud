inherit "room/room";
reset(arg) {
    move_object(clone_object("/players/mythos/aroom/shop1.c"),this_object()); 
  if(!arg) {
  set_light(1);
    short_desc = "Place of All Things";
    long_desc =
      "You have entered THE SHOP.  This is where things may\n"+
      "be sold and bought.  You may also 'value' items\n"+
      " and 'list' items in the shop.\n";

  dest_dir = ({
    "/players/mythos/aroom/village.c","south",
  });
} }

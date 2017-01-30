inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Balcony";

      long_desc =
      "You stand on a small balcony with an arched ceiling that\n"+ 
      "overlooks the courtyard to the south and the gateway to\n"+ 
      "the north. Under the archway, doors are set to the east\n"+ 
      "and west. The walkway runs off to the south\n";

   items = ({
     "courtyard","It's quite beautiful, isn't it?",
     "doors","The door to the west is locked. The east door is open",
     "gateway","A large gateway stands directly below you",
     "walkway","A marble walkway runs above the courtyard",
  });

  dest_dir = ({
      "/players/arrina/palace/guestroom.c","east",
      "/players/arrina/palace/masterbed.c","west",
      "/players/arrina/palace/walkway.c","south",
  });
} }

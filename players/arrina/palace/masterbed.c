inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Master Bedroom";

      long_desc =
     "You are standing in a sleeping chamber for the masters\n"+
     "of this castle.  A large bed lies before you with draped\n"+ 
     "curtains hanging around it from the ceiling.  The warmth\n"+
     "of a blazing fireplace fills the room.  Magnificent tapestries\n"+
     "adorn the walls.\n";

   items = ({
    "bed","You move the curtains to see a plush bed covered with pillows",
    "fireplace","You warm your hands before the fire",
    "west tapestry","Behind a tapestry on the west wall is a hidden door",
    "tapestries","The tapestries are priceless",
  });

  dest_dir = ({
      "/players/arrina/palace/balcony.c","east",
      "/players/arrina/palace/alcove.c","hidden west door",
  });
} }

inherit "room/room";
reset(arg) {
  set_light(1);
short_desc=("A tropical island");
long_desc=
   "This is a beautiful tropical island. The beach is covered\n"+
   "with blinding white sand and the water is a crystal clear blue.\n"+
   "There are sand dunes off in the distance capped with mounds of soft,\n"+
   "green grass. Little wild flowers  also grow on the dune.\n"+
   "Large palm trees sway back and forth from the cool breeze.\n"+
   "You feel the breeze carress your face, lifting your\n"+
   "hair away from your face.  Near the shore line is a little\n"+
   "table for two.  The waves lap up and envelope the feet\n"+
   "and rushes back to the open sea, foaming and rolling.\n"+
   "The sun is setting slowly. An orange glow is cast over the\n"+
   "little isle, setting the mood for love and romance.\n";
  dest_dir=
({
    "/room/church", "north",
    "/players/nooneelse/black/cult_upper_hall", "hall"
   });
  }

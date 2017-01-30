inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  You are walking along the Main Road of Trixtown, to the west you can see\n"+
"where the town ends, to the east you can see the center of the town.\n";
   short_desc = "Trixtown Main Road";
    dest_dir = ({ "/players/trix/castle/town/mainroad5.c","west",
                  "/players/trix/castle/town/mainroad3.c","east"});
}

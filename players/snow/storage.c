inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc = "You find yourself in a very cold place. \n" +
        "Ice scuptures are numerous but for now this room seems to be\n" +
        "a rather utilitarian storage facility.\n";
   short_desc = "Snow's Storage Facility";
    dest_dir = ({ "/room/church","church",
                  "/room/shop", "shop",
                     "/room/adv_guild","advance",
              });
}

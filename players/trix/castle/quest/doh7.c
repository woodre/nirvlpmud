inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A blind gallery that leads nowhere, it's plugged by a pile of rocks that bar \n"+
              "your way.\n";
    short_desc = "A blind gallery";
    dest_dir = ({
                  "/players/trix/castle/quest/Edof7","north"
                                                        });
}
realm(){return "NT";}

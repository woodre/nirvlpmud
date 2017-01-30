inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A huge gallery lit by the usual pale green light, it curves from north to east.\n";
    short_desc = "A huge gallery";
    dest_dir = ({
                  "/players/trix/castle/quest/dog4","north",
                  "/players/trix/castle/quest/doh5","east"
                                                        });
}
realm(){return "NT";}

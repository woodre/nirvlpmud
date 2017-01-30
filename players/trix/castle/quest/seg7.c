inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"  The tunnel curves from north to east around a right angle, forcing the\n"+
"water to the east.  A hole in the wall leads northeast.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/sef7","north",
                  "/players/trix/castle/quest/Eseg8","east",
                  "/players/trix/castle/quest/sef8","northeast"
                                                        });
}
realm(){return "NT";}

inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"\n"+
"This room seems to be the Banquet hall of the castle. The first thing\n"+
"you recognize is the stench of rotten food coming from the table.\n"+
"Along the table are chairs covered in old dried up blood, some of them\n"+
"still have their owners in them.\n";
    short_desc ="The banquet hall";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first9.c","north",
                  "/players/trix/closed/guild/castle/first3.c","east"
                                                        });
}
realm(){return "NT";}

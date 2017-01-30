inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"  You are at a junction of the drainage system, where several tunnels lead\n"+
"in different directions.  The water flows north and south.  A hole leads west.\n";
    short_desc = "A dirty sewer";
    dest_dir = ({
                  "/players/trix/castle/quest/see8","west",
                  "/players/trix/castle/quest/sed9","north",
		"/players/trix/castle/quest/sef9","south"
/*  took out sw exit to change quest  -Eurale
                  "/players/trix/castle/quest/sef8","southwest"
*/
                                                        });
}
realm(){return "NT";}

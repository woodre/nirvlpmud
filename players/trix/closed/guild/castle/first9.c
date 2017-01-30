inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"This room looks as if it was once used to prepare food for the royal house.\n"+
"With cobwebs brushing your face you believe that this kitchen hasn't been\n"+
"used for a while. As you stand there are reflecting on the room you swear\n"+
"you can still smell the food of the pasts.\n";
    short_desc ="A dusty kitchen";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first8.c","south",
                  "/players/trix/closed/guild/castle/first4.c","east"
                                                        });
}
realm(){return "NT";}

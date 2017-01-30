inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"This is the chapel organ room. \"I hope you enjoy your stay. Aha! ha! ha!ha! ha!\"\n"+
"sings a ghostly pianist. To the west is the altar room it is the only exit.\n";
    short_desc ="The organ room";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first5.c","west"
                                                        });
}
realm(){return "NT";}

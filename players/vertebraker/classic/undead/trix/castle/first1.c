inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"You stand before the gate house of the Castle of Eternal Night.\n"+
"The two towers that make up the gate house stand least the height of\n"+
"50 men. The brick is old and blood stained from wars long passed.\n"+
"The battlements are dark and brooding. To the north the drawbridge\n"+
"is down but by no means welcoming.\n";
    short_desc ="A castle entrance";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first2","north"
                                                        });
}
realm(){return "NT";}





 

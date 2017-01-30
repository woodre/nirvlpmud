inherit "room/room";
 
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc = 
"  You're on the southern part of Trixtown 1st street, the commercial part of\n"+
"the town.  To the south you can see the bank.\n";
   short_desc = "Trixtown 1st street";
   dest_dir = ({ "/players/trix/castle/town/mainroad3.c","north",
                 "/players/trix/castle/town/bank1.c","south"});
}

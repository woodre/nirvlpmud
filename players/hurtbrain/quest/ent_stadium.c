
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "Hotel entrance" ;
    long_desc = "This is the entrance of a beautiful 5-stars hotel. You\n"+
    "never saw something like this. There is a series of columns on the\n"+
    "sides of a wonderful staircase. Three livery servants quicly are\n"+
    "near you: one gets your baggage, the second pays the taxist and the\n"+
    "third is waiting to accompany you to the doors of the hotel.\n";
   dest_dir =
   ({
    "/players/hurtbrain/quest/stadium1","east",
    "/players/hurtbrain/quest/taxi","taxi",
    } ) ;
    set_light(1);
}
realm(){return "NT";}

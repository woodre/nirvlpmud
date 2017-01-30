#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int play;
reset(int arg) {
   play = 1;
   if(arg) return;
   set_id("jukebox");
   set_alias("Jukebox");
   set_short(RED+"A Jukebox"+NORM);
   set_long(
      "This is an old jukebox.  It has buttons to choose the record\n"+
      "you want to play, and a coin slot to pay for it.  There is only\n"+
      "one record inside, so for 1 coin, you could "+MAG+"play song."+NORM+"\n");
   set_value(0);
}
get() {return 0;}
init() {
   ::init();
   add_action("jukebox","play");
}
jukebox(arg) {
   if(arg != "song") {return 0;}
   if(this_player()->query_money() < 1) {
      write("You're flat broke.\n");
      return 1; }
   if(play == 2) {write("The jukebox is already playing.\n"); return 1; }
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Guitar music starts playing."+NORM+"\n");
   TP->add_money(-1);
   play = 2;
   
   call_out("song",4);
   call_out("song2",6);
   call_out("song3",9);
   call_out("song4",17);
   call_out("song5",21);
   call_out("song6",24);
   call_out("song7",30);
   call_out("song8",32);
   call_out("song9",35);
   call_out("song10",40); 
   call_out("song11",44);
   call_out("song12",47);
   call_out("song13",51);
   return 1; }
song() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Just two good old boys."+NORM+"\n");
   return 1; }
song2() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Never meanin no harm."+NORM+"\n");
   return 1; }
song3() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Beats all you never saw, been in trouble\n"+
      "with the law since the day they was born."+NORM+"\n");
   return 1; }
song4() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Straightening the curves."+NORM+"\n");
   return 1; }
song5() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Flattening the hills."+NORM+"\n");
   return 1; }
song6() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Someday the mountain might get em, but\n"+
      "the law never will."+NORM+"\n");
   return 1; }
song7() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Making their way "+NORM+"\n");
   return 1; }
song8() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"the only way they know how."+NORM+"\n");
   return 1; }
song9() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"But that's just a little bit more than the\n"+
      "law will allow."+NORM+"\n");
   return 1; }
song10() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Just two good ole boys."+NORM+"\n");
   return 1; }
song11() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Wouldn't change if they could."+NORM+"\n");
   return 1; }
song12() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"Fightin the system, like a true modern day Robin Hood."+NORM+"\n");
   return 1; }
song13() {
   tell_room("/players/jenny/dukes/rooms/nest1.c",BOLD+"The music stops."+NORM+"\n");
   play = 1;
   return 1; }

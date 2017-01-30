#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
/*
 if (!present("flier")) {
  move_object(clone_object("/players/francesco/kale/items/contest.c"),
	this_object());  }
*/

set_light(1);

short_desc = ""+HIR+"C"+NORM+YEL+"o"+HIY+"l"+HIG+"o"+HIB+"r"+HIM+"s"+NORM+" entrance";
long_desc =
     "   This room has been decorated with several posters and drawings on \n"+
     "the walls.  It is of a circular shape, about 20 feet in diameter.\n"+  
     "Some toys are scattered about.  An ample chandelier hangs down from \n"+
     "the ceiling and lights the room.  A board is suspended on a stand.\n",

items = ({
   "walls","They are covered with some posters",
   "posters","They depict some typical shapes obtained by the fractal theory",
   "drawings","They show some typical shapes obtained by the theory of the diffraction of the light",
   "chandelier","It is made of three tubes, which emit a white shining light",
   "ceiling","It is about twelve feet high",
   "board","A black board holding a flier which you could read",
   "stand","It has three legs and holds a the board",
   "toys",""+HIR+"Th"+NORM+YEL+"e "+HIY+"to"+HIG+"ys"+HIB+" a"+HIM+"re"+NORM+""+HIR+" m"+NORM+YEL+"ul"+HIY+"ti"+HIG+"co"+HIB+"re"+HIM+"d!"+NORM+"",
});

dest_dir = ({
  "/room/forest11.c","exit",
});

}

init(){
  ::init();
  add_action("read","read");
  add_action("random_move","enter");
return 1;}

read(str){
  if(!str) {notify_fail("Read what?\n"); return 0;}
  if(str == "flier"){
    write("The "+HIR+"C"+NORM+YEL+"o"+HIY+"l"+HIG+"o"+HIB+"r"+HIM+"s"+NORM+" area is actually open only for the kaleidoscopic part.\n"+
          "The kaleidoscopic area can be 'enter'ed from this room.\n"+
          "Just like any other kaleidoscope, it will bring you to an\n"+
          "endless combination of shapes and colors.  Of course, it\n"+
          "is impossible to predict what kind of combination you will\n"+
          "see and what kind of inhabitants (inhabitants??) you will\n"+
          "meet inside.  Likewise, it is unpredictable how to exit\n"+
          "the area, even though it will not be very difficult.\n"+
          "For the best effects, please turn off your brief toggle.\n"+
          "Enjoy the multishaped, multicolored features of the \n"+
          ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"!\n");    return 1;}
  notify_fail("Read what?\n"); return 0;}

query_no_fight() {return 1;}

random_move(str) {
   if(!str) {notify_fail("Enter what?\n"); return 0;}
   if(str=="kale" || str=="kaleido" || str=="kaleidoscope") {
   this_player()->move_player("to look at the endless patterns of the kaleidoscope#players/francesco/kale/rooms/kale"+random(50)+".c");
   return 1;}
   notify_fail("You cannot enter the "+str+".\n"); return 0;
}
 

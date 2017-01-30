#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "A paved road" ;
long_desc =
     "   This is a typical ancient roman road.  The pavement is made by \n"+
     "large rectangular stones with a slight slope towards the sides.\n"+
     "Therefore, the rain water cannot stagnate in the middle.  Far to\n"+
     "the north the Coliseum is visible.  On the side of the road, there\n"+
     "is an info booth.\n",

items = ({
 "pavement","The pavement is uneven due to the irregularities of the stones",
 "stones","Each stone is about three by three feet wide.\n"+
          "They are well levigated by the millennial use",
 "coliseum","The famous, huge Coliseum of the ancient Roma, a must see",
 "Coliseum","The famous, huge Coliseum of the ancient Roma, a must see",
 "booth","On its outer wall there is a map.  You might want to read it",
 });

dest_dir = ({
  "/players/francesco/roma/rooms/vi4.c","south",
  "/players/francesco/roma/rooms/col/co01.c","north"
});

}


init(){
      ::init();
     add_action("read","read");
 }


read(str) {
 if(!str) {notify_fail("Read what?\n"); return 1;}
 if(str=="map") {
    write("The map had been torn out, only a small text can be read on it.\n");
    return 1;}
 if(str=="text") {
    write("The text reads: \nhttp://www.virtualrome.com/english/virtualtour/colosseo.html\n");
    return 1;}
return 1;}



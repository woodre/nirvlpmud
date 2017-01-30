#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "A wide avenue" ;
long_desc =
     "   At the west end of Via dei Fori Imperiali, a very wide avenue which\n"+
     "crosses the Roman Forum and the downtown of Roma.  On the sidewalk,\n"+
     "there is an info booth.\n",

items = ({
 "forum","The Roman Forum is an archaelogical area of about one square mile",
 "Forum","The Roman Forum is an archaelogical area of about one square mile",
 "sidewalk","The sidewalk is very ample",
 "booth","On its outer wall there is a map of Roma.  You might want to read it",

});

dest_dir = ({
  "/players/francesco/roma/rooms/vi4.c","east",
  "/players/francesco/roma/rooms/vi2.c","up"
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
    write("The text reads: \nhttp://www.virtualrome.com/english/virtualtour/\n");
    return 1;}
return 1;}



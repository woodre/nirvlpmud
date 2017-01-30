inherit "/players/jenny/rhps/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+RED+"To the north, you can hear the sounds of\n"+
                      "people having a good time."+NORM+"");
     set_smell(""+GRN+"The air smells a little dank."+NORM+"\n");
short_desc=(""+RED+"~ "+NORM+""+BOLD+"Dr. Frank N. Furter's Castle "+NORM+""+RED+"~"+NORM+"");
long_desc=
"Upon entering this dimly lit castle, you get the feeling this\n"+
"is going to be an interesting visit.  This hallway looks quite\n"+
"unimpressive.  Cobwebs can be seen all over the place.  A\n"+
"grandfather clock stands near the wall, next to an old china\n"+
"cabinet.\n";
items = ({
"cobwebs","They are all over.  The maid must not be doing a very good job.",
"clock","A very old grandfather clock.",
"grandfather clock","A very old grandfather clock.",
"cabinet","An old china cabinet, which contains some worthless looking trinkets.",
"china cabinet","An old china cabinet, which contains some worthless looking trinkets",

});
dest_dir = ({
  "/players/jenny/rhps/rooms/castle2","north",
 "/players/jenny/rhps/rooms/entrance","exit",
});
}
init() { 
    ::init(); 
if(TP->query_level() < 15) {
   this_player()->set_fight_area();

}
}

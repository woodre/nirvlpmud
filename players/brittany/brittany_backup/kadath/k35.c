#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     You end up in a dark tunnel.  To the west light can be seen\n"+
   "through a small opening.  The opening looks small and there might\n"+
   "not be a way back.\n";

   items = ({
         "light","A bright light at the end of the tunnel, which\n"+
         "seems to be an opening",
         "pyramid","The pyramid has a polygonal base with triangular\n"+
         "sides that meet at an apex",
         "opening","A bright light is coming from a small opening",
         "tunnel","The tunnel is dark, a bright light is coming from the end",
          });

   dest_dir = ({
         "/players/brittany/kadath/k37.c","opening",
         "/players/brittany/kadath/k30.c","out",
});
}

init() {
    ::init();
    add_action("opening","opening");
    add_action("out","out");
   add_action("search","search");
    }
 
out(str){
write("You climb out of the tunnel.\n\n");
say(tpn+"  climbs out of the tunnel.\n");
tp->move_player("out#/players/brittany/kadath/k30.c");
return 1;
}

opening(str){
   write("You enter the opening.\n\n");
   say(tpn+"  enters the opening.\n\n");
    tp->move_player("into the opening#/players/brittany/kadath/k37.c");
    return 1;
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

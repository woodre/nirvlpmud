#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Dragonland"+NORM;
   long_desc =
   "     A high range of mountains surround the area.  The mountains\n"+
   "are in the shape of a bear.  One mountain is a steeply sloped peak,\n"+
   "bare of any vegetation.  West of here, in between some more mountains\n"+
   "is a large passage.  The low-branched trunk is downward.\n";
   
   items = ({
         "trunk","A big tree with low branches",
         "passage","A small opening",
         "mountain","A large mass of the earth's surface, rising 100 feet high",
         "mountains","Several masses of the earth's surface, that resemble a bear",
          });

   dest_dir = ({
         "/players/brittany/xanth/dragonet.c","west",        
              });
}

init() {
   ::init();
   add_action("search","search");
  add_action("down","down");
  }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

 down(str){               
write("You  C L I M B  down the tree.\n");
   say(tpn+"  C L I M B S  down the tree and disappears.\n");
tp->move_player("down#/players/brittany/xanth/gar1.c");
return 1; }

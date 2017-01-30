#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A veggie garden"+NORM;
   long_desc =
   "     The patch of cabbages seem to end on this path.  At the end\n"+
   "of the path you notice a lake of some placid, brownish liquid.\n";
   
   items = ({
         "cabbages","A patch of cruciferous plants, with short stems and leaves formed\n"+
         "into a compact, edible head",
         "liquid","A wet substance made out of fluid, maybe you could 'dive' in",
         "lake","A substance made out of liquid",
         "patch","Cabbage plants on the path",
         "path","A trail through a vegetable garden",
          });

   dest_dir = ({
         "/players/brittany/xanth/vgar.c","west",
              });
}

init() {
::init();
   add_action("dive_liquid","dive");
   add_action("dive_fluid","dive");
   add_action("search","search");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
 
dive_liquid(str){
if(!str || str != "liquid") {    
        notify_fail("What do you want to dive into?\n");
        return 0; }

write("You  S I N K  into the liquid.\n");
   say(tpn+"  S I N K S  into the liquid and disappears.\n");
tp->move_player("dive#/players/brittany/xanth/magicastle.c");
return 1; }

dive_fluid(str){
if(!str || str != "fluid") {
        notify_fail("What do you want to dive into?\n");
        return 0; }
 
write("You  S I N K  into the fluid.\n");
   say(tpn+"  S I N K S  into the fluid and disappears.\n");
tp->move_player("dive#/players/brittany/xanth/magicastle.c");
return 1; }

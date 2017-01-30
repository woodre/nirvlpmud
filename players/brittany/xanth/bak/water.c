#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status icicle;

reset(arg) {
   if(arg) return;
   icicle = 1;
   set_light(1);
   
   short_desc = RED+"Water Region"+NORM;
   long_desc =
   "     A strong rainfall pours down in this region.  Water abounds\n"+
   "in all its states.  There is no dry land in this region.  A huge\n"+
   "snow mountain rises out of the center.  Some icicles are forming\n"+
   "down beside a waterfall of melted snow.\n";
   
   items = ({
         "rainfall","A strong downpour of rain",
         "mountain","A huge mountain covered with snow",
         "icicles","Frozen ice from a waterfall of melted snow, maybe you could\n"+
         "'break' one",
         "snow","White snow that is melting and forming icicles",
         "land","The land is very dry",
         "waterfall","Water dripping off of melted snow",
          });

   dest_dir = ({
         "/players/brittany/xanth/fen.c","west",        
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("break_icicle","break");
  }
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
 
break_icicle(str){
object dragon;
if (!str || str != "icicle") {
notify_fail ("What do you want to break?\n");
return 0; }
 
if(icicle) {
write("You break off an icicle and the room fills with a white cloud.\n\n"+
   "A small "+HIW+"WHITE"+NORM+" dragon appears.\n");
  dragon = clone_object("/players/brittany/xanth/NPC/waterling.c");
  move_object(dragon,this_object());
  dragon->attack_object(this_player());
  icicle = 0;
  }
  else write("You break off an icicle.\n");
  return 1; }


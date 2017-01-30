#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status throne;
status dais;

reset(arg) {
   if(arg) return;
   throne = 1;
   dais = 1;
   set_light(0);
   
   short_desc = WHT+"The crawling chaos"+NORM;
   long_desc =
    "     The great domed space is lit up by small clay lamps.\n"+
    "The walls are carved in shocking bas-reliefs, and the center\n"+
    "holds a circular pit surrounded by six stone altars in a ring.\n"+
    "At the farther end there is a high stone dais, reached by five\n"+
    "steps.  On the dais is a golden throne.\n";

   items = ({
         "doorway","The doorway is 30 feet high",
         "walls","The walls are carved in bas-reliefs",
         "bas-reliefs","A small sculpture, with a figure projected\n"+         
         "slightly in the background",
         "center","A circular pit is in the center",
         "pit","A circular pit surrounded by six stone altars",
         "altars","Six stone altars in a circular pit.  There seems to be\n"+
         "no real way to get a closer look from here",
         "lamps","Small clay lamps continously burning to light the room",
         "dais","A raised platform for a throne",
         "steps","There are five steps leading to a high stone dais",
         "throne","A golden throne sitting on the dais.  It looks untouched\n"+
         "maybe you could 'sit' on it",
          });

   dest_dir = ({
         "/players/brittany/kadath/k35.c","out",
         "/players/brittany/kadath/k27.c","south",
});
   
}

init(){
::init();
add_action("sit_throne","sit");
add_action("sit_dais","sit");
add_action("search","search");
add_action("out","out");
add_action("south","south");
}

sit_throne(str){
   object chaos;
   if(!str ||  str != "throne") {
   notify_fail("Where do you want to sit?\n");
   return 0; }
 
   if(throne) {
 write("You sit down and the room turns dim as a yellow GLOW moves closer.\n\n"+
   ""+HIY+"The Crawling chaos appears."+NORM+"\n");
      chaos = clone_object("/players/brittany/kadath/NPC/nyar.c");
      move_object(chaos,this_object());
      chaos->attack_object(this_player());
     throne = 0;
   }
   else write("You sit on the hard throne.\n");
   return 1; }

sit_dais(str){
   object chaos;
   if(!str ||  str != "dais") {
   notify_fail("Where do you want to sit?\n");
   return 0; }
 
   if(dais) {
 write("You sit down and the room turns dim as a yellow GLOW moves closer.\n\n"+
   ""+HIY+"The Crawling chaos appears."+NORM+"\n");
      chaos = clone_object("/players/brittany/kadath/NPC/nyar.c");
      move_object(chaos,this_object());
      chaos->attack_object(this_player());
     dais = 0;
   }
   else write("You sit on the hard throne.\n");
   return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

out(str){
write("You climb out of the opening.\n\n");
say(tpn+"  climbs out of the opening.\n");
tp->move_player("climb#/players/brittany/kadath/k35.c");
return 1;
}

south(str){
write("You end back on the path.\n\n");
say(tpn+"  ends back on the path.\n");
tp->move_player("south#/players/brittany/kadath/k27.c");
return 1;
}

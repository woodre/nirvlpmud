#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = GRN+"Keep of Ganelon"+NORM;
   long_desc =
   "     You are standing in front of a Keep with tall Towers.\n"+
   "There is a drawbrige crossing a moat that is raised.  Towers\n"+
   "are at each of the four corners where its high walls meet.\n"+
   "From within the walls many other towers reach even higher,\n"+
   "tickling the bellies of dark clouds, casting shadows of the\n"+
   "high hills.  The woods are to the north or south of here.n";
   
   items = ({
         "towers","Towers with high walls",
         "drawbridge","An heavy wooden drawbridge about 10 feet wide\n"+
         "maybe you can 'walk drawbridge",
         "walls","High walls of the towers",
         "clouds","Puffy dark cotton balls floating in the sky.",
         "hills","High hills in the background",
         "moat","A deep trench, filled with grass and some mud spots",
         });

   dest_dir = ({
         "players/brittany/amber/shadow.c","north",
         "players/brittany/amber/shadow1.c","south",
          });
   }
   
init() {
   ::init();
   add_action("search","search");
   add_action("walk_drawbridge","walk");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

walk_drawbridge(str){
if(!str || str != "drawbridge") {
        notify_fail("Where do you want to walk?\n");
        return 0; }
 
write("You  W A L K across the drawbridge.\n");
   say(tpn+"  W A L K S across the drawbridge.\n");
tp->move_player("walk#/players/brittany/amber/.c");
return 1; }

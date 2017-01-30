#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = YEL+"Commoner District"+NORM;
long_desc = YEL+
 "   Rowdy yells and slurs can be heard from outside the local tavern.\n"+
 "This part of town seems darker and more sinister than the rest of the\n"+
 "city. The tavern is built from mudcaked stones and has a peat roof with\n"+
 "thick smoke coming from the small chiminey. There is a sign above the\n"+
 "entrance.  There are two alleyways leading to the western towers.\n"+NORM;

items = ({
  "alleyways","They are short little paths leading to the entrance of the\n"+
              "towers in each direction",
  "towers","There is a tower in each corner of this part of the city.\n"+
           "They both loom above the tavern assisting with keeping the lewd\n"+
           "antics of its visitors sheltered from the rest of the city",
  "tavern","A small pub erected here for the people of Tintagel to wet their\n"+
           "whistles and tell their great tales of everyday happenings",
  "stones","Medium sized stones cemented together with mud were used to\n"+
           "build the walls of the tavern",
  "walls","The walls are made from stones cemented together with mud",
  "roof","The roof is made from peat moss",
  "chiminey","A small stone chiminey emits a continue funnel of smoke",
  "smoke","The thick smoke from the chiminey lingers in the air around\n"+
          "the tavern and alleyways",
  "sign","A blackened wooden sign hangs from the entrance of the tavern.\n"+
         "It seems important enough to read",
  "mud","The mud looks like it was sloppily thrown on the stones to hold\n"+
        "them together",
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/square.c","backward",
    "players/nikki/Tintagel/Rooms/pub.c","enter",
    "players/nikki/Tintagel/Rooms/t4.c","east",
    "players/nikki/Tintagel/Rooms/t2.c","west",
    
});
}}

init() {
  ::init();
  add_action("read_sign","read");
  add_action("listen","listen");
}

/*  Read the sign  */
read_sign(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") {
  write("\n\n\t"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIB+"-"+HIG+"-"+HIB+"_"+HIG+"~"+HIB+"*"+HIG+"_"+HIB+"-"+HIG+"-"+HIB+"_"+HIG+"~"+HIB+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"*"+HIG+"~ \n\n"+NORM);
  write("\t"+HIB+"                  _"+HIG+"Athanasius' Tavern"+HIB+"_\n\n"+NORM);
  write("\t"+HIC+"         Special on roast mutton and dwarven ale.\n\n"+NORM);
  write("\t"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIB+"-"+HIG+"-"+HIB+"_"+HIG+"~"+HIB+"*"+HIG+"_"+HIB+"-"+HIG+"-"+HIB+"_"+HIG+"~"+HIB+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"~"+HIG+"*"+HIB+"_"+HIG+"-"+HIB+"-"+HIG+"_"+HIB+"*"+HIG+"~ \n\n\n"+NORM);
  return 1; }

}
listen(str) {
   if(!str) {
            write("What are you trying to listen to?\n");
            return 1; 
              }
   if(str == "yells") {
	    write("The excited yells are coming from inside the tavern.\n");
	    return 1;
              } 
   if(str == "slurs") {
	    write("Lewd insults and insinuations can be heard from outside the tavern.\n");
	    return 1; 
              }  
}

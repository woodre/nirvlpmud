#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define DAEMON "/players/jaraxle/templar/gdaemon.c"

inherit "room/room";
int i;
int nospam;
reset(arg) {
if(!present("templar_guard", this_object())){
for(i=0; i < 3; i++) {
 move_object(clone_object("/players/jaraxle/templar/mobs/templar_guard.c"), this_object());     
    }
 }
  if(arg) return;
set_light(1);
nospam = 0;
short_desc = "Gatehouse "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  The thick, wooden gate of the castle spans between two stone walls.\n"+
"There are several small slits within the stone bricks of the walls,\n"+
"and the gate itself has been carved with an intricate design. A wide\n"+
"bridge leads south away from the castle, well worn with time and use.\n";

items = ({
"gate",
"A huge gate with reinforced beams of steel providing extra strength. As\n"+
"long as these gates remain, it is highly unlikely that anyone will ever\n"+
"be capable of entering. The gate shimmers slightly in the light.",
"portcullis",
"A large steel set of bars that may lower at a command",
"slits",
"Small steel lined slits that allow archers to fire in upon anyone who\n"+
"might be trapped within the confines of the gatehouse",
"walls",
"Finely laid stone bricks that form an extremely strong wall",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/courtyard","north",
"/players/jaraxle/templar/rooms/path.c", "exit",
});

}


init(){
	::init();
	if(!present("KnightInvite", this_player()) && present("templar_guard", this_object()) && !nospam && !this_player()->is_npc()){
    nospam = 1;
	send();
	} 
   add_action("woo", "exit");
   this_player()->set_fight_area();
}

woo(){
 if(DAEMON->gate2_condition() && DAEMON->gate2() == 2 && 
    "/players/jaraxle/templar/rooms/path.c"->query_gate())
  {
   write("The gates are closed!\n");
   return 1;
   }
 return;
 }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

send() {
   object list;
   object cross;
   int i;
   list = users();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
          GRN+"(templar) The Gate Guards shout"+NORM+": Intruders at the front gate!\n");
       }
   }
   call_out("unset_spam", 100);
   return 1;
}


unset_spam(){ nospam = 0; }

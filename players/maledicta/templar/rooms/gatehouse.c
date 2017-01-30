#include "/players/maledicta/ansi.h"
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
 move_object(clone_object("/players/maledicta/templar/mobs/templar_guard.c"), this_object());     
    }
 }
  if(arg) return;
set_light(1);
nospam = 0;
short_desc = "Gatehouse "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"   You stand within a solid gatehouse. Protecting the entrance of\n"+
"the castle is a large wooden gate with a portcullis backing it. Small\n"+
"arrow slits line the inside walls of the gatehouse. To the north is\n"+
"the main courtyard, and to the south is the wilds of nirvana.\n";

items = ({
"gate",
"A huge gate with reinforced beams of steel providing extra strength. As\n"+
"long as these gates remain, it is highly unlikely that anyone will ever\n"+
"be capable of entering",
"portcullis",
"A large steel set of bars that may lower at a command",
"slits",
"Small steel lined slits that allow archers to fire in upon anyone who\n"+
"might be trapped within the confines of the gatehouse",
"walls",
"Finely laid stone bricks that form an extremely strong wall",
});

dest_dir = ({
/*  "/players/jaraxle/templar/rooms/courtyard","north", */
  "/players/maledicta/ares/rooms/city16.c", "exit",
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
    "/players/maledicta/ares/rooms/city16.c"->query_gate()){
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
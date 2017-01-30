#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int num;
string *rooms;

reset(arg)  {
   num = random(sizeof(rooms));
   rooms = ({
         "church","vill_green","vill_track","vill_road1","vill_road2","vill_road3",
         "northroad1","northroad2","northroad3","bank","adv_guild","yard","narr_alley",
         "pub2","alley","hump","wild1","forest9" });
   
   if(arg) return;
   
   set_id("portal");
   set_short("A portal");
   set_long("A strange portal in the center of the room.\n");
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("enter_it","enter");
}

enter_it(arg){
   num = random(sizeof(rooms));
   rooms = ({
         "church","vill_green","vill_track","vill_road1","vill_road2","vill_road3",
         "northroad1","northroad2","northroad3","bank","adv_guild","yard","narr_alley",
         "pub2","alley","hump","wild1","forest9" });
   
   if(arg == "portal"){
      write("You enter the portal out to another realm.\n");
      TP->move_player("into the portal#/room/"+rooms[num]+"");
      say("Appears out of a hazing portal.\n");
      command("look",TP);
      return 1; }
   notify_fail("Enter portal.\n"); return 0; }

get(){
   write("Get what?\n");
   return 0; }

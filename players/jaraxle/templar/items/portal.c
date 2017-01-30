inherit "obj/treasure";
#include "/players/jaraxle/ansi.h"

string location;

reset (arg) {
if(!arg){

  set_id("ring");
  set_alias("portal_object_new");
  set_short(HIY+"a glowing ring of magic"+NORM);
  set_long(
  "  This is a ring of electrical magic which sits on the ground\n"+
  "before you. You may 'Enter' it at anytime.\n");
   
 }  }

  init(){
  ::init();
call_out("destroy_me", 10);  
add_action("enter_it", "enter");
 }
 
destroy_me(){
tell_room(environment(),
"The ring fades away...\n");
destruct(this_object());
return 1;
}

get(){
	return 1;
}

query_weight(){ return 5000; }


enter_it(str){
if(!str){
write("enter what?\n");
return 1;
}

if(str == "ring"){
if(!present("KnightInvite", this_player()) && this_player()->query_level() < 20){
		if(!this_player()->query_pl_k() || this_player()->query_level() < 15){
		write("You do not have the courage to enter the Templar Castle!\n");
		return 1;
		}
	}	
write("You step within the ring of magic...\n");
say(this_player()->query_name()+" enters a glowing ring of magic and vanishes...\n");
say(
"The ring fades away...\n");
move_object(this_player(), "players/jaraxle/templar/rooms/mage_room");
tell_room(environment(this_player()),
this_player()->query_name()+" appears from a glowing ring of magic.\n");
if(!present("KnightTemplar", this_player())){
	send();
}
destruct(this_object());
return 1;
}
return;
}

send() {
   object list;
   object cross;
   int i;
   list = users();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
          GRN+"(templar) The Archmage Shouts"+NORM+": Intruders have entered the guild!\n");
       }
   }
   return 1;
}

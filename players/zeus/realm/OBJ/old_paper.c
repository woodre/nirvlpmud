inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define ALIVE (environment()->is_player() || environment()->is_npc())
reset(arg){

  set_id("paper");
  set_short("An enchanted piece of paper"+HIW+"[8.5]"+NORM);
  set_long(
"This is a piece of white, lined paper.  It has not been hole-punched.\n"+
"There is some neat black writing on it which can be 'read'.  The paper\n"+
"is enchanted and may have strange effects on you.\n");
  set_weight(0);
  set_value(0);
  call_out("home", 120);
  set_save_flag(1);
}

home(){
 if(!environment()) return;
 if(ALIVE && file_name(environment(environment())) !=
	 "players/zeus/realm/main"){
	 tell_object(environment(), 
		 "The enchanted paper blows out of your hand.\n");
	 move_object(this_object(), "players/zeus/realm/main");
	 tell_room(environment(), "A piece of paper blows into the room.\n");
	 call_out("home", 120);
 }
 else if(0 == ALIVE &&
         file_name(environment()) != "players/zeus/realm/main"){
	 tell_room(environment(),
		 "The enchanted paper blows away.\n");
	 move_object(this_object(), "players/zeus/realm/main");
	 tell_room(environment(), "A piece of paper blows into the room.\n");
	 call_out("home", 120);
 }
 else call_out("home", 120);
}

void init(){
    ::init();
  add_action("read_cmd", "read");
}

read_cmd(str){
 if(str != "paper" && str != "piece of paper") return 0;
 if(environment() != TP){
     write("You can't read it while it's on the ground.\n");
     return 1; 
 }
 write(
HIW+"\nThe enchanted piece of paper reads:\n\n"+NORM+
"Welcome to the realms of Zeus.  If you have any questions of comments\n"+
"about any of my code I would appreciate them.  You can mail me, or type\n"+
"'note <whatever>' and I'll get it as soon as I log on.\n\n"+
HIW+"Disclaimer:\n"+NORM+
"This is a dangerous area.  If you die it's your own fault.  You should\n"+
"'ask' Tyborlek and the old gurther for info on the Fallen Lands.\n\n"+
HIW+"Update:\n"+NORM+
"1) You can use the cmd 'feelfollow <player>' in my area. [thanx Snow]\n"+
"   If you dont have a feeler, ask someone to give you one.\n"+
"2) The Fallen Lands has expanded...  You may now travel north to the\n"+
"   area known as Taus.\n\n"+
"Thanks, and enjoy my code..\n\t\t\t"+HIW+"Zeus\n\n"+NORM);
         say(TP->QN+" reads the piece of paper.\n");
 return 1; 
}

prevent_insert(){
          write("A mysterious force is preventing you from doing that.\n");
 return 1; }



inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define ALIVE (living(environment()))
string col;
object paper;
reset(arg){
  if(arg) return;

  col = HIC;
  set_short("An enchanted piece of paper "+col+"[08.23.05]"+NORM);
  set_long(
"This is a piece of white, lined paper.  It has not been hole-punched.\n"+
"There is some neat black writing on it which can be 'read'.  The paper\n"+
"is enchanted and may have strange effects on you.\n");
  set_weight(0);
  set_value(0);
/*
  call_out("home", 120);
*/
  set_save_flag(1);
}

id(str){ return str == "paper" || str == "zeus_paper" || str == "nodrain"; }

home(){
 if(!environment()) return;
 paper = present("zeus_paper", environment());
 if(ALIVE && file_name(environment(environment())) != 
	 "players/zeus/realm/main"){
	 tell_object(environment(), 
		 "The enchanted paper blows out of your hand.\n");
	 move_object(this_object(), "players/zeus/realm/main");
	 tell_room(environment(), "A piece of paper blows into the room.\n");
/*
	 call_out("home", 120);
*/
 }
 else if(0 == ALIVE &&
	 (file_name(environment()) != "players/zeus/realm/main")){
	 tell_room(environment(),
		 "The enchanted paper blows away.\n");
	 move_object(this_object(), "players/zeus/realm/main");
	 tell_room(environment(), "A piece of paper blows into the room.\n");
/*
	 call_out("home", 120);
*/
 }
/*
 else call_out("home", 120);
*/
 if(paper && TO != paper)  /* prevent multi-copies */
   destruct(paper);
}

void init(){
    ::init();
  add_action("read_cmd", "read");
  add_action("wipe", "wipe");
  if (environment())
    if(ALIVE && file_name(environment(environment())) != "players/zeus/realm/main")
      call_out("home", 120);
}

read_cmd(str){
 if(str != "paper" && str != "piece of paper") return 0;
 if(environment() != TP)
 {
     write("You can't read it while it's on the ground.\n");
     return 1; 
 }
 write(
col+"\nThe enchanted piece of paper reads:\n\n"+NORM+
"Welcome to the realms of Zeus.  If you have any questions or comments\n"+
"about any of my code I would appreciate them.  You can mail me, or type\n"+
"'note <whatever>' and I'll get it as soon as I log on.\n\n"+
col+"Updates:\n"+NORM+
"1) The Museum of Legendary Warriors has been reopened.  - Go to the\n"+
"     lounge to see how it works (2n from the entrance).  Please\n"+
"     report any bugs to "+col+"Forbin"+NORM+" via the mudmail system.\n"+
"2) The Fallen Lands is a dangerous and fun high level area.\n"+
"     Talk to Tyborlek and the old gurther for more info.  And if you're\n"+
"     feeling brave, ask Tyborlek what you can do to save the Fallen Lands.\n"+
"     Tyborlek also has information about the Fallen guild which opened\n"+
"     on 4.15.00.\n"+
"3) Inculta Creperum - the dark desert is now open for both mid and high\n"+
"     level players.  If you are midlevel, do not attack a monster that\n"+
"     sounds like it could kick your ass.  It will.\n"+
"\n"+
"Thanks, and enjoy my code..\n\t\t\t"+col+"Zeus\n\n"+NORM);
         say(TP->QN+" reads the piece of paper.\n");
         if(!random(100)) write("\nYou have a strange urge to wipe...\n");
 return 1; 
}

prevent_insert()
{
  write("A mysterious force is preventing you from doing that.\n");
  return 1; 
}

wipe(str){
  if(str != "butt" && str != "ass") return 0;
  if(!present(this_object(), this_player())) return 0;
  write("\n\tYou wipe your "+str+" with the enchanted paper...\n\t"+
    HIY+"Your "+str+" starts to shine like the fucking sun!\n\n"+NORM);
  tell_room(environment(this_player()), "\n\t"+this_player()->query_name()+
    " wipes "+this_player()->query_possessive()+" "+str+" with the"+
    " enchanted paper...\n\t"+HIY+
    capitalize((string)this_player()->query_possessive())+" "+str+" starts"+
    " to shine like the fucking sun!\n\n"+NORM, ({ this_player() }));
  return 1;
}

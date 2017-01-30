#include "/players/fred/mages/defs.h"

cmd_memorize(){
 object room, ob;
 string HERE;
   if(USER->query_ghost()){ 
     write("You can't cast a spell in your condition.\n"); return 1; }
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1; }
   if(RANK < 3) {
      write("You have not mastered this art yet.\n"); return 1; }
   room = ENV(USER);
   if(room->realm() == "NT"){
      write("Your vision becomes blurred, you can't seem to remember this location.\n"); return 1; }
   if(!room->okay_follow()){
      write("Your vision becomes blurred, you can't seem to remember this location.\n"); return 1; }
   HERE = file_name(room);
   ob = present("dark_circle", TP);
   ob->set_tele_room(HERE);  
   ob->ssave();
   write("You focus your "+BOLD+BLK+"dark energy"+NORM+" and memorize your exact location.\n");
   say(TPN+" concentrates "+TP->query_possessive()+" energy on the surrounding room.\n");
   return 1;}
   

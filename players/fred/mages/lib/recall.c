#include "/players/fred/mages/defs.h"

cmd_recall(){
 object room, ob;
 string WHERE;
 int cost;
 cost = 55+random(10);
   if(USER->query_ghost()){ 
     write("You can't cast a spell in your condition.\n"); return 1; }
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1; }
   if(RANK < 3) {
     write("You have not mastered this art yet.\n"); return 1; }
   if(USER->query_sp() < cost){ 
     write("You don't have enough energy.\n"); return 1; }
   room = ENV(USER);
   if(room->realm() == "NT"){
     write("You can not recall from this location.\n"); return 1; }
   ob = present("dark_circle", TP);
   WHERE = ob->query_tele_room();  
   write("You focus all of your "+BOLD+BLK+"dark energy...\n"+
         "   Dark Energy"+NORM+" engulfs you transporting you to another realm...\n");
   say(TPN+" concentrates all of "+TP->query_possessive()+" energy...\n"+
       ""+BOLD+BLK+" Dark Energy"+NORM+" engulfs "+TPN+" as "+TP->query_pronoun()+" is transported elsewhere...\n");
   tell_room(WHERE,
     BOLD+BLK+"Dark Energy fills the room...\n"+
              "The energy slowly dissipates leaving "+capitalize(TPRN)+" behind."+NORM+"\n");
   move_object(TP, WHERE);
   command("look",TP);
   USER->add_spell_point(-cost);
   return 1;}
   

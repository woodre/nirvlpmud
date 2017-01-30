/**************************************************************************
* The Dark Ranger Communicator                             *
* Created by Beck/Russ Warren for Nirvana.                                *
* Last changed 03/20/2002.                                                  *
**************************************************************************/



id(str){ 
   return str == "communicator" || str == "DarkRangerCommunicator" || 
    str == "channel_object"; 
}

query_name(){ return "Dark Ranger Communicator"; }



#include "/players/beck/Defs.h"



#include "/players/beck/Rangers/RangerDefs.h" 

short() {
   string msg;
   msg = "";
   msg = "A Dark Ranger Communicator";
   return msg;
}

void long() {
   write(
      "This communicator is made with a steel case,"+
      " and has a fine quartz crystal.\n"+
      "Looking closer you see little blinking lights\n"+
      "all over the communicator.\n"+
      "");
}

query_auto_load(){ return "/players/beck/Rangers/DarkRangers/DarkRangerCommunicator:"; }



init_arg(){
      
      CHANNEL->ChannelMessage("Power Ranger","["+BOLD+RED+" ENEMY "+OFF+"] Zordon says: "+TP->NAME+" has appeared\n");

}

void init(){
   int i;
  


   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
/*
         if(ENVOB->query_level() > 19){
            write("Wizards may not have this object!!!\n"+
               "Clone HonorRangerCommunicator instead\n");
            destruct(this_object());
         }
*/
         /*carry_weight();*/
                 

         
      }
      
      
   }
   CHANNEL->AddChannel("Power Ranger",TO);
}



get(){ return 1;}
drop(){ 
   
   return 1;
}

QMuffles(){ return 1; }

QRangerType(){
   if(ENVOB){
      if(ENVOB->is_player()){
         if(TP)
            write(RED);
         return "Dark Ranger";
      }
      else{
         if(TP)
            write(BOLD+RED);
         return "Enemy";
      }
   }
}

QRangerColor(){ return " "; }
QRangerAnsi(){ return ""; }





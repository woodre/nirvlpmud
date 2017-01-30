/**************************************************************************
* The Power Ranger Communicator (Guild Object)                            *
* Created by Beck/Russ Warren for Nirvana.                                *
* Last changed 03/20/2002.                                                  *
**************************************************************************/

object recruit;
string sponsor;

id(str){ 
   return str == "recruit object"; 
}

#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h" 


short() {
   string msg;
   msg = "";

   msg += "A Power Ranger Recruit Object (recruit object)";


   return msg;
}

void long() {
   write(
      "This communicator is made with a steel case,"+
      " and has a fine quartz crystal.\n"+
      "Looking closer you see little blinking lights\n"+
      "all over the communicator.\n"+
      "Type 'its morphin time' to join the Power Rangers.\n"+
      "");
}

set_sponsor(arg){ sponsor = arg; }
set_recruit(arg){ recruit = arg; }

recruit_ranger(){
   object communicator;
   if(this_player()->query_guild_name() != 0){
      write("You cannot join the Power Rangers.  You are alread in a guild.\n");
      destruct(this_object());
      return 1;
   }
   
   this_player()->set_guild_name("rangers");
   communicator = clone_object("/players/beck/Rangers/RangerCommunicator.c");
   move_object(communicator, this_player());
   communicator->SRangerColor("Initiate");
   communicator->SRangerNumber("0");
   communicator->SRangerDino("None");
   communicator->SRangerAnimal("None");
   communicator->SRangerWeapon("None");
   communicator->SOldTitle(this_player()->query_title());
   communicator->SOldPretitle(this_player()->query_pretitle());
   write("Zordon tells you: Welcome to the Power Rangers!\n"+
      "I am pleased you have decided to become part of our orginization.\n"+
      "For a period of time you will be an initiate\n"+
      "This will be a chance for you to prove that you are worthy\n"+
      "of the ideals that the Power Rangers hold.\n"+
      "The Power Rangers are given their abilities in order to protect good\n"+
      "and destroy evil.  In time you learn many skills that will help\n"+
      "you to use the power you are given to the fullest.\n"+
      "\n"+"Zordon hands you a Communicator.\n"+
      "Zordon tells you:  This is the device that the Rangers use to\n"+
      "communicator with others.  You must learn how to use\n"+
      "it well, for it has many beneficial functions.\n"+
      "Go now and meet the other Power Rangers, learn about your communicator,\n"+
      "and begin your martial arts training.  You must do all this as\n"+
      "well as begin to start fighting the forces of evil in order\n"+
      "to become a true Power Ranger.\n"+
      "Good Luck, and may the Power protect you!\n"+
      "");
   write("\n");
   communicator->SaveRanger();
   communicator->init_arg();
   communicator->init();
   "/players/beck/Rangers/ViewingGlobe.c"->add_mn(1);
   if(present("honor_ranger_communicator",TP)){
      destruct(present("honor_ranger_communicator",TP));
   }
   CHANNEL->ChannelMessage("Power Ranger", BLUE+"["+OFF+RED+"Power Ranger"+OFF+BLUE+"] "+OFF+recruit->query_name()+" has become a Power Ranger, sponsored by "+sponsor+".\n");
   "/players/beck/Rangers/ViewingGlobe.c"->Color1();
   destruct(this_object());
   return 1;
}

void init(){
   
  
   add_action("recruit_ranger","its_morphin_time");
}



get(){ return 1;}

drop(){ return 1;}






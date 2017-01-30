/******************************************************************
*  Honorary Ranger Communicator                                  *
*  Made by Beck                                                  *
*  Last Changed 1/6/97                                           *
******************************************************************/
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
static int muffles;
id(str){
   return str == "ranger_object" || str == "communicator" ||
   str == "dark_honor_ranger_communicator";
}

short(){ return "A Dark Ranger Communicator"; }

long(){
   write("This is a communications device for the Dark Rangers.\n"+
      "It allows you to converse on the guild channel.\n"+
      "It also signifies your alliance with all Dark Ranger guild members.\n"+
      "For a list of features, type 'ranger'.\n"+
      "");
   return 1;
}

init(){
   if(present("ranger_object",TP) && TP->LEVEL < 20){
      write("You may not be an Ally to both good and evil.\n");
      present("ranger_object",TP)->dest_honor_ranger_communicator();
      return;
   }
   if(member_array(TP->query_real_name(), BANISHED) != -1){
      write(CLR+OFF+"\n\n\n\n\n\n\n");
      write("\n\n\n\n\n\n");
      write("\t");
      write("You will no longer be associated with the Dark Rangers.\n");
      write("\n\n");
      write("\t\t\t"+BLINK+BOLD+RED+"B A N I S H E D"+OFF+"\n\n\n\n\n\n\n\n");
      destruct(this_object());
      return 1;
   }
   add_action("GeneratePower","generate");
   add_action("CheckPower","power");
   add_action("ranger_info","ranger");
   add_action("ranger_talk","drt");
   add_action("ranger_emote","drte");
   add_action("ranger_who","drwho");
   add_action("dest_honor_ranger_communicator","rleave");
   add_action("muff_on","rtm");
   add_action("quit","quit");
   MASTER->AddChannel("Dark Ranger",ENVOB);
}
query_auto_load(){ return "/players/beck/DarkRangers/HonorRangerCommunicator:"; }
QRangerColor(){ return "Ally"; }
CheckPower(){ MASTER->CheckPower("Dark Ranger"); }
GeneratePower(str){ MASTER->GeneratePower(str,"Dark Ranger"); return 1; }
ranger_talk(str){ return MASTER->RangerTalk("rt","Dark Ranger",str); }
ranger_emote(str){ return MASTER->RangerTalk("rte","Dark Ranger",str); }
ranger_who(){ return MASTER->RangerWho("Dark Ranger"); }
dest_honor_ranger_communicator(){
   write("I hope someday you'll be a member again.  Until then, Good Luck.\n");
   MASTER->RemoveChannel("Dark Ranger",ENVOB);
   destruct(this_object());
   return 1;
}
ranger_info(){
   write("Commands availible with the Ranger Communicator.\n"+
      "\n\n"+
      "drt     Allows you to talk on the Dark Ranger guild channel.\n"+
      "drte    Allows you to emote on the Dark Ranger guild channel.\n"+
      "rtm    Turns you guild channel muffles on or off.\n"+
      "drwho   A list of Dark Rangers and Allies currently on Nirvana.\n"+
      "rleave Destruct your honorary communicator.\n"+
      "ranger This help screen.\n"+
      "generate Donate sps to the power pool.\n"+
      "power  Check the Power Pool Levels.\n"+
      "");
   return 1;
}
quit(){
   MASTER->RemoveChannel("Dark Ranger",ENVOB);
   return;
}

get(){ return 1;}
drop(){ return 1;}
muff_on(){
   if(muffles){
      muffles = 0;
      write("Your guild channel muffle is OFF.\n");
      return 1;
   }
   muffles = 1;
   write("Your guild channel muffle is ON.\n");
   return 1;
}
QMuffles(){ return muffles; }

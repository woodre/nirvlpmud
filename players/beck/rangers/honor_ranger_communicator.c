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
   str == "honor_ranger_communicator";
}

short(){ return "A Power Ranger Communicator"; }

long(){
   write("This is a communications device for the Power Rangers.\n"+
      "It allows you to converse on the guild channel.\n"+
      "It also signifies your alliance with all Power Ranger guild members.\n"+
      "For a list of features, type 'ranger'.\n"+
      "");
   return 1;
}

init(){
   if(member_array(TP->query_real_name(), BANISHED) != -1){
      write(CLR+OFF+"\n\n\n\n\n\n\n");
      write("\n\n\n\n\n\n");
      write("\t");
      write("You will no longer be associated with the Power Rangers.\n");
      write("\n\n");
      write("\t\t\t"+BLINK+BOLD+RED+"B A N I S H E D"+OFF+"\n\n\n\n\n\n\n\n");
      destruct(this_object());
      return 1;
   }
   add_action("GeneratePower","generate");
   add_action("CheckPower","power");
   add_action("ranger_info","ranger");
   add_action("ranger_talk","rt");
   add_action("ranger_emote","rte");
   add_action("ranger_who","rwho");
   add_action("dest_honor_ranger_communicator","rleave");
   add_action("muff_on","rtm");
   add_action("quit","quit");
   MASTER->AddRanger("all",ENVOB);
}
query_auto_load(){ return "/players/beck/Rangers/HonorRangerCommunicator:"; }
QRangerColor(){ return "Ally"; }
CheckPower(){ MASTER->CheckPower(); return 1; }
GeneratePower(str){ MASTER->GeneratePower(str); return 1; }
ranger_talk(str){ return MASTER->RangerTalk("rt","all",str); }
ranger_emote(str){ return MASTER->RangerTalk("rte","all",str); }
ranger_who(){ return MASTER->RangerWho("all"); }
dest_honor_ranger_communicator(){
   write("I hope someday you'll be a member again.  Until then, Good Luck.\n");
   destruct(this_object());
   return 1;
}
ranger_info(){
   write("Commands availible with the Ranger Communicator.\n"+
      "\n\n"+
      "rt     Allows you to talk on the Power Ranger guild channel.\n"+
      "rte    Allows you to emote on the Power Ranger guild channel.\n"+
      "rtm    Turns you guild channel muffles on or off.\n"+
      "rwho   A list of Power Rangers and Allies currently on Nirvana.\n"+
      "rleave Destruct your honorary communicator.\n"+
      "ranger This help screen.\n"+
      "generate Donate sps to the power pool.\n"+
      "power  Check the Power Pool Levels.\n"+
      "");
   return 1;
}
quit(){
   MASTER->RemoveRanger("all",ENVOB);
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

/******************************************************************
*  Honorary Ranger Communicator                                  *
*  Made by Beck                                                  *
*  Last Changed 1/6/97                                           *
******************************************************************/
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
static int muffles;
string *Banished;

id(str){
   return str == "ranger_object" || str == "communicator" ||
   str == "honor_ranger_communicator" || str == "channel_object";
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
  /* 03/16/06 Earwax: added this, everything keeps bugging in here */
  if(this_player() && present(this_object(), this_player())) {
    move_object(clone_object("/players/guilds/Rangers/HonorRangerCommunicator"), this_player());
    destruct(this_object());
    return;
  }
   if(!Banished)
      restore_object(RANGERDIR+"BANISHED");
   add_action("GeneratePower","generate");
   add_action("CheckPower","power");
   add_action("ranger_info","ranger");
   add_action("ranger_talk","rt");
   add_action("ranger_emote","rte");
   add_action("ranger_who","rwho");
   add_action("ranger_history","rth");
   add_action("dest_honor_ranger_communicator","rleave");
   add_action("muff_on","rtm");
   add_action("quit","quit");
   CHANNEL->AddChannel("Power Ranger",TO);
}
query_auto_load(){ return "/players/guilds/Rangers/HonorRangerCommunicator:"; }
QRangerType(){ 
   string name;
   if(ENVOB->query_guild_name() == "none") name = "";
   else if(ENVOB->query_guild_name() == "warrior") name = "(Warrior)";
   else if(ENVOB->query_guild_name() == "bard") name = "(Bard)";
   else if(ENVOB->query_guild_name() == "Knights Templar") name = "(Knight)";
   else if(ENVOB->query_guild_name() == "meijin") name = "(Meijin)";
   else if(ENVOB->query_guild_name() == "vampire") name = "(Vampire)";
   else if(ENVOB->query_guild_name() == "healer") name = "(Healer)";
   else if(ENVOB->query_guild_name() == "polymorph") name = "(Poly)";
   else if(ENVOB->query_guild_name() == "decepticon") name = "(Decepticon)";
   else if(ENVOB->query_guild_name() == "dervish") name = "(Dervish)";
   else name = "";
   if(TP)
      write(BOLD+GREEN);
   return "Ally "+name; 
}
CheckPower(){ MASTER->CheckPower("Power Ranger"); return 1; }
GeneratePower(str){ "/players/beck/Rangers/Commands/Generate.c"->RangerPower(str,"Power Ranger"); return 1; }
ranger_talk(str){ return "/players/beck/Rangers/Commands/Rt.c"->RangerPower(str,"Power Ranger"); }
ranger_emote(str){ return "/players/beck/Rangers/Commands/Rte.c"->RangerPower(str,"Power Ranger"); }
ranger_who(str){ return "/players/beck/Rangers/Commands/Rwho.c"->RangerPower(str,"Power Ranger"); }
ranger_history(str){ return "/players/beck/Rangers/Commands/Rth.c"->RangerPower(str,"Power Ranger"); }
dest_honor_ranger_communicator(){
   write("I hope someday you'll be a member again.  Until then, Good Luck.\n");
   CHANNEL->RemoveChannel("Power Ranger",TO);
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
   CHANNEL->RemoveChannel("Power Ranger",TO);
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
QRangerAnsi(){ return ""; }
QRangerColor(){ return ""; }

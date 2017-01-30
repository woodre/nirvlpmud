/*
    The Clan Object   Version 1.0
    Created by Cosmo  May 2000
    Based on Beck's Party Object v2.0
*/

#include "/players/cosmo/closed/ansi.h"
#define MASTER "/players/cosmo/clan/clanmaster.c"
#define TP this_player()
#define ETO environment(this_object())

/* The Clan name - used in the mapping */
string ClanName;

/* The player's rank in the clan */
int ClanRank;

/* The player's title (if Rank == 2) */
int ClanTitle;

/* Toggle for Clan channel muffle */
static int ClanBlock;

id(str){ return str == "clan_object" || str == "clan" || str == "clan object" || str == "implant"; }

reset(arg){
  if(arg) return;
  ClanBlock = 0;
}

long(){
  write("The implant looks to be made of some sort of organic polymer.\n"+
        "It is composed of a series of tough flexible fibers.  The exact\n"+
        "composition is not obvious, but it definitely appears to be\n"+
        "alien material.  The fibers go down into your skin at the base\n"+
        "of your neck, making the implant a permanent part of your body.\n"+
        "At times it feels painful, but it's a worthy tradeoff knowing\n"+
        "that this implant marks your membership in the "+
        BOLD+ClanName+NORM+" Clan.\n\n");
  write("Use "+BOLD+"clan info"+NORM+" for details.\n");
  return 1;
}

query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 0; }

query_auto_load(){
  return "/players/cosmo/clan/clanob:"+ClanName+"#"+ClanRank;
}

init_arg(str){ sscanf(str,"%s#%d",ClanName,ClanRank); }

extra_look(){ return ETO->query_name()+" has an implant on the base of "+
              ETO->query_possessive()+" neck |>."+BOLD+ClanName+NORM+".<|"; }

init(){
  if(!environment()) return;
  if(!MASTER->check_status(ClanName,ETO) && ETO->query_level() < 20) {
    tell_object(environment(),
               "You are no longer a member of the clan. If this\n"+
               "is a mistake, please notify your clan leader.\n");
    destruct(this_object());
  }
  if(!ClanRank) ClanRank = 1;
  if(!ClanTitle) ClanTitle = 0;
  add_action("ClanCommand","clan");
  add_action("FreeSlot","quit");
}

/*  Most commands are passed on to the Master object */
ClanCommand(str){ 
  string name;
  int rank;
  if(!str || str == "info"){ return MASTER->ClanInfo(); }
  if(str == "who"){ return MASTER->ClanWho(ClanName); }
  if(str == "muffle"){
    write("Clan channel muffled.\n"); ClanBlock = 1; return 1;
  }
  if(str == "listen"){
    write("Clan channel activated.\n"); ClanBlock = 0; return 1;
  }
  if(str == "history"){
    write("/obj/user/chistory.c"->query_history(ClanName)+"\n");
    return 1;
  }
  if(str == "leave"){ return MASTER->ClanLeave(ClanName,ETO); }
  if(ClanRank > 5) {
    if(sscanf(str,"add %s",name)){
      return MASTER->ClanAdd(ClanName, name);
    }
    if(sscanf(str,"remove %s",name)){
      return MASTER->ClanRemove(ClanName,name);
    }
    if(sscanf(str,"setrank %s %d",name,rank)){
      return MASTER->ClanModRank(ClanName, name, rank);
    }
  }
  return MASTER->ClanSpeak(ClanName, str, TP->query_name());
}

FreeSlot(){ MASTER->ClanQuit(ClanName,ETO); }

/* Info used and needed by the Master Object */
QClanName(){ return ClanName; }
SClanName(str){ ClanName = str; return 1; }
QClanRank(){ return ClanRank; }
SClanRank(arg){ ClanRank = arg; return 1; }
QClanTitle(){ return ClanTitle; }
SClanTitle(str){ ClanTitle = str; return 1; }
QClanBlock(){ return ClanBlock; }
SClanBlock(arg){ ClanBlock = arg; return 1; }

QClanRankN( int arg ){
  int clanrank;
  if(arg) clanrank = arg; else clanrank = ClanRank;
  switch(clanrank){
    case 1: return "Seaman";
    case 2: return "Petty Officer";
    case 3: return "Chief Petty Officer";
    case 4: return "Chief of the Boat";
    case 5: return "Executive Officer";
    case 6: return "Commanding Officer";
    default: return "No Rank";
  }
}

QClanTitleN( int arg ){
  int clantitle;
  if(arg) clantitle = arg; else clantitle = ClanTitle;
  switch(clantitle){
    case 1: return "Master-at-Arms";
    case 2: return "Boatswain's Mate";
    case 3: return "Gunner's Mate";
    case 4: return "Damage Controlman";
    case 5: return "Quartermaster";
    case 6: return "Sonar Technician";
    case 7: return "Intelligence Specialist";
    default: return "";
  }
}

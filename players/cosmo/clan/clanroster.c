#include "/players/cosmo/closed/ansi.h"
#define CLANOB "/players/cosmo/clan/clanob.c"
#define MASTER "/players/cosmo/clan/clanmaster.c"

string *Name;            /* Clan member name */
string *Banned;          /* Names of former members */
static string *Rank;     /* Clan member rank */
static string *Title;    /* Clan member title (only for rank == 2) */

id(str){ return str == "clan_roster"; }

reset(arg){
  if(arg) return;
  Name = allocate(12);
  Banned = ({ });
  Rank = ({ "Commanding Officer","Executive Officer",
            "Chief of the Boat","Chief Petty Officer",
            "Petty Officer","Petty Officer","Petty Officer",
            "Petty Officer","Petty Officer","Petty Officer",
            "Petty Officer","Seaman","Seaman" });
  Title = ({ "","","","","Master-at-Arms",
             "Boatswain's Mate","Gunner's Mate",
             "Damage Controlman","Quartermaster",
             "Sonar Technician","Intelligence Specialist","","" });
}

RestoreClan( string clanname ){
  if(!clanname) return 0;
  if(!restore_object("players/cosmo/clan/save/"+lower_case(clanname))){
    write("Creating new clan...\n");
    Name = ({"<vacant>","<vacant>","<vacant>","<vacant>",
             "<vacant>","<vacant>","<vacant>","<vacant>",
             "<vacant>","<vacant>","<vacant>","<vacant>","<vacant>"});
    SaveClan(clanname);
  } else write("Clan roster restored.\n");
  return 1;
}

SaveClan( string clanname ){
  save_object("players/cosmo/clan/save/"+lower_case(clanname));
  write("Clan roster saved.\n");
  return 1;
}

/* Return 1 for succes, 0 for failure, or -1 for banned member */
UpdateClan( string clanname, string member_name, int rank, int title){
  int i;  /* Previous position in the array */
  int x;  /* New position in the array */
  RestoreClan(clanname);
  if(sscanf(member_name,"rm#%s",member_name) == 1){
    Name[member_array(member_name, Name)] = "<vacant>";
    Banned += ({ member_name });
    SaveClan(clanname);
    return 1;
  }
  if(member_array(member_name,Banned) > -1) return -1;
  if(rank == 1){
    if(Name[11]=="<vacant>") x=11;
    else if(Name[12]=="<vacant>") x=12;
    else return 0;  /* Can't have more than 2 seaman */
  }
  else if(rank > 2 && rank < 7){
    if(Name[6-rank]=="<vacant>") x = 6 - rank;
    else return 0;  /* Slot already occupied */
  }
  else{
    if(Name[3+title]=="<vacant>") x = 3 + title;
    else return 0;  /* Slot already occupied */
  }
  i = member_array(member_name, Name);
  if(i > -1) Name[i] = "<vacant>";
  Name[x] = member_name;
  SaveClan(clanname);
  return 1;
}

ViewClan( string clanname, object *actives ){
  int x,y;
  string toggle;
  if(RestoreClan(clanname)){
    write("Members of the "+BOLD+clanname+NORM+" Clan:\n");
    write(pad(" NAME",16)+pad("RANK",22)+"POSITION\n");
    for(x=0;x<13;x++){
      for(y=0;y<sizeof(actives);y++){
        if(actives[y]->query_name() == Name[x]){
          toggle = "*";
          break;
        }
        else toggle = " ";
      }
      write(pad(toggle+" "+Name[x],16));
      write(pad(Rank[x],22));
      write(Title[x]);
      write("\n");
    }
    write("\n* Currently logged on.\n");
  }
  return 1;
}

/* Return 1 if member_name is in the clan */
CheckClan( string clanname, string member_name ){
  RestoreClan(clanname);
  if(member_array(member_name, Name) < 0) return 0;
  else return 1;
}

/* Return 1 if clanname is available */
CheckClans( string clanname ) {
  string *clans;
  int x;
  clans=get_dir("/players/cosmo/clan/save/");
  if(member_array(lower_case(clanname)+".o",clans) > -1) return 0;
  return 1;
}

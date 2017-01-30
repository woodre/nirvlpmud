
/*  The Party Object   Version 2.0
    Created by Beck (Russ Warren)   June 1998
*/

/*  The master object (daemon) where all the party info, 
    and commands are located.
*/
#define MASTER "/players/beck/Test/partymaster.c"

/* The Party's name */
string PartyName;

/* The party name used in the mapping (really the party leader's name) */
string RealPartyName;

/* How many shares this person gets */
int PartyShares;

/* How much experience this person has received */
int PartyExperience;

/* Determines if a person is leader (0) or follower (1) */
status PartyFollower;


id(str){ return str == "party_object" || str == "object" || str == "party object" || str == "party"; }

short(){
   return "A Party Object";
}

long(){
   if(present(this_object(),this_player())){
   write("A Party Object\n"+
   "Available commands to all party members:\n\n"+
   "party                        Shows data about the party.\n"+
   "party say <message>          Tells message to others in your party.\n"+
   "party who                    Shows all members of all parties.\n"+
   "party leave                  Allows you to leave the party.\n"+
   "\nAvailable commands for party leaders only:\n\n"+
   "party add <name>             Add a player or kid to your party.\n"+
   "party name <name>            Set your party name.\n"+
   "party share <name> <number>  Sets a party members number of shares.\n"+
   "party remove <name>          Remove a player from the party.\n"+
   "party leader <name>          Make someone else the party leader.\n"+
   "");
   }
   else{
      write("A Party Object\n"+
      "You can 'get' it to form a party.\n"+
      "");
   }
}

get(){ 
   if(present("party_object",this_player()) || !this_player()->is_player()){
      write("You are already in a party.\n");
      return 0;
   }
   else{
   write("Congrats on forming your new Party.\n"+
   "Please 'look at object' for more details.\n");
   return 1;
   }
}

drop(){ 
   if(query_verb() == "drop"){
      write("You must type 'party leave' to leave the party.\n");
      return 1;
   }
   MASTER->PartyLeave(RealPartyName,environment(this_object())); 
   return 1;
}

init(){
   if(this_player()){
      if(present(this_object(),this_player())){
         if(this_player()->query_level() > 19 && this_player()->query_level() < 700){
            write("Wizards cannot join Parties.\n");
            destruct(this_object());
            return;
         }
         PartyShares = this_player()->query_level();
         if(!PartyFollower){
            RealPartyName = this_player()->query_real_name();
            PartyName = "Party ["+this_player()->query_name()+"]";     
            MASTER->PartyAdd(RealPartyName, this_player()->query_real_name(),PartyName);
         }
         add_action("PartyCommand","party");
      }
   }
}

extra_short(){ return "[member of "+PartyName+"]"; }

/*  All commands are passed on to the Master object */
PartyCommand(str){ 
   string message;
   string name;
   string partyname;
   int number;
   if(!str){ return MASTER->PartyStatus(RealPartyName,PartyName); }
   if(sscanf(str,"add %s",name)){ return MASTER->PartyAdd(RealPartyName, name, PartyName);}
   if(sscanf(str,"say %s",message)){ return MASTER->PartySay(RealPartyName, message, PartyName, this_player()->query_name()); }
   if(sscanf(str,"name %s",partyname)){ return MASTER->PartyName(RealPartyName,partyname); }
   if(sscanf(str,"remove %s",name)){ return MASTER->PartyRemove(RealPartyName,name); }
   if(str == "leave"){ return MASTER->PartyLeave(RealPartyName,environment(this_object())); }
   if(str == "who"){ return MASTER->PartyWho(); }
   if(sscanf(str,"leader %s",name)){ return MASTER->PartyLeader(RealPartyName,name); }
   if(sscanf(str,"share %s %d",name,number)){ return MASTER->PartyShare(RealPartyName,name,number); }
   return 0;
}

/* This function is called by hit player */
/* This just passes the info to the Master object */
share_exp(amount){  
   object leader;
   leader = previous_object()->query_attack();
   MASTER->ShareExp(amount,RealPartyName,environment(this_object()), leader); 
}

/* Info used and needed by the Master Object */
QPartyShares(){ return PartyShares; }
SPartyShares(arg){ PartyShares = arg; return 1; }
QPartyName(){ return PartyName; }
SPartyName(str){ PartyName = str; return 1; }
QPartyFollower(){  return PartyFollower; }
SPartyFollower(arg){ PartyFollower = arg; return 1; }
SRealPartyName(str){ RealPartyName = str; return 1; }
APartyExperience(arg){ PartyExperience += arg; return 1; }
QPartyExperience(){ return PartyExperience; }

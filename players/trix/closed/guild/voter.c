#include "/players/boltar/things/esc.h"
string choice,names,candid;
string name,guild_name;
int guild_rank;
int votes,i,j;
reset(arg) {
	int i;
        if(arg) return;
	candid=allocate(10);
	votes=allocate(10);
	names=allocate(100);
	for(i=0;i<100;i++) names[i]="";
	for(i=0;i<10;i++) candid[i]="";
	for(i=0;i<10;i++) votes[i]=0;
        restore_object("players/trix/closed/guild/votes");
}

id( str ) {
        if(str=="machine"||str=="gc_voter") return 1;
        return 0;
}

long() {
write("This is a voting machine made to collect the votes for the Guild Commanders\n");
write("election. One gc spot is available, so the guilder that will collect the\n");
write("highest numbers of votes will be promoted GC rank. The candidates must \n");
write("belong to the guild and be at least level 7th. So check to see if the \n");
write("person you want to vote for matches these requirements. Of course every guilder\n");
write("that is at least 2nd level will be able to vote only once.\n");
write("If you vote a person who's not in the exit-poll list, your vote will sign\n");
write("the person as a candidate and give him/her the first vote.\n");
write("The elections will close on September Thursday 29, then Friday 30 the votes\n");
write("will be controlled and the charge assigned. Think about your choice, a Guild\n");
write("Commander is supposed to help you when you are in trouble, so you'd better\n");
write("choose A PERSON YOU'RE SURE WILL BE ON OFTEN in case of need.\n");
write("It is up to you all now, good luck and chose properly!!!!!!!!!!\n");
write("Type 'vote <name>' to give your preference.\n");
write("Type 'exit-poll' to look at the current situation of the GC elections.\n");
}

short()
  { return "A "+esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"
           +"GC"+esc+"[0m voting machine"; }

init()
{
  add_action( "vote","vote");
  add_action( "poll","exit-poll");
  add_action( "rearrange","rearrange");
}

vote(arg)
{  
   if(present("soul-undead",this_player())->guild_level()<2)
	{ write("You must be 2nd level in the guild to be able to vote.\n");
	  return 1;
	}
	if(!arg)
	 { write("Whom do u want to vote for?\n");
	  return 1;
	 }
   if(!restore_object("players/"+arg)) 
         { write("No such player on the mud.\n");
           return 1;
         }
   if(guild_name!="undead")
         { write(capitalize(name)+" is not an Undead.\n");
           return 1;
         }
   if(guild_rank<7||guild_rank>8) 
         { write("You can only vote for level 7 or 8 guild members.\n");
           return 1;
         }
        choice=name;
    for(i=0;names[i]!="";i++)
      if(this_player()->query_real_name()==names[i])
	{  write("You already voted!!!\n");
	   return 1;
        }
    for(j=0;candid[j]!=""&&candid[j]!=choice;j++)
      if(j==9)
{ write("Sorry, there can't be more than 10 candidates. To see the candidates'\n"+
                "names type 'exit-poll'.\n");
	  return 1;
        }
write("Are you sure you want vote for "+capitalize(choice)+" (y/n)? [n] ");
	input_to("realvote");
	return 1;
}

realvote(arg)
{   
    if(arg!="y") 
	{ write("Ok, you don't express your vote.\n");
	  return 1;
	}
    names[i]=this_player()->query_real_name(); 
    candid[j]=choice;
    votes[j]++;
    write("Ok, your vote goes to "+capitalize(choice)+" that scores "+votes[j]+" votes.\n");
    save_object("players/trix/closed/guild/votes");
    say(capitalize(this_player()->query_real_name())+" posts his GC elections vote.\n",this_player());
    return 1;
}
poll()
{  int i;
   write("\n*---------------------------*> Guild Commanders *<----------------------------*\n");
   write("*---------------------------*>     Elections    *<----------------------------*\n");
   write("*---------------------------*> Exit-Poll Results *<---------------------------*\n");
   for(i=0;i<10&&candid[i]!="";i++)
   {   int j;
       write(capitalize(candid[i]));
       if(strlen(candid[i])>7)
                write("\t"); else write("\t\t");
       write("\b\b\b\b\b|"+votes[i]+"\t\b\b|");
       for(j=1;j<=votes[i];j++) write("x");
       write("\n");
   }
   if(i==0) write("No candidates yet.\n");
   write("*-----------------------------------------------------------------------------*\n");
   return 1;
}

get() {
        return 0;
}
drop() {
        return 0;
}
rearrange(arg)
{ string from,to;
  int find1,find2;
  if(this_player()->query_real_name()!="trix") { write("You can't rearrange!\n"); return 1; }
  if(!arg) { write("Syntax: rearrange <from>:<to>\n"); return 1; }
  if(sscanf(arg,"%s:%s",from,to)!=2)
    { write("Syntax: rearrange <from>:<to>\n"); return 1; } 
   find1=-1;
   find2=-1;
   for(i=0;i<10&&candid[i]!="";i++)
   {   if(candid[i]==from) find1=i; 
       if(candid[i]==to) find2=i;
   }
   if(find1==-1||find2==-1) { write("One of the two is not in the list.\n"); return 1; } 
   votes[find2]++;
   votes[find1]--;
   if(!votes[find1]) 
     while(candid[find1]!=""&&find1<9) { candid[find1]=candid[find1+1];
				         votes[find1]=votes[++find1]; }
     if(find1==9) { candid[find1]=""; votes[find1]=0; }
   save_object("players/trix/closed/guild/votes");
   write("Ok, changed.\n");
   return 1;
}        

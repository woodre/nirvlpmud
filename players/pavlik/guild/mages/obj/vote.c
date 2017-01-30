#include "/players/pavlik/closed/colors.h"
#define SAVE "players/pavlik/guild/mages/players/vote_stats"
#define MAX_NOMINEE 5

string nominees;
string who_voted;
int votes;

reset(arg){
 if(arg) return;
 nominees = allocate(MAX_NOMINEE);
 votes = allocate(MAX_NOMINEE);
 who_voted = "noone#";
 restore_object(SAVE);
}

short(){ return "A Voting Booth"; }

long() {
  write(
  "A tiny voting booth stands here.  A small black curtain\n"+
  "provides secrecy for the voter. You peek inside the booth\n"+
  "and see a neatly printed ballot and a freshly sharpened\n"+
  "pencil.  There is also a set of instructions avaliable for\n"+
  "you to read.\n");
  return;
}

id(str){ return str == "booth"; }
get(){ return 0; }
drop(){ return 1; }

init() {
  add_action("read","read");
  add_action("vote","vote");
  add_action("nominate","nominate");
  add_action("remove_nominee","removenom");
}

read(str) {
  if(str == "instructions" || str == "booth") {
    write(
    "The rules are simple...Guild Council Members are selected\n"+
    "by majority.  Any Guild Member above rank 21 is allowed to\n"+
    "vote 1 time only.  You can only vote for a person that has\n"+
    "been nominated.  Only the current Guild Council may\n"+
    "nominate a canidate.\n"+
    "commands are:\n"+
    "    vote <name>      - enter your vote.\n"+
    "    vote status      - see the current statistics.\n"+
    "\n");
    if(this_player()->query_guild_rank() > 71) {
      write("    nominate <name>  - make new canidate.\n");
      write("    removenom <name> - remove a canidate.\n");
    }
  return 1;
  }
}

nominate(str) {
  int num;

  if(this_player()->query_guild_rank() < 72) {
    write("You cannot do that.\n");
    return 1;
  }
  if(!str) {
    write("Nominate who?\n");
    return 1;
  }

  num = 0;
  while(num < 10) {
    if(num > MAX_NOMINEE) {
      write("Voting Ballot Full.\n");
      write("No other persons may be nominated.\n");
      num = 100;
      return 1;
    }
    if(nominees[num] == 0) {
      nominees[num] = capitalize(str);
      num = 100;
    }
    else {
      num++;
    }
  }

  write("You nominate "+capitalize(str)+".\n");
  say(capitalize(this_player()->query_name())+
   " nominate "+capitalize(str)+".\n");
  save_object(SAVE);

  return 1;
}

remove_nominee(str) {
  int x, found;

  if(this_player()->query_guild_rank() < 72) {
    write("You can't do that.\n");
    return 1;
  }

  if(!str) {
    write("Remove who?\n");
    return 1;
  }
  
  found = -1;
  for(x=0; x<MAX_NOMINEE; x++) {
    if(nominees[x] == capitalize(str))
      found = x;
  }

  if(found == -1) {
    write(capitalize(str)+" was never nominated.\n");
    return 1;
  }

  for(x=found; x<(MAX_NOMINEE-1); x++) {
    nominees[x] = nominees[x+1];
    votes[x] = votes[x+1];
  }
  nominees[MAX_NOMINEE-1] = 0;
  votes[MAX_NOMINEE-1] = 0;

  write("You have removed "+capitalize(str)+".\n");
  say(capitalize(this_player()->query_name())+
   " removes a canidate.\n");
  save_object(SAVE);

  return 1;
}


vote(str) {
  int found, x;
  string who;

  if(!str) {
    write("Vote what?\n");
    return 1;
  }

  if(str == "status") {
    write("Current Vote Totals ...................... \n");
    write("Name:\t\t\tVotes:\n");
    for(x=0; x<MAX_NOMINEE; x++) {
      if(nominees[x] != 0)
        write(nominees[x]);
        if(strlen(nominees[x]) > 7) write("\t\t");
        else write("\t\t\t");
        write("  "+votes[x]+"\n");
    }
    write("\n");

    if(this_player()->query_guild_rank() > 20) {
      if(!valid_voter()) write("You have already voted.\n");
      else write("You have not voted yet.\n");
    }

    return 1;
  }

  if(this_player()->query_guild_rank() < 21) {
    write("You are not permitted to vote yet.\n");
    return 1;
  }

  if(!valid_voter() && this_player()->query_level() < 50) {
    write("You cannot vote again.\n");
    return 1;
  }

  who = capitalize(str);

  found = -1;
  for(x=0; x<MAX_NOMINEE; x++) {
    if(who == nominees[x]) found = x;
  } 

  if(found == -1) {
    write(who+"'s name is not on the ballot.\n");
    return 1;
  }

  write("You step into the voting booth and grab a ballot.\n");
  write("You check "+who+"'s name and submit the paper slip.\n");
  say(capitalize(this_player()->query_name())+
   " steps into the booth and votes.\n");

  votes[found] = votes[found] + 1;
  who_voted = who_voted + this_player()->query_real_name() + "#";
  save_object(SAVE);

  return 1;
}

valid_voter() {
  string who, rest;

  rest = who_voted;
  while(sscanf(rest, "%s#%s", who, rest) == 2) {
    if(who == this_player()->query_real_name()) return 0;
  }
  if(rest == this_player()->query_real_name()) return 0;

  return 1;
}



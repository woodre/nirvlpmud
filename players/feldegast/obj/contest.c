/*
File: contest.c
Author: Feldegast @ nirvana.mudservices.com
Date: 2/7/01
Description:
  An autoloading object that sits on the green, and arbitrates a
player description contest.
*/
#define FILE "players/feldegast/obj/contest"
#define LOG "/players/feldegast/log/contest.log"
#define AGE 43200
  /* Fri Feb 23 00:00:00 2001 */
#define END_DATE 982904400
#include "defs.h"

/* Contestants */
string *registered; 

/* An array of an array of names of people who've voted for each contestant */
mixed *votes;       

/* An array of people who've voted */
string *voted;

int id(string str) {
  return str=="booth";
}

string short() {
  return "Description Contest Booth";
}

string query_winner() {
  int i;
  int max,max_index;
  for(i=0; i < sizeof(votes); i++) {
    if(sizeof(votes[i]) > max) {
      max = sizeof(votes[i]);
      max_index = i;
    }
  }
  return registered[max_index];
}

void long() {
  if(time() < END_DATE)
  write(
"This is a voting booth for the description contest.\n"+
"Voting will end "+ctime(END_DATE)+"\n"+
"Commands:\n"+
"  register          - Register yourself as a contestant\n"+
"  view              - View the list of contestants\n"+
"  view <contestant> - View a contestant's description\n"+
"  vote <contestant> - Vote for a contestant\n"
  );
  else
    write("This is a voting booth for the description contest.\n"+
          "The contest is over.  The winner is "+query_winner()+".  Congratulations!\n");
}


void reset(int arg) {
  if(arg) return;
  registered=({ });
  votes=({ });
  voted=({ });
  restore_object(FILE);  
}

void init() {
  add_action("cmd_register", "register");
  add_action("cmd_view", "view");
  add_action("cmd_vote", "vote");
}

int cmd_register(string str) {
  string name;
  name=(string)this_player()->query_real_name();
  if(time() > END_DATE) {
    write("The contest ended "+ctime(END_DATE)+".\n");
    return 1;
  }
  if((int)this_player()->query_level() > 20) {
    write("Wizards are not allowed to enter.\n");
    return 1;
  }
  if(member_array(name,registered)!=-1) {
    write("You have already registered.\n");
    return 1;
  }
  registered+=({ name });
  votes+=({ ({ }) });
  save_object(FILE);
  write("You register for the description contest!\n");
  say(TPN+" registers for the description contest.\n");
  return 1;
}

int cmd_view(string str) {
  object blank;
  string line;
  int xyclflex;
  if(time() > END_DATE) {
    write("The contest ended "+ctime(END_DATE)+".\n");
    return 1;
  }
  if(!str) {
    write("The following contestants have registerd, and received the\n"+
          "following number of votes:\n");
    line="";
    for(xyclflex=0; xyclflex < sizeof(registered); xyclflex++) {
      line+=capitalize(registered[xyclflex]);
      line+="("+sizeof(votes[xyclflex]) + ")";
      if(xyclflex!=(sizeof(registered)-1))
        line+=", ";
      else
        line+=".";
    }
    line+="\n";
    write(format(line, 70));
    return 1;
  }
  str=lower_case(str);
  if(member_array(str,registered)==-1) {
     write("That player hasn't registered for the contest.\n");
     return 1;
  }
  blank=clone_object("/players/feldegast/arena/equip/blank.c");
  blank->load_info(str);
  return 1;
}
 
int cmd_vote(string str) {
  int index;
  string *vote_list;
  if(time() > END_DATE) {
    write("The contest ended "+ctime(END_DATE)+".\n");
    return 1;
  }
  if(!living(this_player()) || !this_player()->is_player()) {
    write("You are not a player.\n");
    return 1;
  }
  if(!str) {
    notify_fail("Usage: vote <contestant>\n");
    return 0;
  }
  if((int)this_player()->query_age() < AGE) {
    write("You must be at least one day old to vote.\n");
    return 1;
  }
  if(member_array((string)this_player()->query_real_name(),voted)!=-1) {
    write("You have already voted.\n");
    return 1;
  }
  str=lower_case(str);
  index=member_array(str,registered);
  if(index==-1) {
    write("That player is not registered for the contest.\n");
    return 1;
  }
  vote_list=votes[index];
  vote_list+=({ (string)this_player()->query_real_name() });
  votes[index]=vote_list;
  voted+=({ (string)this_player()->query_real_name() });
  save_object(FILE);
  write("You have voted for "+capitalize(str)+".\n");
  write_file(LOG,ctime(time())+" "+TPN+" voted for "+capitalize(str)+".\n");
  return 1;
}

is_castle() { return 1; }

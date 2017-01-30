#define MAXTOPICS 5
#define MAXSIZE 6
#define MAXSOLUTIONS 4
#define PATH "players/boltar/templar/items/votec"

string *topics;
int topic_num;
static int sol_number;
static string temp;

short() { return "Templar Knights Council Voting Board"; }

init() {
  add_action("add_option","add");
  add_action("vote","vote");
}

reset(arg) {
  int i;
  
  if (arg) return;
  topics = allocate(MAXSIZE);
  for(i=0; i<sizeof(topics); i++) {
    topics[i] = allocate(MAXSOLUTIONS+1);
  }
  restore_object(PATH);
}

add_option(str) {
  if(this_player()->query_real_name() != "dragnar" &&
     this_player()->query_real_name() != "maledicta") {
    write("You may not add voting options.\n");
    return 1;
  }
  topics[topic_num][0] = str;
  topic_num++;
  write(str + " added as voting option number "+topic_num+"\n");
  save_object(PATH);
  write("Enter the number of solutions for this topic: ");
  input_to("GetNumber");
  return 1;
  }

GetSolutions(str) {
  int i,j;
  string sol1, sol2;

  if(sol_number == 2) {
    if(sscanf(str, "%s %s", sol1, sol2) != 2) {
      write("You didn't enter the correct number.\n");
      return;
    }
    topics[topic_num-1][1] = sol1;
    topics[topic_num-1][2] = sol2;
  }
  write("OK, done.\n");
  return 1;
}

GetNumber(str) {
  int num;
  if( (!sscanf(str, "%d", num)) || (num < 2 || num > 4)) {
    write("You must enter an integer between 2 and 4.\n");
    write("Enter the number of solutions for this topic: ");
    input_to("GetNumber");
    return;
  }
  sol_number = num;
  write("Now enter the solutions:\n");
  input_to("GetSolutions");
}


long() {
  int i,j;
  
  if(!topics) return 0;
  if(!topics[0][0]) {
    write("No voting issues at this time.\n");
	return 1;
  }
  write(" #\tTopic\tVotes\n");
  for(i=0; i<sizeof(topics) && topics[i][0]; i++) {
    write(i+1+". "+topics[i][0]+"\n");
	for(j=1; j<sizeof(topics[i]) && topics[i][j]; j++) {
	  write("\t"+topics[i][j]+"\n");
	}
  }
  return 1;
}

id(str) {
return str == "board" || str == "voting board";
}

vote(str) {
  int i,voternum,arg;
  string bb,bo,a,b;
  bb = this_player()->query_real_name();
  if(this_player()->query_guild_name() != "Knights Templar") {
    write("You are not a Knight!!\n");
    return 1;
  }

save_object(PATH);
write("Your vote has been recorded.\n");
return 1;
}

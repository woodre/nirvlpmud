#define OPTNUM 11
#define VOTEPER 3
int opt,totalvoted;
int votetotals;
string voterecord,voter;
int votecount;
string options;
short() { return "Templar Knights Voting Board";
}
init() {
add_action("add_option","add");
add_action("vote","vote");
}
reset(arg) {
if (arg) return;
options = allocate(OPTNUM+1);
votetotals = allocate(OPTNUM+1);
voterecord = allocate(100);
voter = allocate(100);
votecount = allocate(100);
restore_object("players/boltar/templar/items/voteb");
}
add_option(str) {
if(this_player()->query_real_name() != "boltar") {
write("You may not add voting options.\n");
return 1;
}
options[opt] = str;
write(str + " added as voting option number "+opt+"\n");
opt += 1;
save_object("players/boltar/templar/items/voteb");
return 1;
}
long() {
int i;
write(" #\tVote Choice\tVotes\n");
while (i < opt) {
write(" "+i+"\t"+options[i]+"\t"+votetotals[i]+"\n");
i+=1;
}
write("Total votes cast: "+totalvoted+"\n");
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
if(!str) return 0;
if(sscanf(str,"%d",arg) != 1) {
write("please vote by the numbers.\n");
return 1;
}
if(arg > opt - 1) {
write("There is no such thing to vote for.\n");
return 1;
}
i = 1;
while (voter[i]) {
if(voter[i]==bb) voternum = i;
i+=1;
}
if(!voternum) { voternum =i; voter[voternum] = bb; }
if(votecount[voternum] == VOTEPER) {
write("You have no votes remaining.\n");
return 1;
}
bo = options[arg];
if(voterecord[voternum])
if(sscanf(voterecord[voternum],"%s"+bo+"%s",a,b)==2) {
write("You have already cast a vote for that option.\n");
return 1;
}
votecount[voternum] += 1;
voterecord[voternum] = voterecord[voternum] +"##"+ bo;
totalvoted += 1;
votetotals[arg] += 1;
save_object("players/boltar/templar/items/voteb");
write("Your vote has been recorded.\n");
return 1;
}

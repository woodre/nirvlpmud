#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include "/players/pavlik/closed/colors.h"
#define WAR "players/pavlik/guild/mages/rooms/war_room.c"
#define FILENAME "players/pavlik/guild/mages/rooms/party_stats2"
#define MAX 5
inherit "room/room";

string party_name, leader, members;
int total_exp, kills;

static object memb, board;
static object tempa;
static int z;

reset(arg) {
  if(arg)  return;
set_light(1);
short_desc="Party Room";
long_desc=
"The Mage's Party Room is where adventurous Mages can meet to team\n"+
"up.  The large chamber is furnitured with plush chairs and a blazing\n"+
"heart, a relaxing atmosphere.  There is a message board on the south\n"+
"wall and just next to that is the Party Leader Board, where the\n"+
"achievements of the most sucessful parties are posted.  A heavy iron\n"+
"door in the south war leads to the War Room and a smaller wooden door\n"+
"to the north leads to the bar.  There is a small sign just below\n"+
"the Leader Board.\n";

 party_name = allocate(4);
 leader = allocate(4);
 members = allocate(4);
 total_exp = allocate(4);
 kills = allocate(4);
 for(z=0; z<4; z++){
  party_name[z] = "none";
  leader[z] = "nobody";
  members[z] = "none";
  total_exp[z] = 1;
  kills[z] = 1;
 }
  tempa = allocate(6);

 restore_object(FILENAME);

dest_dir=({
  "/players/pavlik/guild/mages/rooms/guild_room", "east",
  "/players/pavlik/guild/mages/rooms/war_room", "south",
  "/players/pavlik/guild/mages/rooms/mage_bar", "north",
});

if(!present("board", this_object())){
  board = clone_object("players/pavlik/guild/mages/obj/party_board");
  move_object(board, this_object());
  }

}

query_mguild(){ return "Party Room"; }

init(){
 ::init();
  mage_check();
  add_action("guild_move","gm");
  add_action("south","south");
  add_action("read_sign","read");
  add_action("party_scores","pscores");
  add_action("party_register","register");
  add_action("get_party_object","pobject");
}

south(){
  if(this_player()->query_ghost()){
    write("You cannot go in there!\n");
    return 1;
    }

  if(WAR->query_combat() == 1){
    write(
    "The War Room is currently occupied.  You will have\n"+
    "to wait until the contest is concluded.\n");
   return 1;
  } 

  move_object(this_player(), "players/pavlik/guild/mages/rooms/war_room");
  command("look", this_player());
  return 1;
}

read_sign(str){
  if(str == "sign"){
    write(
    "-- Mages Party Room: -- \n"+
    "Message Board: The message board here is for posting notes on\n"+
    "               adventuring (tips, monsters, etc...).  Anyone may\n"+
    "               post messages here. Note: NO Quest info may be posted!!\n"+
    "Leader Board : The Leader Board contains scores for the top ranking\n"+
    "               parties.  To view standings, use 'pscores'.  To enter\n"+
    "               Your party into the standings, use 'register' (note:\n"+
    "               you Must have a Mage Party Object to register)  All\n"+
    "               standings will be reset periodically.\n"+
    "Party Objects: Mage Party Objects can be aquired here, use 'pobject'\n"+
    "               to attain one.\n"+
    "\n");
    return 1;
    }
}

get_party_object(){
   object obj;

  if(present("party object", this_player())){
    write("You already have a party object.\n");
    return 1;
    }

  write("Disabled, heh\n");
  return 1;

  write("You take a Party Object from a small chest by the hearth.\n");
  say(capitalize(this_player()->query_name())+" takes a Party Object.\n");

  obj = clone_object("players/pavlik/guild/mages/obj/party_object");
  move_object(obj, this_player());
  return 1;
}

party_register(){
 object obj;
 string member_name;
 int tot_exp, nrof;
 int i, place;

  obj = present("mage party object", this_player());

  if(!obj){
    write("You must have a Mage party object to register.\n");
    return 1;
    }

 tot_exp = obj->query_total_exp();

 place = 5;
 for(i=3; i>=0; i--){
  if(tot_exp >= total_exp[i]) place = i;
 }

 if(place > 3){
  write("Your party has earned a total of "+tot_exp+" XP.\n"+
  "Sorry, but this was not enough to get you onto the leader board.\n");
  return 1;
 }

 if(place == 0){
  write("Your party has earned a total of "+tot_exp+" XP.\n"+
  "This is a new record!!!  You take the #1 spot on the leader board!\n");
 } else {
  write("Your party has earned a total of "+tot_exp+" XP.\n"+
  "You have placed #"+(place+1)+" on the leader board!\n");
 }

 for(i=2; i>=place; i--){
  party_name[i+1] = party_name[i];
  leader[i+1] = leader[i];
  members[i+1] = members[i];
  total_exp[i+1] = total_exp[i];
  kills[i+1] = kills[i];
 }

 party_name[place] = obj->query_party_name();
 leader[place] = obj->leadername();
 /* members */
 nrof = obj->query_nrofmembers();
 if(nrof < 1) members[place] = "none";
 else {
  tempa = obj->query_members();
  members[place] = tempa[1]->name();
  for(i=2; i<=nrof; i++){
   members[place] = members[place] +"#"+ tempa[i]->name();
  }
 }
 total_exp[place] = obj->query_total_exp();
 kills[place] = obj->query_kills();

 write("Updating stats ...\n");
 save_object(FILENAME);
 return 1;
}

party_scores(){
 int i;
 string mem, rest;
 write("\n"+BCYN+BLK+
 "      *   *  * * * * Mages Party Leader Board * * * *  *   *   \n"+NORM);
 for(i=0; i<4; i++){
 if(i==0) write(HIY+"> [1st]: "+NORM);
 else if(i==1) write(HIM+"> [2nd]: "+NORM);
 else if(i==2) write(HIG+"> [3rd]: "+NORM);
 else if(i==3) write(HIR+"> [4th]: "+NORM);
 write(party_name[i]+"\n");
 write("\tLeader: "+HIM+leader[i]+NORM+"\t\tExperience: "+HIC+total_exp[i]+NORM+"\n");
 write("\tMembers:\t\t\tKills: "+HIR+kills[i]+NORM+"\n");
 rest = members[i];
 while(sscanf(rest, "%s#%s", mem, rest)==2){
 write("\t   "+HIC+mem+"\n");
 }
 write("\t   "+HIC+rest+"\n");
 write(BLU+"   -----------------------------------------------------------\n"+NORM);
 }
 return 1;
}


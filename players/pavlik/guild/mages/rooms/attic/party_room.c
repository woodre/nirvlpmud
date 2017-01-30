#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include "/players/pavlik/closed/colors.h"
#define WAR "players/pavlik/guild/mages/rooms/war_room.c"
#define FILENAME "players/pavlik/guild/mages/rooms/party_stats2"
#define MAX 4
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
"up, or a place to kick back for some well deserved rest.  The large\n"+
"chamber provides a relaxing atmosphere: huge plush chairs, a warm\n"+
"blazing hearth and thick fur skin rugs.  Trophies from many of the\n"+
"conquered monsters of Nirvana adorn the walls.  There is a special\n"+
"board here where Mage's can recount and share their great expeditions\n"+
"throughout the realms.  The cheerful sounds of a Tavern come from the\n"+
"north, and the not-so-friendly sounds of the War Room echo from the\n"+
"south.  There is a small sign on the wall here.\n";

 party_name = allocate(MAX);
 leader = allocate(MAX);
 members = allocate(MAX);
 total_exp = allocate(MAX);
 kills = allocate(MAX);

 /* reset the arrays */
 for(z=0; z<MAX; z++){
   party_name[z] = "none";
   leader[z] = "nobody";
   members[z] = "none";
   total_exp[z] = 1;
   kills[z] = 1;
 }
 tempa = allocate(6);

 /* get the party stats from save file */
 restore_object(FILENAME);

dest_dir=({
  "/players/pavlik/guild/mages/rooms/guild_room", "east",
  "/players/pavlik/guild/mages/rooms/war_room", "south",
  "/players/pavlik/guild/mages/rooms/mage_bar", "north",
});

items=({
"sign",
"A small sign proclaiming certain things you can do here:\n"+
HIM+"pobject"+NORM+"  : Get a Mages Party Object.\n"+
HIM+"register"+NORM+"  : Register your Party Stats for the leader board.\n"+
HIM+"pscores"+NORM+"  : Check out the Party Leaders.\n"+
HIM+"sitdown"+NORM+"  : Pull up one of the comfy chairs and relax.\n"+
"\n",
"chairs",
"Several inviting chairs furnish this chamber.  They look quite comfortable",
"hearth",
"The blazing fire warms your tired bones",
"rugs",
"Thick animal fur rugs cover the floor",
});

 if(!present("board", this_object())){
  board = clone_object("players/pavlik/guild/mages/obj/bboard");
  move_object(board, this_object());
  }

}

query_mguild(){ return "Party Room"; }

init(){
 ::init();
  add_action("cmd_read","read");
 mage_check();
 add_action("guild_move","gm");
 add_action("south","south");
 add_action("get_party_object","pobject");
 add_action("party_register","register");
 add_action("party_scores","pscores");
 add_action("sitdown","sitdown");
}

sitdown(){
 write("You pull one of the large comfortable chair closer to the fire\n"+
 "and sit down to relax.\n");
 say(capitalize(this_player()->query_name())+
 " pulls a chair close to the fire and sits down.\n");
 return 1;
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

get_party_object(){
   object obj;

  if(present("party object", this_player())){
    write("You already have a party object.\n");
    return 1;
    }

  write("Disabled.\n"); return 1;
 write(
 "You pull a small hidden lever and a tiny ball rolls out into the palm\n"+
 "of your hand.  You now have a Mage's Party Object!\n");
 say(capitalize(this_player()->query_name())+
 " pulls a tiny lever hidden in the wall.\n"+
 "A tiny round ball rolls into his hands!\n");
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

 /* adjust the other places on the leader board */
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


int cmd_read(string str)
{
  if(str != "sign") return 0;
  long(str);
  return 1;
}

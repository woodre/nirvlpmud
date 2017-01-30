#include "/room/clean.c"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

string dest_dir;
string short_desc;
string long_desc;
string items;
string property;
string listens;
string smells;

/* No castles are allowed to be dropped here */
int no_castle_flag;
int no_exits;

init() {
    int i;
::init();
    add_action("listen","listen");
    add_action("smell","smell");
    add_action("search","search");
}

listen(str){
int i;
    if(!listens){
      notify_fail("You don't hear anything.\n");
   return 0;
}
  if(!str){
    str = "default"; }
    while(i < sizeof(listens)){
    if(listens[i] == str){
    write(listens[i+1] + ".\n");
    return 1;
}
    i+= 2;
}
write("You can't hear that.\n");
return 1;
}

smell(str){
int i;
    if(!smells){
      notify_fail("You dont smell anything.\n");
    return 0;
}
    if(!str){
    str = "default"; }
    while(i < sizeof(smells)){
    if(smells[i] == str){
    write(smells[i+1]+".\n");
    return 1;
}
    i+= 2;
}
write("You can't smell that.\n");
return 1;
}

search(){
  notify_fail("You find nothing of intrest.\n");
  return 0;
}




 

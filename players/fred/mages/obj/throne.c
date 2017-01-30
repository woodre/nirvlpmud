#include "/players/fred/mages/defs.h"

inherit "/obj/treasure";
string sit_name;
int sit;
object sitter;

reset(arg){
  if(!arg)
  sit = 0;
  }

id(str) {return str == "throne" || str == "jade throne"; }

short(){
      if(sit) return "A Great Jade Throne, occupied by "+capitalize(sit_name);
      if(!sit) return "A Great Jade Throne"; }      

long(){
 write("This is a beautiful throne, hacked out of a single hunk of jade.\n");
 write("It is literally worth a dukedom.  There are some runes inscribed in it.\n");} 

get(){ return; }

query_value() { return 1000000; }

init(){
   add_action("read","read");
   add_action("summon_stalker","summon");
   add_action("stop_stalk","recall");
   add_action("sit","sit");
   add_action("stand","stand");
   add_action("south","s");
   add_action("south","south");}

sit(){
  if(sitter){
    write(capitalize(sitter->query_name())+" is already sitting there.\n");
    return 1; }
  sitter = TP;
  sit = 1;
  sit_name = TPN;
   write("You make yourself comfortable on the throne.\n");
   say(capitalize(TPN)+" takes a seat upon the jade throne.\n");
   return 1;}

stand(){
  if(TP != sitter){
    write("You are not sitting.\n"); return 1;}
  sitter = 0;
  sit = 0;
   write("You stand up from the throne.\n");
   say(capitalize(TPN)+" stands up.\n");
   return 1;}

south(){
  if(TP == sitter){
    write("Perhaps you should stand up before trying to leave the room.\n");
    return 1;}
    return 0;}

stop_stalk(){
  object ds;      
  ds = find_living("dark_stalker_bug");
  if(!ds){write("The Dark Stalker is nowhere to be found.\n");
  return 1;}
  ds->set_follow(0);
    write("You call back the dark stalker.\n");
    MO(find_living("dark_stalker_bug"), ENV(TP));
    return 1;}

summon_stalker(str){
  object ds, bug, me;
  if(str != "dark stalker" && str != "stalker"){ write("You want to summon what?\n"); return 1;}
  ds = find_living("dark_stalker_bug");
  if(ds){
    write("There is already a Dark Stalker out there.\n");
    return 1;}
  write("You summon the Dark Stalker.\n");
  me = TP;
  bug = CO("/players/fred/mages/mon/dark_stalker.c");
  MO(bug, ENV(TP));
  bug->set_owner(me);
  return 1;}
	
read(str){
if(str != "runes"){return 0;}
  write("From this Throne you may <summon> a <dark stalker>.\n");
  write("From this Throne you may <recall> your <dark stalker>.\n");
  return 1;
}

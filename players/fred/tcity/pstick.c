#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";
#define ENN environment()->query_name()
#define POS environment()->query_possesive()
#define PRO environment()->query_pronoun()
int Q;

reset (arg) {
 set_id("stick");
 set_alias("pogo stick");
 set_short(GRN+"Pogo"+NORM+BOLD+" Stick"+NORM);
 set_long(
 "  An average looking pogo stick. It is bright green in color with\n"+
 "a few small yellow stickers randomly placed on it. There is some\n"+ 
 "sort of writing scratched into it.\n");
 set_weight(1);
 set_value(200);
 Q = 0; 
}

init(){
 ::init();
   add_action("bouncy_bouncy_boing", "hop");
   add_action("what_what_what", "read");
   add_action("alien_antfarm", "look");
   add_action("alien_antfarm", "l"); 
   add_action("wed_niatnuom", "pogo");
   add_action("LOG", "n");
   add_action("LOG", "s");
   add_action("LOG", "e");
   add_action("LOG", "w");
   add_action("LOG", "ne");
   add_action("LOG", "se");
   add_action("LOG", "nw");
   add_action("LOG", "sw");
   add_action("LOG", "up");
   add_action("LOG", "down");
   add_action("LOG", "u");
   add_action("LOG", "d");
   add_action("LOG", "southwest");
   add_action("LOG", "southeast");
   add_action("LOG", "northeast");
   add_action("LOG", "northwest");
   add_action("LOG", "in");
   add_action("LOG", "out");
   add_action("LOG", "climb");
   add_action("LOG", "descend");
}

alien_antfarm(str){
  if(str == "at writing"){
    write("Perhaps you could read them.\n");
    return 1; }
  }

what_what_what(str){
  if(str == "writing"){
    write("To start just '"+BOLD+"pogo start"+NORM+"'.\n"+
          "To stop simply '"+BOLD+"pogo stop"+NORM+"'.\n");
    return 1; }
  }  

wed_niatnuom(str){
  if(str == "start"){
    if(Q > 0){
      write("You are already 'hopping' on it.\n");
    return 1; } 
    write("You hop on the pogo stick and begin hopping around the room.\n");
    say(ENN+" climbs on the pogo stick and begins to merrily hop around the room.\n");
    Q = 1;
  call_out("JUMP", 30);
  return 1; }
  if(str == "stop"){
    if(Q < 1){
      write("You aren't 'hopping' on the pogo stick.\n");
    return 1; }
    write("You jump off the pogo stick and land steadily on your feet.\n");
    say(ENN+" jumps off the pogo stick and lands on "+POS+" feet.\n");
    Q = 0; 
   remove_call_out("JUMP"); 
   return 1; }
  }

bouncy_bouncy_boing(str){
  if(str == "east" || str == "e"){
   write("You hop off to the east.\n");
   command("east", environment());
   return 1; }
  if(str == "west" || str == "w"){
   write("You hop off to the west.\n");
   command("west", environment());
   return 1; }
  if(str == "north" || str == "n"){
   write("You hop off to the north.\n");
   command("north", environment());
   return 1; }
  if(str == "south" || str == "s"){
   write("You hop off to the south.\n");
   command("south", environment());
   return 1; }
  if(str == "southeast" || str == "se"){
   write("You hop off to the southeast.\n");
   command("se", environment());
   return 1; }
  if(str == "southwest" || str == "sw"){
   write("You hop off to the southwest.\n");
   command("sw", environment());
   return 1; }
  if(str == "northwest" || str == "nw"){
   write("You hop off to the northwest.\n");
   command("nw", environment());
   return 1; }
  if(str == "northeast" || str == "ne"){
   write("You hop off to the northeast.\n");
   command("ne", environment());
   return 1; }
  if(str == "up" || str == "u"){
   write("You hop in an upward direction.\n");
   command("u", environment());
   return 1; }
  if(str == "down" || str == "d"){
   write("You hop in a downward direction.\n");
   command("d", environment());
   return 1; }
  else{
   write("That doesn't appear to be a direction you can hop.\n");
   return 1;
  }
}

JUMP(){
  tell_room(environment(environment()),
  ENN+" hops happily around the room.\n");
  call_out("JUMP", 30);
  return 1; }

LOG(){
 if(Q > 0){
  write("You can't move while on the pogo stick.\n"+
        "You can however 'hop' a direction.\n");
  return 1; }
 }



  


    


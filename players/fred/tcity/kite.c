#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";
#define MAX 5
#define ENN environment()->query_name()
#define POS environment()->query_possesive()
#define PRO environment()->query_pronoun()
#define EN environment()
int flu, y, ack, stu;
string blah;

reset (arg) {

 set_id("kite");
 set_long(
 "  A small kite with a long tail on it. There should be\n"+
 "just enough breeze here to "+BOLD+GRN+"fly"+NORM+" it. Once you are done\n"+ 
 "playing with it you can just "+BOLD+GRN+"reel"+NORM+" it in.\n");
 set_weight(1);
set_value(20);
 flu = 0;
 ack = 0;
 stu = 0;
 }

init(){
 ::init();
   add_action("set_that_ninny_free", "fly");
   add_action("get_your_butt_back_here", "reel");
 }

set_that_ninny_free(str){
  if(!str){ write("What did you want to fly?\n"); return 1; }
  if(str == "kite"){
   write("You take off running with the kite trailing behind you.\n"+
         "Suddenly the wind catches it and it soars up into the air!\n");
   say(ENN+" takes off running with "+POS+" kite behind "+PRO+".\n");
   say(ENN+"'s kite catches some wind and soars up into the sky!\n");
 flu = 1;
 call_out("float_em", 20);
 return 1; }
 }

get_your_butt_back_here(str){
  if(!str){ write("Reel what in?\n"); return 1; }
  if(str == "in kite" || str == "kite"){
   write("You start to reel in your kite...\n");
   say(ENN+" starts to reel in "+POS+" kite.\n");
 remove_call_out("float_em");
 call_out("bring_it", 7);
 return 1; }
}

float_em(){
  if(stu < MAX){
  tell_object(EN, "The wind catches your kite and it pulls it out even farther...\n");
  stu ++;
  call_out("float_em", 20);
  return 1;
  }
}


bring_it(){
 tell_object(EN, "You tug on the kite string, slowly reeling it in...\n");
 stu --;
 if(!stu){
  tell_object(EN, "You finally get your kite reeled in!\n");
  remove_call_out("bring_it");
  flu = 0;
  return 1; }
 call_out("bring_it", 7);
return 1; }
 
short(){
 if(ack < 1){
 y = random(6);
 switch(y){
 case 0: blah = BLU+"blue"+NORM; break;
 case 1: blah = GRN+"green"+NORM; break;
 case 2: blah = RED+"red"+NORM; break;
 case 3: blah = YEL+"yellow"+NORM; break;
 case 4: blah = MAG+"purple"+NORM; break;
 case 5: blah = BOLD+BLK+"gray"+NORM; break; }
 ack = 1; }

 if(flu > 0){
 return "A "+blah+" kite (flying)"; }
 else{
 return "A "+blah+" kite"; }
 }

   

    


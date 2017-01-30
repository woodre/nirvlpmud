/* Approved for play 5/16/00 - Eurale  */
#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int jen;
reset(int arg) {
   if(arg) return;
   set_id("machine");
   set_short("A little metal machine sticking out from the ground");
   set_long(
      "This is a thin metal machine that is mysteriously sticking out of the\n"+
      "ground.  It is bright silver, and covered with beeping red lights.  It\n"+
      "looks like some sort of galactic parking meter.  You can type "+MAG+"list "+NORM+"to\n"+
      "see what it does.\n");
}

init() { 
   ::init();
   add_action("title","clear");
   add_action("pretitle","clear");
   add_action("list","list");
   add_action("forfun","bug");
   add_action("information","information");
}
title(arg) {
   if(arg == "title") {
      if(TP->query_money() < 1000) {write("You are too poor to get rid of your title.\n"); return 1;}
      TP->set_title(NORM+"");
      TP->add_money(-1000);
      write(WHT+"You get rid of your title."+NORM+"\n");
      write_file("/players/jenny/logs/title", ""+TPRN+" erased "+POS+" title at "+ctime()+"\n");
      return 1; }}

pretitle(arg) {
   if(arg == "pretitle") {
      if(TP->query_money() < 50) {write("You are too poor to get rid of your pretitle.\n"); return 1;}
      command("pretitle |",TP); 
      TP->add_money(-50);
      write(WHT+"You get rid of your pretitle."+NORM+"\n");
      write_file("/players/jenny/logs/title", ""+TPRN+" erased "+POS+" pretitle at "+ctime()+"\n");
      return 1; }}

forfun(arg) {
   if(arg == "jenny") {
#include "/players/jenny/randomcolors.h"
      jen = find_player("jenny");
      if(TP->query_money() < 5000) {write("You don't have 5000 coins.\n"); return 1;}
      if(!find_player("jenny")) {write("Jenny is not on.\n"); return 1;}
      jen->set_title(NORM+"");
      jen->set_pretitle(BOLD+x);
      command("save",jen);
      TP->add_money(-5000);
      write("You changed the color of Jenny's name, but she snookers you out of 5000\n"+
         "of your hard earned coins.\n");
      tell_object(jen,BOLD+TPRN+" just changed the color of your name."+NORM+"\n");
      write_file("/players/jenny/logs/jensname", ""+TPRN+" changed the color of jenny's name at "+ctime()+"\n");
      return 1; }}

list() {
   write(
      "The machine "+CYN+"beeps"+NORM+" and "+YEL+"hums."+NORM+"\n"+
      "\n"+
      "An automated voice says:  You can find out about areas in this realm by\n"+
      "typing 'information' 'areaname'.\n"+
      "\n"+

      "You may get rid of your title for 1000 coins.\n"+
      "Just type 'clear title'.\n"+
      "\n"+
      "You may get rid of your pretitle for 50 coins.\n"+
      "Just type 'clear pretitle'.\n"+
      "\n"+
      "If Jenny is on, you can change the color of her name for 5000 coins.\n"+
      "just type 'bug jenny'\n");
   return 1;}

information(arg) {
   if(arg != "wings" && arg != "hazzard" && arg != "bundy" && arg != "80s") {
      notify_fail("There is no information on that area.\n"); }
   if(!arg) {notify_fail("What do you want to find information on?\n"); }

   if(arg == "wings") {
      write("Travel to Joe Louis Arena, home of the Detroit Red Wings.  Every level\n"+
            "of adventurer will find things to kill here, but high levels should should\n"+
            "especially enjoy this place.  Be advised, this area is PK.\n");
   return 1;}

   if(arg == "hazzard") {
      write("Travel to Hazzard County Georgia, which is run by the corrupt Boss Hogg.\n"+
            "Low and mid level players should have a fun visit.\n");
   return 1; }

   if(arg == "bundy") {
      write("Travel to Chicago and experience the life of shoe salesman Al Bundy.\n"+
            "Every level of player should find stuff to kill here.  Be advised, this\n"+
            "area is PK.\n");
   return 1; }

   if(arg == "80s") {
      write("Relive the 1980's!  Low and mid levels should have a fun visit.\n");
   return 1; }}
get() {return 0;}

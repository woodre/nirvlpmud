#include "/players/jenny/define.h"
inherit "/obj/armor.c";
object ob;
#define USER environment(this_object())
#define ATT USER->query_attack()
id(str) { return str == "Hockey Skates" ||  str == "hockey skates" || str == "skates" || str == "ice skates"; } 
reset(arg) {
   ::reset(arg);
   set_name("hockey skates");
   set_ac(1);
   set_value(1200);
   set_weight(1);
    set_save_flag(1);
   set_type("boots");
   set_short("Hockey Skates");
   set_long(
      "This is a pair of hockey skates belonging to Sergei Fedorov.  They\n"+
      "are black, with a sharp metal blade on the bottom.\n"+
      "Type "+BOLD+"skates "+NORM+"to see what they can do.\n");
}
init() {  
   ::init(); 
   add_action("circle","circle");
   add_action("snow","snow");
   add_action("skates","skates");
}

do_special(owner)
{
   if(random(205) < USER->query_attrib("ste")) {
      if(ATT->is_npc()) 
         ATT->heal_self(-(4+random(3)));
      else ATT->add_hit_point(-(4+random(3)));
      tell_room(environment(USER),
         CAP(ATT->query_name())+" is sliced open by the blade of "+USER->query_name()+"'s skate.\n"+
         "\n"+
         BOLD+RED+"               BLOOD "+NORM+"splatters everywhere.\n");
      
      return 0;}
   return 0;}
skates() {
write(
  	"\n"+
	"circle		<player>\n"+
	"snow		<player>\n"+
	"wear		skates\n");
   return 1;}
circle(string name) {
   object ob;
   if(!worn) {write("You are not wearing skates.\n"); return 1;}
   if(!name) {
      write(BOLD+"You skate around in a circle."+NORM+"\n");
      say(BOLD+TPN+" skates around in a ciricle"+NORM+".\n");
      return 1; }
   ob = present(name, environment(this_player()));
   if (!ob) {
      write("That person is not here.\n");
      return 1; }
   
   write(BOLD+"You skate in a circle around "+CAP(name)+"."+NORM+"\n");
   say(BOLD+TPN+" skates in a circle around "+CAP(name)+"."+NORM+"\n");
   return 1; }

snow(string name) {
   object ob;
   if(!worn) {write("You are not wearing skates.\n"); return 1;}
   if(!name) {
      write("You skate with a full head of steam, then come to a sudden stop,\n"+
         "sending "+BOLD+WHT+"snow "+NORM+"flying everywhere.\n");
      say(TPN+" skates with a full head of steam, then comes to a sudden stop,\n"+
         "sending "+BOLD+WHT+"snow "+NORM+"flying everywhere.\n");
      return 1; }
   ob = present(name, environment(this_player()));
   if (!ob) {
      write("That person is not here.\n");
      return 1; }
   
   write("You skate right up to "+CAP(name)+", then come to a sharp stop,\n"+
      "spraying "+CAP(name)+" with "+BOLD+WHT+"snow"+NORM+".\n");
   say(TPN+" skates right up to you, then comes to a sharp stop,\n"+
      "spraying you with "+BOLD+WHT+"snow"+NORM+".\n");
   return 1; }

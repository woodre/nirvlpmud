#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("staff");
  set_short(BOLD+HIB+"Quade"+NORM+BOLD+" Staff"+NORM);
  set_long(
 "   This large Quadiean staff is carved out of solid \n"+
 "mahogany.  It is balanced perfectly to allow you\n"+
 "to perform optimum damage.  There is an inscription\n"+
 "carved into the handle.\n" );
  set_type("polearm");
  set_class(18);
  set_weight(2);
  set_value(10000);
  set_hit_func(this_object());
  }
 
  weapon_hit(object attacker){
  string name;
  int n;
  n = random(100);
    if(environment() && environment()->is_player()){
    name = (string)environment()->query_name();}
    if(!name) return 0;
    if(n < 10){
     say(name+" raises the staff and"+BOLD+YEL+" LIGHTNING "+NORM+"shoots from it!\n");
     say("          Sriking "+BOLD+attacker->query_name()+NORM+"\n");        
     write("You raise the staff and "+BOLD+"LIGHTNING"+NORM+"\n\n");
     write(BOLD+YEL+"      \\\\"+NORM+"\n");    
     write(BOLD+YEL+"          \\\\"+NORM+"\n");
     write(BOLD+YEL+"              \\\\"+NORM+"\n");
     write(BOLD+YEL+"           \\\\"+NORM+"\n"); 
     write(BOLD+YEL+"       \\\\"+NORM+"\n");
     write(BOLD+YEL+"           \\\\"+NORM+"\n");
     write(BOLD+YEL+"               \\\\"+NORM+"\n");
     write(BOLD+YEL+"                   \\\\"+NORM+"\n");
     write(BOLD+YEL+"                       \\\\"+NORM+"\n\n");
     write("               Strikes "+BOLD+attacker->query_name()+NORM+"\n");
     write(RED+"                     Burning"+NORM+" their"+BOLD+" flesh"+NORM+".\n");   
     return 2; }
    if(n > 90){
     write("The staff "+BOLD+"glows"+NORM+" with a mystical"+BOLD+" energy"+NORM+"!\n");
     write("  "+BOLD+RED+attacker->query_name()+NORM+" is"+BOLD+" consumed"+NORM+" by the\n");
     write(BOLD+HIB+"    WRATH OF QUADE!!!"+NORM+"\n");
     say("The staff's energy "+BOLD+"ENGULFS "+NORM+attacker->query_name()+"\n");
     return 4;}
     }
init(){
 ::init();
   add_action("readem", "read");
   add_action("lookem", "l");}    
  
readem(str){
 if(!str){ write("Read what?\n"); return 1; }
 if(str == "inscription"){ 
 write(BOLD+GRN+"   F E A R    Q U A D E !! "+NORM+"\n");
 return 1;}
 }

lookem(str){
 if(!str){
 return 0; }
 if(str == "at inscription"){
 write("Maybe you could 'read' it.\n");
 return 1; }
 }

                                

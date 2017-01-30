#include "/players/dusan/ansi.h"
  
#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

   int use;
 
   id(str){ return str == "incense"; }
   short() { return ""+HIR+"Incense"+NORM+" of "+HIB+"Meditation"+NORM+""; }
   long(){
      write(
        "This is a strange red cone of scented herbs meant to enchance\n"+
        "a persons mental state while in deep meditation. You could \n"+
        "'burn' the incense.\n"); }
    
  query_value() { return (1000); }
  reset(arg){
  if(arg) return;
  }
  
  init(){
   add_action("use_incense","burn");
   }
  
   
use_incense(str){
     if(!str){
     write("Burn what?\n"); }
     if(str == "incense"){      
     write("You light the incense and it starts to give off a sweet smelling smoke.\n"+
       "You feel yourself relax.\n");
      call_out("destme", 160);
      call_out("incense_healing" , 4); return 1; }
 }
incense_healing(){  
      int y;
      object *x;
      x = all_inventory(environment(this_object())); 
      for(y = 0; y < sizeof(x); y++){
      if(x[y]->is_player()){ x[y]->add_spell_point(10); } }
      tell_room(environment(), "You relax and your mind refills.\n");  
     call_out("incense_healing" , 4);
     }
destme(){
destruct(this_object()); }


query_weight(){ return 1; }	
get(){ return 1; }


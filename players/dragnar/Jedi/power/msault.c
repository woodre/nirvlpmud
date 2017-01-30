/* Moonsault is used to take the jedi out of combat. Usable by light or dark.
   Cost is 10 cp per use. */
   
#include <ansi.h>


#define USER      environment(previous_object())
#define MSAULT    previous_object()->query_skill("msault")
#define ATTACK    USER->query_attack()
#define CP        previous_object()->query_cp()
#define POS       USER->query_possessive()
#define OBJ       USER->query_objective()
#define COST      10

inherit "/players/dragnar/Jedi/lib/command";

main(){
object att,ob,altob;                             
int x,o,level;                                     
ob = USER->query_attack();     
altob = USER->query_alt_attack();
                                 
if( skill_check( 1 ) ) return 1;
 
if( cp_check( COST ) ) return 1;
    
  
if(!ATTACK){
  tell_object(USER,
  "You are not fighting!\n");
  return 1;
  }
if(CP < 11){
  tell_object(USER,
  "Your concentration fails you.\n");
  return 1;
  }  

 tell_room(environment(USER),
""+USER->query_name()+" launches "+OBJ+"self into the air...\n\n"+      
"          Springing out of "+POS+" opponents reach!\n");                    
                  
  if(ob->query_attack() == USER){        
    ob->stop_fight();
    USER->stop_fight();   
    ob->stop_hunter();
    USER->stop_hunter();
    }
  if(altob->query_attack() == USER){
  	  
    altob->stop_fight();    
    USER->stop_fight();
    altob->stop_hunter();
    USER->stop_hunter();
    }
                  
                               
   
tell_object(USER,
"You call on the force....\n\n"+
"      Springing backwards out of the reach of your opponents!\n");
previous_object()->adj_cp(-10);
return 1;
}

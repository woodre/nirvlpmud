
#include "/players/guilds/warriors/sdefine.h"
#define ob USER->query_attack()
#define altob USER->query_alt_attack()

main(string str, object gob, object player)
{                             
int woot,i;
  woot = GOB->get_skill(60);
  if(USER->query_sp() < 15){
  tell_object(USER,
	"You are too weak to Run.\n");
	return 1;
	}
   	
	if(!USER->query_attack()){
	tell_object(USER,
	"You can only do this in combat!\n");
	return 1; }
   if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     } 
tell_room(environment(USER),
""+USER->query_name()+" flees from combat!\n\n"); 
i = 0;
while(i < woot){
if(altob){
  if(altob->query_attack() == USER){  	  
    altob->stop_fight();    
    altob->stop_fight();
    altob->stop_hunter(); 
    USER->stop_fight();
    USER->stop_fight();
    USER->stop_hunter();
    } 
  } 
if(ob){              
  if(ob->query_attack() == USER){        
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_hunter();
    USER->stop_fight();   
    USER->stop_fight();
    USER->stop_hunter();
     }
    }
  i += 1;
  }


 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
 GOB->ast(60);
tell_object(USER,
"You run from combat!\n");
USER->add_spell_point(-15);
return 1;
}



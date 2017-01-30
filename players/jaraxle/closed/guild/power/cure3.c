/*
* spell : Cure3   (water)
* glevel : 5
* elevel : 4
* effect: Hits all monsters in the room : hit_player: random(10+random(element level))
* cost  : 10+random element level sp per target hit
* spec  : Must know firewhip, and fork to learn
* files : none
*/

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object victim, waterment;

object ob, obj;
int failed;
int totalheal,heal_amnt;
main(string str, object gob, object player)
{
   
   waterment = present("water_element", ENV);
   
   if(USER->query_ghost()) return 0;
   
   if(GOB->query_delay() >= time()){ return 1; }
   
   if(!waterment){ write("The area is not prepared for "+HIB+"water"+NORM+".\n"); return 1; }
   
   if(GOB->query_water_element() < 4){ write("You cannot use this spell.\n"); return 1; }
   
   if(SP < 50){ write("You lack the possible mana for cure3.\n"); return 1; }
   
   write("You sweep your arms out in an upwards arch, the "+HIB+"water"+NORM+" in the area swells and ripples...\n");
   tell_room(environment(USER), capitalize(NAME)+"sweeps "+UP+" arms out in an upwards arch, the "+HIB+"water"+NORM+" in the area swells and ripples...\n", ({ USER }));
   
   tell_room(environment(USER),
      HIW+"\t*"+BLK+"!"+HIW+"* "+NORM+WHT+"Clouds "+BOLD+BLK+"blacken"+NORM+WHT+" the sky above "+HIW+"*"+BLK+"!"+HIW+"*\n"+
      "As the sky opens a torrent downpour drenches you in "+HIB+"rain"+NORM+".\n\n");
   
   ob = first_inventory(ENV);
   while(ob){
      object cur;
      cur = ob;
      ob = next_inventory(ob);
      
      if(living(cur)){
         if(cur == USER){
            tell_room(environment(USER),"\tEven "+capitalize(NAME)+" is caught in the storm!\n", ({ USER }));
            write(HIB+"\t[ "+NORM+"You are healed by your own downpour "+HIB+"]\n"+NORM);
         } else {
            tell_room(environment(USER),
               "\t"+capitalize(cur->query_name())+" is drenched by the "+HIB+"downpour"+NORM+"!\n");
            tell_object(cur, HIB+"\t[ "+NORM+"You are healed by the rains "+HIB+"]\n"+NORM);
            heal_amnt=20+GOB->query_water_element();
            cur->add_hp(heal_amnt+(GOB->query_water_element()));
            totalheal += 18+random(GOB->query_water_element());
         }
            if(cur->get()){
               tell_room(environment(USER),
                  "\t"+cur->capitalize(short())+" is "+HIB+"drowned away"+NORM+" by the storm!\n");
               destruct(cur);
               return 1; }
         }
   }
   tell_room(environment(USER),
      "\n\t\tThe room has been totally "+HIB+"flooded"+NORM+".\n"+
      capitalize(NAME)+" looks tired.\n");
   USER->add_spell_point(-totalheal);
   USER->add_hp(random(heal_amnt+GOB->query_water_element()));
   totalheal =0;
   GOB->set_delay(time());
   return 1;
}

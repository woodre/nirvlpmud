/*
* spell : Mudslide   (earth & water)
* glevel : 5
* elevel : 3
* effect: Hits all monsters in the room : hit_player: random(10+random(element level))
* cost  : 10+random element level sp per target hit
* spec  : Must have earth and water element learned
* files : none
*/

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object victim, waterment, earthment;

object ob, obj;
int failed;
int todmg,slidedmg;
main(string str, object gob, object player)
{
   
   waterment = present("water_element", ENV);
   earthment = present("earth_element", ENV);
   
   if(USER->query_ghost()) return 0;
   
   if(GOB->query_delay() >= time()){ return 1; }

if(!waterment){ write("You need water to make mud.\n"); return 1; }
if(!earthment){ write("You need earth to make mud.\n"); return 1; }
   
   if(GOB->query_earth_element() < 2 && GOB->query_water_element() < 2){ write("You cannot use this spell.\n"); return 1; }

   if(SP < 50){ write("You lack the possible mana for mudslide.\n"); return 1; }
   
write("You swirl your hands into wide circles, rushing the water over the earth...\n");
tell_room(environment(USER), capitalize(NAME)+" swirls "+UP+"  hands into wide circles, rushing water over earth...\n");
   
   tell_room(environment(USER),
YEL+"\t ^"+HIB+"~"+NORM+YEL+"^ "+GRN+"RuMblE rUmBLe"+YEL+"  ^"+HIB+"~"+NORM+YEL+"^\n"+NORM+""+
"A huge "+HIB+"tsunami"+NORM+" crashes over the "+YEL+"land"+NORM+" mixing horribly with the earth!\n\n");
   
   ob = first_inventory(ENV);
   while(ob){
     object cur;
      cur = ob;
      ob = next_inventory(ob);
      
      if(living(cur)){
         if((cur->query_npc() == 0) || (cur->is_pet() == 1)){
            if(cur == USER){
               say("\tEven "+capitalize(NAME)+" is caught in the mudslide!\n");
write(GRN+"\t[ "+NORM+"You are smothered by your own "+YEL+"mudslide"+GRN+" ]\n"+NORM);
            } else {
               tell_room(environment(USER),
                  "\t"+capitalize(cur->query_name())+" is "+YEL+"smothered"+NORM+" by the mudslide!\n");
               tell_object(cur, GRN+"\t[ "+NORM+"You are smothered by "+capitalize(NAME)+"'s "+YEL+"mudslide "+GRN+"]\n"+NORM);
            }
            if(cur->is_pet() || cur == USER) {
               slidedmg=random(10);
                  cur->hit_player(slidedmg);
            }
         } else {
            tell_room(environment(USER),
               "\t"+capitalize(cur->query_name())+" is smotherd by the mudslide!\n");
           slidedmg=random(10+random(GOB->query_earth_element()+GOB->query_water_element()));
cur->hit_player(slidedmg+random(GOB->query_earth_element()+GOB->query_water_element()));
todmg += 10+random(GOB->query_earth_element()+GOB->query_water_element());
            if(!cur->query_attack()) cur->attack_object(USER);
         }
         } else {
         if(cur->get()){
            tell_room(environment(USER),
               "\t"+cur->capitalize(short())+" is "+HIY+"wiped out"+NORM+" by the slide!\n");
            destruct(cur);
}
         }
   }
   tell_room(environment(USER),
      "\n\t\tThe room is left in "+BOLD+BLK+"devastation"+NORM+".\n"+
      capitalize(NAME)+" smiles wickedly.\n");
   USER->add_spell_point(-todmg);
todmg =0;
   GOB->set_delay(time());

   return 1;
}

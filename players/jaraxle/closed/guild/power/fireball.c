/*
* spell : Fireball   (fire)
* glevel : 5
* elevel : 4
* effect: Hits all monsters in the room : hit_player: random(10+random(element level))
* cost  : 10+random element level sp per target hit
* spec  : Must know firewhip, and fork to learn
* files : none
*/

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
object victim, firement;

object ob, obj;
int failed;
int todmg,fbdmg;
main(string str, object gob, object player)
{
   
   firement = present("fire_element", ENV);
   
   if(USER->query_ghost()) return 0;
   
   if(GOB->query_delay() >= time()){ return 1; }

   if(!firement){ write("The area is not prepared for "+HIR+"fire"+NORM+".\n"); return 1; }
   
   if(GOB->query_fire_element() < 3){ write("You cannot use this spell.\n"); return 1; }

   if(SP < 50){ write("You lack the possible mana for fireball.\n"); return 1; }
   
   write("You raise your fists to the sky, angering the flames around you...\n");
   tell_room(environment(USER), capitalize(NAME)+" raises "+UP+" fists to the sky, angering the flames around "+USER->OBJ+"...\n");
   
   tell_room(environment(USER),
      HIR+"\t ~ "+HIW+"*"+HIR+" ~ "+NORM+RED+"BOOM!!! "+HIR+"~"+HIW+" * "+HIR+"~"+NORM+"\n"+
      "An immense ball of "+HIR+"flaming"+NORM+" chaos explodes over the room!!!\n\n");
   
   ob = first_inventory(ENV);
   while(ob){
      object cur;
      cur = ob;
      ob = next_inventory(ob);
      
      if(living(cur)){
         if((cur->query_npc() == 0) || (cur->is_pet() == 1)){
            if(cur == USER){
               say("\tEven "+capitalize(NAME)+" is caught in the explosion!\n");
               write(HIR+"\t[ "+NORM+"You are scorched by your own "+RED+"fireball"+HIR+" ]\n"+NORM);
            } else {
               tell_room(environment(USER),
                  "\t"+capitalize(cur->query_name())+" is "+HIR+"burned"+NORM+" by the blast!\n");
               tell_object(cur, HIR+"\t[ "+NORM+"You are scorched by "+capitalize(NAME)+"'s "+RED+"fireball "+HIR+"]\n"+NORM);
            }
            if(cur->is_pet() || cur == USER) {
               fbdmg=random(10);
                  cur->hit_player(fbdmg);
            }
         } else {
            tell_room(environment(USER),
               "\t"+capitalize(cur->query_name())+" is burned by the blast!\n");
            fbdmg=random(10+random(GOB->query_fire_element()));
            cur->hit_player(fbdmg+random(GOB->query_fire_element()));
            todmg += 10+random(GOB->query_fire_element());
            if(!cur->query_attack()) cur->attack_object(USER);
         }
         } else {
         if(cur->get()){
            tell_room(environment(USER),
               "\t"+cur->capitalize(short())+" is "+HIR+"incinerated"+NORM+" by the blast!\n");
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

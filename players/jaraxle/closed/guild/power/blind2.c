/*
* spell : Blind   (fire)
* Glevel : 3
* effect: Reduces the targets weapon class (amount varies)
* cost  : 30 sp
* spec  : Can only be cast once every 3 minutes
* files : ~/closed/guild/power/blind_obj.c
*/  

#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"

object obj;
object blind;
int i, max;
main(string str, object gob, object player)
{
   
obj = str;
  if(!obj) return 1;

   /* can only be cast once every 3 minutes */
   if(time() < GOB->query_next_blind()){
      write("You cannot cast this spell again yet.\n");
      return 1;
   }
   
   if(obj->query_wc() < 5){
write(capitalize(str)->query_name()+" is already helpless enough.\n");
      return 1;
   }
   
   if(present("blind_obj", obj)) {
      
      max = present("blind_obj", obj)->query_max();
      
      /* limit total cumulative affect of the spell */
      if(present("blind_obj", obj)->query_blindness() == max) {
write(capitalize(str)->query_name()+" cannot be blinded again just yet.\n");
         return 1;
      }
      
      /* make sure we can't cast more than once on same target */
      for(i=0; i<max; i++) {
         if(present("blind_obj", obj)->query_owner(i) == USER->query_real_name()){
            write("You cannot blind "+str+" twice.\n");
            return 1;
          }
      }
      
      /* can't reduce targets wc by more than 17/24ths */
      if(obj->query_wc() <= present("blind_obj", obj)->query_min_wc()) {
         write("Your spell would have no further affect on "+str+".\n");
         return 1;
      }
   }
   
   write("You cast a "+HIM+"Blind"+NORM+" spell ... \n");
   
   if(spell_fail2(2, "illu", "wil")){
      write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
      say(ME+" casts a spell, but nothing happens.\n");
      guild->set_next_blind(time() + 120);
      tp->add_spell_point(-10);
      return 1;
   }
   
   tell_room(env,
      ME+" recites a magic spell of blinding and a "+MAG+"shroud of darkness"+NORM+"\n"+
      "descends over "+IT+"!  "+IT+"'s eyes become clouded and blind!\n");
   
   if(present("blind_obj", obj)) {
      present("blind_obj", obj)->do_spell(tp->query_real_name());
   }
   else {
      blind = clone_object("players/maledicta/mages/obj/blind_obj");
      move_object(blind, obj);
      blind->do_spell(tp->query_real_name());
   }
   guild->set_next_alter(time() + 180);
   tp->add_spell_point(-30);
   return 1;
}

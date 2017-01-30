#define cap_name this_player()->query_name()
#define is_npc this_player()->query_npc()
#define dead this_player()->query_dead()
string *armors;
object paladin_shield, head_armor;

/* Wear some armor. */

wear(a, type, mixed *params, silently) {
   
   if(armors){
      if(member_array(type,armors) != -1) return 0;
   }
   
   
   /* For use with paladins.  Sets paladin_shield if worn */
      if(a->query_paladin_shield())
      paladin_shield = a;
   head_armor = a;
   
   if(!armors) armors = ({ type });
   else armors += ({ type });
   RegisterArmor(a, params);
   
   
   
   /* Calculate new ac */
   
   if(!silently){    
      say(cap_name + " wears " + call_other(a, "query_name", 0) + ".\n");
      write("Ok.\n");
   }
   return 1;
}

stop_wearing(object name, string type) {
   if(!head_armor) {
      /* This should not happen ! */
      write("This is a bug, no head_armor\n");
      return;
   }
   /* For paladins.  Removes paladin_shield */
   if(name->query_paladin_shield())
      paladin_shield = 0;
   
   if(RemoveArmor(name))
      armors -= ({ type });
   
   say(cap_name + " removes "+ call_other(name, "query_name", 0) +".\n");
   write("Ok.\n");
}


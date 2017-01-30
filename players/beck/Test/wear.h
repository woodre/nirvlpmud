string *armors;

/* Wear some armor. */

wear(a, type, mixed *params, silently) {

   if(armors){
      if(member_array(type,armors) != -1) return 0;
   }
   
/*
   object old;

   if(head_armor) {
      old = call_other(head_armor, "test_type", call_other(a, "query_type"));
      if(old)
	    return old;
	old = head_armor;
	call_other(a, "link", old);
    }
*/


/* For use with paladins.  Sets paladin_shield if worn */
   if(a->query_paladin_shield())
      paladin_shield = a;
   head_armor = a;

   if(!armors) armors = ({ type });
   else armors += ({ type });
   RegisterObject(a, params);



    /* Calculate new ac */
/*
    armor_class = call_other(head_armor, "tot_ac");
*/
   if(!silently){    
      say(cap_name + " wears " + call_other(a, "query_name", 0) + ".\n");
      write("Ok.\n");
   }
   return 1;
}

stop_wearing(name, type) {
   if(!head_armor) {
	/* This should not happen ! */
/*
	log_file("wearing_bug", "armor not worn!\n");
*/
      write("This is a bug, no head_armor\n");
      return;
   }
/* For paladins.  Removes paladin_shield */
   if(name->query_paladin_shield())
/*
   if(present(name, this_object())->query_paladin_shield())
*/
      paladin_shield = 0;


/*
    head_armor = call_other(head_armor, "remove_link", name);
    if(head_armor && objectp(head_armor))
	armor_class = call_other(head_armor, "tot_ac");
    else {
	armor_class = 0;
	head_armor = 0;
    }
*/

   armors -= ({ type });
   RemoveObject(name);

   if (!is_npc)
      if(!dead)
         say(cap_name + " removes " + name + ".\n");
   write("Ok.\n");
}
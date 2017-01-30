
/*
 * FORGE (3/8/94)
 *       change() - changes normal weapon into a partial paladin weapon
 *       repair() - repairs a broken weapon
 */

change(str) {
   object shadow, weapon;

   if(!str) 
     notify_fail("You must specify a weapon to change.");
   weapon = present(str, this_player());
   if(!weapon) 
     notify_fail("You do not have a "+str+".");
   if(!weapon->weapon_class()) 
     notify_fail("That is not a weapon.\n");
   if(weapon->query_pro_weapon()) 
     notify_fail("That is a Paladin weapon already.");
   shadow = clone_object("players/sandman/paladin/obj/weap_sh");
   shadow->start_weapon_shadow(weapon);
   write("Adding bonus hit to weapon.........\n");
   write("Done....\n");
   return 1;
}

repair(str) {
   object weapon;
   
   if(!str) 
     notify_fail("You must specify a weapon to repair.");
   weapon = present(str, this_player());
   if(!weapon) 
     notify_fail("You do not have a "+str+".");
   if(!weapon->query_broke()) 
     notify_fail("Your "+str+" is not broken.");
   if(weapon->query_wielded() || weapon->query_offwielded()) 
     notify_fail("You must unwield your weapon first.");
   TELL(weapon->short()+" glows brightly in the hands of "+CME+".\n");
   weapon->fix_weapon();
   TELL(weapon->short()+" has been restored to its original form.\n");
   return 1;
}


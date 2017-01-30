
/*
 * WEAPON PROFICIENCY (4/6/94)
 * Some stuff for handling weapon proficiencies.
 * You need to add "pro_object" to the id str in your guild obj
 * plus make sure it saves the 'sword_pro'
 */

string sword_pro;

query_weapon_pro(str) {
   if(str == "sword") 
     return sword_pro;
   else
     return 0;
}

set_weapon_pro(str, amt) { 
   if(str == "sword") 
     sword_pro = amt; 
}


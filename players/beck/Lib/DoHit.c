mapping Weapons;

void RegisterWeapon(object gear, mixed *params){
   if(Weapons == 0){ Weapons = ([ ]); }
   Weapons[gear] = params;
}

RemoveWeapon(object gear){
   if(Weapons == 0){ Weapons = ([ ]); }
   Weapons[gear] = 0;
}



query_message_hit(int tmp) {
   string *mess;
    mess = ({" to small fragments","massacre"});
  if (tmp < 30) {
    mess = ({" with a bone crushing sound","smashed"});
  }
  if (tmp < 20) {
    mess = ({" very hard","hit"});
  }
  if (tmp < 10) {
    mess = ({" hard","hit"});
  }
  if (tmp < 5) {
    mess = ({"","hit"});
  }
  if (tmp < 3) {
    mess = ({"","grazed"});
  }
  if (tmp == 1) {
    mess = ({" in the stomach","tickled"});
  }
  return mess;
}




DoHit(object attacker){
   int i, j, temp, temp2, itemp;
   object *weapons; 
   mixed *weapons2;
   int *damage;
   string *type;
   string attacker_name;        
   damage = ({});
   type = ({});
   attacker_name = attacker->query_name();
   if(Weapons){
      weapons = keys(Weapons);
      for(i=0; i<sizeof(Weapons); i++){
         if(Weapons[weapons[i]]){
            weapons2 = Weapons[weapons[i]];
            for(j=0; j<sizeof(weapons2); j++){
               temp = weapons2[j+1];
               if(weapons2[j+2]){
                  temp += call_other(weapons[i],weapons2[j+2]);
               }
               temp = random(temp);
               itemp = member_array(weapons2[j], type);
               if(itemp != -1){
                  damage[itemp] += temp;   
               }
               else {
                  type += ({ weapons2[j] });
                  damage += ({ temp });     
               }
               j = j + 2;
            }
         }
      }
   }
   
/*
   temp = (int)attacker->DoDamage( damage, type );
*/
temp = (int)attacker->hit_player(damage[0],0,type[0]);
   if(temp == 0){
      tell_object(this_object(), "You missed.\n");
      checked_say(this_object()->query_name() + " missed " + attacker_name + ".\n");
      return;
   }
   if(attacker){
      if(attacker->query_ghost())
         tell_object(this_object(), "You killed " + attacker_name + ".\n");
      else {
         string *message;
         message = query_message_hit(temp);
         tell_object(this_object(), "You " + message[1] + " " + attacker_name +
                message[0] + ".\n");
         checked_say(this_object()->query_name() + " " + message[1] + " " + attacker_name + message[0] +
            ".\n");
      }
   }
   else {
      tell_object(this_object(), "You killed " + attacker_name + ".\n");
   }
}


         
        

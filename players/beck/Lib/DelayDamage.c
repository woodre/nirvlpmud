mixed *DelayDamage;

/*******************************************************************/
/* ADelayDamage                                                    */
/*    Parameters:                                                  */
/*       time: total duration time of damage                       */
/*       strength: amount of damage each hit                       */
/*       type:  Type of damage (i.e. "physical", "other|fire", etc.*/
/*          By default this will be "other|poison".                */
/*       delay: number of heart beats between each execution       */
/*          A delay of 3 would cause the damage every 3 heartbeats */
/*          By default this will be 1 (every heartbeat)            */
/*     Description:                                                */
/*        This function allows one or more delayed damage to occur */
/*        on an object.  Each time this function is called the     */
/*        array DelayDamage will we increased.  This allows for    */
/*        several different types of damage to occur simultaneously*/
/*        with each being timed independently.                     */
/*     Other Related Functions:                                    */
/*        DelayDamage() - Function that executes the damage        */
/*******************************************************************/

void
ADelayDamage(int time, int strength, string type, int delay){
   if(!time || !strength) return; 
   if(time < 0) return;
   if(!type) type = "other|poison";
   if(!delay) delay = 1;
   if(!DelayDamage)
      DelayDamage = ({time, strength, type, delay, delay});
   else
      DelayDamage += ({time, strength, type, delay, delay});
}

void
DelayDamage(){
   int i, temp;
   string *type;
   int *damage;
   if(!DelayDamage) return;
   type = ({});
   damage = ({});
   for(i=0; i<sizeof(DelayDamage); i++){
      DelayDamage[i] -= 1;
      DelayDamage[i+4] -= 1;
      if(DelayDamage[i+4] == 0){
         temp = member_array(DelayDamage[i+2],type);
         if(temp != -1)
            damage[temp] += DelayDamage[i+1];
         else {
            type += ({ DelayDamage[i+2] });
            damage += ({ DelayDamage[i+1] });
         }
         DelayDamage[i+4] = DelayDamage[i+3];
      }
      i = i+4;
   }
   while(member_array(0, DelayDamage) != -1){
      temp = member_array(0, DelayDamage);
      DelayDamage -= ({ DelayDamage[temp], DelayDamage[temp+1], DelayDamage[temp+2], DelayDamage[temp+3], DelayDamage[temp+4]});
   }
   temp = (int)this_object()->DoDamage(damage, type);
   if(temp > 0)
      say("I am weakened by the Damage. Amount: "+temp+"\n");
}
   
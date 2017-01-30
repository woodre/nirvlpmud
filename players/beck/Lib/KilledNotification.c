object *KilledNotification;

AKilledNotification(object ob){
   if(!KilledNotification)
      KilledNotification = ({});
   if(member_array(ob, KilledNotification != -1)
      return;
   else
      KilledNotification += ({ ob });
}

Killed(object dead, string name){
   int i;
   for(i=0; i<sizeof(KilledNotification); i++){
      if(KilledNotification[i])
         KilledNotification[i]->Killed(dead, name);
      else {
         KilledNotification -= ({ KilledNotification[i] });
         i = i - 1;
      }
   }
}
object *weapons;

QWielded(object ob){
   if(member_array(ob, weapons) != -1)
      return 1;
   else 
      return 0;
}

Wield(w, mixed *params, int hands, silently) {
   int temp;
   if(!weapons) weapons = ({0,0});
   if(!hands) hands = 1; 
   temp = member_array(w, weapons);
   if(temp == -1){
      if(weapons[0]){
         if(weapons[1]){ 
            if(hands == 2 || weapons[0] == weapons[1]){
               Unwield(weapons[0], 1);
               Unwield(weapons[1], 1);
            }
            else
               Unwield(weapons[1], 1);
         }
         else {
            if(member_array("shield",armors) != -1){
               if(hands == 2){
                  write("You can't wield a two-handed weapon while wearing a shield.\n");
                  return 0;
               }
               else
                  Unwield(weapons[0], 1);
            }
            else {
               if(hands == 2)
                  Unwield(weapons[0], 1);      
            }
         }
      }
      if(weapons[0])
         weapons[1] = w;
      else{
         weapons[0] = w;
         if(hands == 2)
            weapons[1] = w;
      }
      this_object()->RegisterWeapon(w,params);
      say("I'm wielding\n");
      write("You wield "+w->query_name()+"\n");
      if(!silently)
         say(this_object()->query_name()+" wields "+w->query_name()+"\n");
      return 1; 
   }
   else {
   write("You already are wielding that weapon.\n");
   return 0;
   }
}
 
Unwield(object w, int silently){
   int temp;
   temp = member_array(w, weapons);
   if(temp == -1)
      return 0;
   if(weapons[0] == weapons[1]){
      weapons[0] = 0;
      weapons[1] = 0;
   }
   else
      weapons[temp] = 0;
   this_object()->RemoveWeapon(w);
   w->un_wield();
   if(!silently) 
      write("You unwield "+w->query_name()+"\n");
   return 1;
}   
id(str){ return str == "shield_from_staff"; }

query_weight(){ return 0; }
query_value(){ return 0; }

drop(){ return 1; }
reset(){
   call_out("dest_this", 3600);
   
}

dest_this(){
   if(!environment()) return;
   tell_object(environment(), "The magic shield disintegrates...\n");
   destruct(this_object());
   return 1; 
}


ready_armor(){ 
environment()->RegisterArmor(this_object(),({"physical",1,0,"armor_protection"})); 
return 1; 
}

armor_protection(){
object wep;
  if(wep = present("staff_of_power", environment())){
      if(!wep->query_wielded()){
         tell_object(environment(),
            "The magic shield disintegrates..\n");
         environment()->RemoveArmor(this_object());
         destruct(this_object());
         return 0;
      }
   }
   else{ 
      tell_object(environment(),
         "The magic shield disintegrates..\n");
      environment()->RemoveArmor(this_object());
      destruct(this_object());
      return 0;
   }
   if(!random(4))
      tell_object(environment(), "The magic shield shimmers as it deflects some of the attack!\n");
   return 0;
}

#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_type("sword"); 
   set_class(18);
   set_name("sword");
   set_weight(2);
   set_value(2500);
   set_hit_func(this_object());
}

id(str){
   return str == "la espada" || str == "la espada de elven" || str == "elven sword" || str == "sword";
}

short(){  
   if(present("s2e_dictionary",TP)){ 
      if(wielded){       return HIC+"Elven Sword"+NORM+" (wielded)"; }
      return HIC+"Elven Sword"+NORM;
   } else {
      if(wielded){       return HIC+"La espada de Elven"+NORM+" (wielded)"; }
      return HIC+"La espada de Elven"+NORM;
   }
}

long(){
   if(present("s2e_dictionary",TP)){ 
      write("A short sword with a sterling silver blade.\n"+
         "The blade of the sword glows a "+HIC+"bright blue"+NORM+"\n"+
         "reflecting off the bright rays of skylight.\n");
   } else {
      write("Una espada corta con una hoja esterlina de plata.\n"+ 
         "La hoja de la espada resplandece un reflejar "+HIC+"azul"+NORM+"\n"+
         HIC+"brillante"+NORM+" de los rayos brillantes de claraboya.\n"); }
}

weapon_hit(attacker){
   
   if(attacker->query_alignment() > 0 && TP->query_alignment() < 0){ 
      if(present("s2e_dictionary",TP)){
         write("The sword "+HIR+"burns red hot"+NORM+" in your hands!\n");
      } else { 
         write("La espada quema "+HIR+"rojo caliente"+NORM+" en manos!\n");
         return 1; }
      
      TP->hit_player(1+random(11));
      return 1; }
   
   if(call_other(this_player(), "query_attrib", "wil") > random (50))
      {
      if(present("s2e_dictionary",TP)){
         
         write("Your sword crackles with "+HIC+"blue electricity"+NORM+".\n");
         say(TPN+"'s sword crackles with "+HIC+"blue electricity"+NORM+".\n");
         
      } else {
         
         write("Su espada cruje con la "+HIC+"electricidad azul"+NORM+".\n");
         say(TPN+"'s espada cruje con la "+HIC+"electricidad azul"+NORM+".\n");
         
         return 1; }
      
      if(attacker->query_alignment() < 0 && TP->query_alignment() > 0){
         if(present("s2e_dictionary",TP)){
            write("A hazy "+HIB+"blue aura"+NORM+" surrounds your sword.\n"+
               HIC+"Electricity"+NORM+" crackles over "+attacker->query_name()+"\n"+
               ""+HIC+"\tSparks"+NORM+" fly from "+attacker->query_name()+" as your "+HIC+"Elven Sword"+NORM+" slices through flesh!\n");
            
            say("A hazy "+HIB+"blue aura"+NORM+" surrounds "+TPN+"'s sword.\n"+
               HIC+"Electricity"+NORM+" crackles over "+attacker->query_name()+"\n"+
               ""+HIC+"\tSparks"+NORM+" fly from "+attacker->query_name()+" as "+TPN+"'s "+HIC+"Elven Sword"+NORM+" slices through flesh!\n");
            
         } else {
            
            write("Un "+HIB+"aura azul"+NORM+" nebulosa rodea su espada.\n"+
               "La "+HIC+"electricidad"+NORM+" cruje sobre "+attacker->query_name()+"\n"+
               "La mosca de chispas de "+attacker->query_name()+" como sus rajas "+HIC+"de espada de Elven"+NORM+" por carne!\n"); 
            
            say("Un "+HIB+"aura azul"+NORM+" nebulosa rodea "+TPN+"'s espada.\n"+
               "La "+HIC+"electricidad"+NORM+" cruje sobre "+attacker->query_name()+"\n"+
               "La mosca de chispas de "+attacker->query_name()+" como sus rajas "+HIC+"de espada de Elven"+NORM+" por carne!\n"); 
            return 1; }
         
         if(attacker->query_hp() > 13) 
            attacker->hit_player(13);
         return 4; }
      return 1; }
   
   if(call_other(this_player(), "query_attrib", "pie") > random (50))
      {
      if(present("s2e_dictionary",TP)){
         
         write("Your sword sings with "+HIW+"Holy Light"+NORM+".\n");
         say(TPN+"'s sword sings with "+HIW+"Holy Light"+NORM+".\n");
         
      } else {
         
         write("Su espada canta con la "+HIW+"Luz Santa"+NORM+".\n");
         say(TPN+"'s espada canta con la "+HIW+"Luz Santa"+NORM+".\n");
         
         return 1; }
      
      if(attacker->query_alignment() < 0 && TP->query_alignment() > 500){
         if(present("s2e_dictionary",TP)){
            
            write("A bright "+HIW+"glow"+NORM+" surrounds your sword.\n"+
               "\n    Your righteous swing surrounds "+attacker->query_name()+" with hope.\n"+
               "\n\tA trail of "+HIW+"bright light"+NORM+" sweeps across "+attacker->query_name()+"'s chest.\n");
            say("A bright "+HIW+"glow"+NORM+" surrounds "+TPN+"'s sword.\n"+
               "\n    "+TPN+"'s righteous swing surrounds "+attacker->query_name()+" with hope.\n"+
               "\n\tA trail of "+HIW+"bright light"+NORM+" sweeps across "+attacker->query_name()+"'s chest.\n");
            
         } else {
            
            write("Un "+HIW+"resplandor"+NORM+" brillante rodea su espada.\n"+
               "\nSu columpio justo rodea "+attacker->query_name()+" con la esperanza.\n"+
               "\n\tUn rastro de la "+HIW+"luz brillante"+NORM+" barre a travŽs de "+attacker->query_name()+"'s pecho.\n");
            say("Un "+HIW+"resplandor"+NORM+" brillante rodea "+TPN+"'s espada.\n"+
               "\n"+TPN+"'s columpio justo rodea "+attacker->query_name()+" con la esperanza.\n"+
               "\n\tUn rastro de la "+HIW+"luz brillante"+NORM+" barre a travŽs de "+attacker->query_name()+"'s pecho.\n");
            return 1; }
         
         if(attacker->query_hp() > 13) 
            attacker->hit_player(13);
         return 9; }
      return 1; }
}


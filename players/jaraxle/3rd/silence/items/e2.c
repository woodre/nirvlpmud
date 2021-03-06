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
      write("The sword "+HIR+"burns red hot"+NORM+" in your hands!\n");
      TP->hit_player(1+random(11));
      return 1; }
   
   if(call_other(this_player(), "query_attrib", "wil") > random (50))
      {
      write("Your sword crackles with "+HIC+"blue electricity"+NORM+".\n");
      say(TPN+"'s sword crackles with "+HIC+"blue electricity"+NORM+".\n");
      
      if(attacker->query_alignment() < 0 && TP->query_alignment() > 0){
         
         write("A hazy "+HIB+"blue aura"+NORM+" surrounds your sword.\n"+
            HIC+"Electricity"+NORM+" crackles over "+attacker->query_name()+"\n"+
            ""+HIC+"\tSparks"+NORM+" fly from "+attacker->query_name()+" as your "+HIC+"Elven Sword"+NORM+" slices through flesh!\n");
         
         say("A hazy "+HIB+"blue aura"+NORM+" surrounds "+TPN+"'s sword.\n"+
            HIC+"Electricity"+NORM+" crackles over "+attacker->query_name()+"\n"+
            ""+HIC+"\tSparks"+NORM+" fly from "+attacker->query_name()+" as "+TPN+"'s "+HIC+"Elven Sword"+NORM+" slices through flesh!\n");
         if(attacker->query_hp() > 13) 
            attacker->hit_player(13);
         return 4; }
      return 1; }
   
   if(call_other(this_player(), "query_attrib", "pie") > random (50))
      {
      write("Your sword sings with "+HIW+"Holy Light"+NORM+".\n");
      say(TPN+"'s sword sings with "+HIW+"Holy Light"+NORM+".\n");
      
      if(attacker->query_alignment() < 0 && TP->query_alignment() > 500){
         write("A bright "+HIW+"glow"+NORM+" surrounds your sword.\n"+
            "\n    Your righteous swing surrounds "+attacker->query_name()+" with hope.\n"+
            "\n\tA trail of "+HIW+"bright light"+NORM+" sweeps across "+attacker->query_name()+"'s chest.\n");
         say("A bright "+HIW+"glow"+NORM+" surrounds "+TPN+"'s sword.\n"+
            "\n    "+TPN+"'s righteous swing surrounds "+attacker->query_name()+" with hope.\n"+
            "\n\tA trail of "+HIW+"bright light"+NORM+" sweeps across "+attacker->query_name()+"'s chest.\n");
         if(attacker->query_hp() > 13) 
            attacker->hit_player(13);
         return 9; }
      return 1; }
}


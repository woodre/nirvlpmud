#include "/players/jaraxle/define.h"
inherit "players/jaraxle/weapon/weapon.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("elven spear");
   set_alias("spear");
   set_type("polearm"); 
   set_short(HIC+"Elven Spear"+NORM);
set_long("A long spear with a sterling silver blade at the\n"+
"top. The blade of the spear glows a "+HIC+"bright blue"+NORM+"\n"+
"reflecting off the bright rays of skylight. The\n"+
"long staff of the spear can allow the owner to\n"+
""+HIW+"wield"+NORM+" this "+HIW+"spear with both hands"+NORM+" for added power.\n");
   set_class(18);
   set_weight(2);
   set_value(6500);
   set_no_break(1);
   set_hit_func(this_object());
   set_two_handed_wep(1);
}
weapon_hit(attacker){
   if(attacker->query_alignment() > 0 && TP->query_alignment() < 0){
      write("The spear "+HIR+"burns red hot"+NORM+" in your hands!\n");
      TP->hit_player(1+random(11));
      return 1; }
   
   if(call_other(this_player(), "query_attrib", "wil") > random (50))
      {
      write("Your spear crackles with "+HIC+"blue electricity"+NORM+".\n");
      say(TPN+"'s spear crackles with "+HIC+"blue electricity"+NORM+".\n");
      
      if(attacker->query_alignment() < 0 && TP->query_alignment() > 0){
         
         write("A hazy "+HIB+"blue aura"+NORM+" surrounds your spear.\n"+
            HIC+"Electricity"+NORM+" crackles over "+attacker->query_name()+"\n"+
            ""+HIC+"\tSparks"+NORM+" fly from "+attacker->query_name()+" as your "+HIC+"Elven Spear"+NORM+" slices through flesh!\n");
         
         say("A hazy "+HIB+"blue aura"+NORM+" surrounds "+TPN+"'s spear.\n"+
            HIC+"Electricity"+NORM+" crackles over "+attacker->query_name()+"\n"+
            ""+HIC+"\tSparks"+NORM+" fly from "+attacker->query_name()+" as "+TPN+"'s "+HIC+"Elven Spear"+NORM+" slices through flesh!\n");
         if(attacker->query_hp() > 13) 
            attacker->hit_player(13);
         return 4; }
      return 1; }
   
   if(call_other(this_player(), "query_attrib", "pie") > random (50))
      {
      write("Your spear sings with "+HIW+"Holy Light"+NORM+".\n");
      say(TPN+"'s spear sings with "+HIW+"Holy Light"+NORM+".\n");
      
      if(attacker->query_alignment() < 0 && TP->query_alignment() > 500){
         write("A bright "+HIW+"glow"+NORM+" surrounds your spear.\n"+
            "\n    Your righteous swing surrounds "+attacker->query_name()+" with hope.\n"+
            "\n\tA trail of "+HIW+"bright light"+NORM+" sweeps across "+attacker->query_name()+"'s chest.\n");
         say("A bright "+HIW+"glow"+NORM+" surrounds "+TPN+"'s spear.\n"+
            "\n    "+TPN+"'s righteous swing surrounds "+attacker->query_name()+" with hope.\n"+
            "\n\tA trail of "+HIW+"bright light"+NORM+" sweeps across "+attacker->query_name()+"'s chest.\n");
         if(attacker->query_hp() > 13) 
            attacker->hit_player(13);
         return 9; }
      return 1; }
}


#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";

reset(arg){
   ::reset(arg);
   if (arg) return;
   
   set_name("bow");
   set_alias("bow");
   set_short("A bow");
   set_long(
      "A short curved bow made from flexible wood.\n"+
      "This bow is strong enough to handle normal arrows.\n");
   
   set_type("bow");  /*  sword/knife/club/axe/bow/polearm  */
      set_class(10);
   set_weight(1);
   set_value(150);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   int W;
   W = random(13);
   if(W>9)  {
      if(present("N_quiver", environment())){
         present("N_quiver", environment())->set_arrows(-1);
         say(TPN+" pulls an arrow from their quiver.\n\n");
         say(TPN+" fires an arrow into "+attacker->query_name()+"!\n");
         
         write("You pull an arrow from your quiver.\n\n");
         write("You fire an arrow from your bow!\n");
         write("It lands square in "+attacker->query_name()+"'s chest with a loud 'THUK!'\n");
         
    MOCO("/players/jaraxle/3rd/warrior/weaps/arrow.c"), attacker);
         
         return((environment()->query_attrib("str")+environment()->query_attrib("dex"))/10);
         
         return 2; }
      
   }
}


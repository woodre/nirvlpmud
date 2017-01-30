#include "/players/jaraxle/define.h"
inherit "players/jaraxle/weapon/weapon.c";
#define moose this_object()->query_attacker()
#define moosen capitalize(moose->query_name())
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("dagger of the sun");
   set_alias("sun");
   set_type("dagger"); 
   set_short("Dagger of the "+HIY+"Sun"+NORM);
   set_long("A long spear with a sterling silver blade at the\n"+
      "top. The blade of the spear glows a "+HIC+"bright blue"+NORM+"\n"+
      "reflecting off the bright rays of skylight. The\n"+
      "long staff of the spear can allow the owner to\n"+
      ""+HIW+"wield"+NORM+" this "+HIW+"spear with both hands"+NORM+" for added power.\n");
   set_class(16);
   set_weight(1);
   set_value(6500);
   set_no_break(1);
   set_hit_func(this_object());
   set_two_handed_wep(0);
}
weapon_hit(attacker){
   
   object n;
   object *inv;
   int lil_doggy, i;
   inv = all_inventory(environment());
   n = inv[i];
   lil_doggy = sizeof(inv);
   say(TPN+" dissapears in a blur of light! . . .\n");
   write("You dissapear in a blur of light! . . .\n");
   for(i = 0; i < lil_doggy; i++){
      /*
      if(living(inv[i]) && inv->query_npc()){
         */
       if(n == query_npc()){
            /*
            write("You sliced "+n+"!\n");
            */
            tell_object(inv[i], "\t"+BYEL+HIW+"You are sliced quickly with the Dagger of the "+HIY+"Sun"+NORM+"!\n");
            inv[i]->hit_player(random(20));
         }
       }
   }

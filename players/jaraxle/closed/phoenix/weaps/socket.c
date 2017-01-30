#include "/players/jaraxle/define.h"
inherit "players/jaraxle/weapon/weapon.c";
#define moose this_object()->query_attacker()
#define moosen capitalize(moose->query_name())
int SLOTS;
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("strike of night");
   set_alt_name("night");
   set_alias("strike");
   set_type("sword"); 
   set_short("Strike of "+BLK+BOLD+"Night"+NORM);
   set_long("This is a unique double bladed sword that has\n"+
      "been constructed of one piece of tempered 420\n"+
      "stainless steel with a black non-glare finish\n"+
      "and a black nylon cord grip wrapped around the\n"+
      "center. The sword is extremely light and has a\n"+
      "static feel to it.  Along the blade are two sockets.\n");
   
   set_class(18);
   set_weight(1);
   set_value(6500);
   add_special_fun("/players/jaraxle/closed/weapon/powers/reverse.c");
   add_special_fun("/players/jaraxle/closed/weapon/powers/speed.c");
   set_no_break(0);
   set_hit_func(this_object());
   set_two_handed_wep(1);
}
weapon_hit(attacker){
   if(this_object()->query_two_handed_wield() == 0){ return 0; }
   if((call_other(this_player(), "query_attrib", "dex") > random (40)) && (call_other(this_player(), "query_attrib", "ste") > random (40)) ){
      
      object n;
      object *inv;
      object room;
      int lil_doggy, i;
      room = environment(wielded_by);
      if(!room) return 0;
      inv = all_inventory(room);
      lil_doggy = sizeof(inv);
      say(TPN+" dissapears in a blur of light! . . .\n");
      write(BYEL+HIW+"You dissapear in a blur of light! . . .\n"+NORM);
      for(i = 0; i < lil_doggy; i++){
         n = inv[i];
         if(n->query_npc()){
            write("You slice "+n->query_name()+" with a quick slash.\n");
            tell_object(inv[i], "\t"+BYEL+HIW+"You are sliced quickly with the Dagger of the "+HIY+"Sun"+NORM+"!\n");
            inv[i]->hit_player(10+random(21));
          }
      }
   }
}

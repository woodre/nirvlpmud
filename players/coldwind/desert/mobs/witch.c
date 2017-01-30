#include "/players/coldwind/define.h"
inherit "obj/monster.c";
#define attacked this_object()->query_attack()
#define atn capitalize(attacked->query_name())


reset(arg)  {
   ::reset(arg);
   if(arg) return;
   move_object(clone_object("/players/coldwind/desert/weapons/ball.c"),this_object());
   init_command("wield weapon");
   move_object(clone_object("/players/coldwind/desert/armor/witch_hat.c"),this_object());
   init_command("wear hat");
   set_name("ashgan");
   set_alias("woman");
   set_alt_name("witch");
   set_short(HIK+"Ashgan, the Witch"+NORM);
   set_long(HIK+
      "  Dressed all in black, the ugly witch stands before you. Her \n"+
      "wicked smile and features reveal her evil nature. A dark gray aura\n"+
      "surrounds her and souls of her preys appear in a lighter gray \n"+
      "within the field of the aura. Ashgan holds a small crystal ball\n"+
      "in her right hand.\n"+NORM);
   set_dead_ob(this_object());
   set_level(23);
   set_hp(800);
   set_al(-1000);
   set_gender("female");
   set_wc(40);
   set_ac(21);
   set_ac_bonus(1);
   set_aggressive(0);
   set_wc_bonus(18);
   set_chat_chance(5);
   load_chat("Ashgan whispers a dark prayer.\n");
   load_chat("You take a step back.\n");
   load_chat("The witch cackles madly...\n");
}

heart_beat(){
   int blah;
   blah = random(100);
   :: heart_beat();
   if(!environment()) return;
   if(!attacked) return;
   if(!random(20) && attacker_ob && !attacker_ob->query_dead())
      {
      already_fight=0;
      attack();
   }
   
   if(attacker_ob && blah > 70) {
      woo(); }
}

woo(){
   tell_room(environment(),
      HIK+"Ashgan holds her crystal above her head and drains "+atn+"'s\n"+          
      "   "+HIW+"               \n"+
      "   "+HIW+"               \n"+
      ""+HIW+"                          L  I  F  E     \n"+
      "   "+HIW+"              \n"+NORM);
   attacked->hit_player(50+random(10), "magical");
}

query_attrib(str){ if(str == "int") return 20; }

monster_died() {
   object corpse;
   corpse = present("corpse", environment()); 
   move_object(clone_object("/players/coldwind/desert/items/soul_6.c"),
      environment(this_object()));
   if(corpse)
      
   return 1; }

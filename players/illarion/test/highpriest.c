#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("priest");
   set_alias("jeserius");
   set_alt_name("templar_priest");
   set_race("human");
   set_short("Jeserius, High Priest of the Templars");
   set_long(
      "  Looking at this man you see someone of medium height and build, his\n"+
      "face care-worn and slightly wrinkled.  He wears the robes of his office\n"+
      "with ease, their bleached white material reflecting the incoming light\n"+
      "of the domed ceiling overhead.  He wears the cross of the Templars\n"+
      "around his neck.\n");
   set_level(4);
   set_hp(80);
   set_al(1000);
   set_wc(8);
   set_ac(3);
   set_aggressive(0);
   set_heart_beat(1);
   set_chat_chance(5);
   load_chat("Jeserius says: Welcome my friend.\n");
   load_chat("The Templar Priest smiles.\n");
   load_chat("Jeserius comments: It is a fine day, a fine day indeed.\n");
   gold = clone_object("obj/money");
   gold->set_money(50);
   move_object(gold,this_object());
}

init(){
   ::init();
   add_action("bless_weapon", "bless");
}

bless_weapon(str){
   int cost;
   object wep;
   object ob;
   
   if(!present("KnightInvite", this_player())){
      return 0;
   }
   
   if (!str) return 0;
   ob=present(str,this_player());
   if(!ob) ob = present(str,this_object());
   if(!ob) {
      write("Jeserius looks about but does not see that here.\n");
      return 1;
   }
   
   if(!ob->weapon_class()){ write("You don't think that is a weapon.\n");
      return 1;
   }
   
   if(ob->query_wielded()){ 
      write("Jeserius asks that you unwield it first.\n");
      return 1;
   }
   
   if(ob->query_enchantment("templar_holy_water")){
      write("This item has already been dipped into the Holy Water.\n");
      return 1; }
   
   cost = 3000;
   if(this_player()->query_money() < cost) {
      write("Jeserius Shakes his head, \"You do not have enough money.\"\n");
      return 1;
   }
   
   this_player()->add_money(-cost);
   ob->add_enchantment("templar_holy_water",""+HIC+"<"+HIW+"BLESSED"+HIC+">"+NORM+"",""+HIW+"This weapon has already been dipped in Holy Water."+NORM+"",5,"other|water",3600,0,0,0);
   write(
      "Jeserius takes hold of the "+str+" and dips it into the basin of "+HIW+"Holy Water"+NORM+"...\n"+
      "The weapon glows brightly for a moment then settles with a faded aura.\n"+
      "Jeserius returns it into your hands.\n");
   return 1;
}


heart_beat(){
   int x;
   object ob;
   ::heart_beat();
   if(!query_attack() && random(100) < 25){
      ob = users();
      for (x = 0; x < sizeof(ob); x ++){
         if(present(ob[x], environment()) && living(ob[x]) && present("KnightInvite", ob[x]) &&
               ob[x]->query_hp() < ob[x]->query_mhp()){
            ob[x]->heal_self(random(5) + 1);
            tell_object(ob[x], "Jeserius reaches out with his holy symbol and touches you...\n"+
               "You feel a warmth travel into your body.\n");
           }
      }
   }
}


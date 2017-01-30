inherit "obj/monster";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
#include "/players/beck/Rangers/Npc/RangerNpc.h"
string my_name;
string random_color;
string the_color;
string COLR;
reset(arg)
{
   object gold, watch;
   switch(random(4)){
      case 0: my_name = "joshua";
      break;
      case 1: my_name = "joy";
      break;
      case 2: my_name = "robert";
      break;
      case 3: my_name = "peter";
      break;
   }
   
   switch(random(4)){
      case 0: random_color = BLUE;
      the_color = "periwinkle";
      COLR = ""+BLUE+"";
      break;
      case 1: random_color = RED;
      COLR = ""+RED+"";
      the_color = "bittersweet";
      break;
      case 2: random_color = GREEN;
      COLR = ""+BOLD+GREEN+"";
      the_color = "lime";
      break;
      case 3: random_color = YELLOW;
      COLR = ""+BOLD+YELLOW+"";
      the_color = "chocolate";
      break;
   }
   ::reset(arg);
   if(arg) return;
   set_name(capitalize(my_name));
   set_alt_name(my_name);
   set_long(capitalize(my_name)+" is one of the Mighty Morphin' Power Rangers.\n"+
      "He is dressed from head to toe in a "+COLR+the_color+OFF+" nylon suit.\n"+
      "His face is obscured by a "+COLR+the_color+OFF+" helmet.\n"+
      "\n");
   set_alias("ranger");
   set_race("human");
   set_level(20);
   set_hp(900 + random(50));
   set_wc(29 + random(5));
   set_ac(16 + random(4));
   set_al(1000);
   set_aggressive(0);
   set_chat_chance(3);
   set_dead_ob(this_object());
   gold=clone_object("obj/money");
   gold->set_money(random(1500) + 1000);
   move_object(gold, this_object());
   if(!present("watch", this_object())){
      watch=clone_object("/players/beck/Rangers/RangerCommunicator.c");
      watch->init_arg();
      move_object(watch, this_object());
      watch->init();
      watch->SRangerAnsi(random_color);
   }
   
}
custom_clean(){
   MASTER->RemoveRanger("Power Ranger",TO);
   return 0;
}
RangerNPC(){ return 1; }
query_guild_rank(){ return 70; }

short(){
   if(present("RangerCommunicator", this_object())->QMorphed()){
      return capitalize(my_name)+" the "+COLR+capitalize(the_color)+OFF+" Ranger";
   }
   return "A teenage boy named "+capitalize(my_name)+"";
}

monster_died(){
   object corpse;
   MASTER->RemoveRanger("Power Ranger",TO);
   command("release",this_object());
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/red_helmet.c"), corpse);
   move_object(clone_object("/players/beck/weapon/power_sword.c"), corpse);
   return 0;
}


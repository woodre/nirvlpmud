inherit "/players/beck/NewStuff/monster.c";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
reset(arg)
{
   object gold, watch;
   ::reset(arg);
   if(arg) return;
   set_name("Zack");
   set_alt_name("zack");
   set_alias("ranger");
   set_race("ranger_zack");
   set_long("Zack is one of the Mighty Morphin' Power Rangers.\n"+
      "\n");
   set_level(20);
   set_wc(29 + random(5));
   set_ac(25 + random(4));
set_res(-50);
   set_hp(500 + random(50));
   set_dead_ob(this_object());
   set_al(1000);
   set_aggressive(0);
   set_chat_chance(3);
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 1000);
   move_object(gold, this_object());
set_armor_params("magical",40,50,0);
}
custom_clean(){
   MASTER->RemoveRanger("Power Ranger",TO);
   return 0;
}
RangerNPC(){ return 1; }
query_guild_rank(){ return 70; }

short(){
   return "A teenage boy named Zack";
}
monster_died(){
   object corpse;
   MASTER->RemoveRanger("Power Ranger",TO);
   command("release",this_object());
   corpse = present("corpse", environment(this_object()));
   move_object(clone_object("/players/beck/armor/black_helmet.c"), corpse);
   move_object(clone_object("/players/beck/weapon/power_axe.c"), corpse);
   return 0;
}
init(){
   ::init();
add_action("poison","poison");
add_action("poison2","poison2");
add_action("poison3","poison3");
   if(present("RangerCommunicator",this_player())){
      present("RangerCommunicator",this_player())->TrainRanger("Zack","random");
   }
}

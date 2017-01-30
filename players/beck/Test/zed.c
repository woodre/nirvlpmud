inherit "/players/beck/updates/monster.c";
#include "/players/beck/Defs.h"

reset(arg)
{
   object gold, staff;
   ::reset(arg);
   if(arg) return;
   set_name("zed");
   set_alias("zed");
   set_short("Lord Zed");
   set_long("The Evil Lord Zed\n"+
      "He wield a huge staff with a giant Z at the top.\n");
   set_level(20);
   set_wc(0);
   set_hp(3000);
   set_ac(5);
   set_al(-3000);
   set_chance(40);
   set_spell_dam(25);
   set_spell_mess2("Lord Zed points his staff at you and toasts you with a giant fireball.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 4000);
   move_object(gold, this_object());
   if(!present("staff", this_object())){
      staff = clone_object("/players/beck/Test/zedstaff.c");
      move_object(staff, this_object());
   }
}

init(){
   string type;
   ::init();
   if(present("DarkRangerCommunicator",this_player())){
      if(TP->GLEVEL < 70){type = "dimensional";}
      if(TP->GLEVEL < 60){ type = "stellar";}
      if(TP->GLEVEL < 50){ type = "shadow";}
      if(TP->GLEVEL < 40){ type = "general";}
      if(TP->GLEVEL < 30){ type = "ninja";}
      if(TP->GLEVEL < 20){ type = "warrior";}
      if(TP->GLEVEL <10){ type = "servant";}
      present("DarkRangerCommunicator",this_player())->TrainRanger("Lord Zed",type);
   }
}

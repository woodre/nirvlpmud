inherit "obj/monster";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
reset(arg)
{
   object gold, weapon;
   ::reset(arg);
   if(arg) return;
   set_short("Zordon the living master computer");
   set_name("zordon");
   set_alias("zordon");
   set_long("Zordon is a giant computer that runs the control center.\n"+
      "He can keep track of the activities of Lord Zed and his evil monsters.\n"+
      "On the screen all you see is a giant face.\n"+
      "");
   set_level(20);
   set_hp(5000);
   set_wc(40);
   set_ac(20);
   set_al(2000);
   set_aggressive(0);
   set_chance(40);
   set_spell_dam(25);
   set_spell_mess2("Zordon short circuits your brain.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000) + 5000);
   move_object(gold, this_object());
}


init(){
   string type;
   ::init();
   if(present("RangerCommunicator",this_player())){
      if(TP->GLEVEL < 70){type = "space";}
      if(TP->GLEVEL < 60){ type = "rescue";}
      if(TP->GLEVEL < 50){ type = "turbo";}
      if(TP->GLEVEL < 40){ type = "zeo";}
      if(TP->GLEVEL < 30){ type = "ninja";}
      if(TP->GLEVEL < 20){ type = "thunder";}
      if(TP->GLEVEL <10){ type = "dino";}
      present("RangerCommunicator",this_player())->TrainRanger("Zordon",type);
   }
}

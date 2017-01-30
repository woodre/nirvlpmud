inherit "obj/monster";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
#include "/players/beck/MortalKombat/MKQuestNPC.h"

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Ueshiba");
   set_alias("morihei");
   set_race("human");
   set_gender("male");
   set_short("Morihei Ueshiba");
   set_long("Morihei Ueshiba is the Grandmaster of Aikido.\n"+
      "He is a very old man with a long grey beard.  Morihei is\n"+
      "very wise and has much he can teach you if you listen to him.\n"+
      "");
move_object(clone_object("/players/dragnar/MKScar/scar.c"), this_object());
   set_hp(10000);
   set_level(40);
   set_wc(100);
   set_ac(30);
enable_commands();
}

init(){
   ::init();
   if(TPRNAME == "beck"){
      write("Welcome Beck.\n");
   }
   if(COMM){
COMM->TrainRangerSkill("combat",5,"beck","Morihei",75);
   }
   if(present("DarkRangerCommunicator",TP)){
      present("DarkRangerCommunicator",TP)->TrainRanger("Morihei","random");
   }
}

#include "/players/jaraxle/define.h"
#include "secret.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("elder mummy");
   set_alias("mummy");
   set_alt_name("elder");
   set_race("undead");
   set_short("Elder Mummy");
   set_long("This is a very old, and tired mummy.  The bandages\n"+
      "wrapped around his body are grey, and soaked with \n"+
      "dry dirt and soil.  His face is scorched black, with\n"+
      "empty sockets where his eyes and nose should be. His\n"+
      "bandages wrap loosley over most of his body.  Dark \n"+
      "grey, wrinkled skin can be seen between the openings\n"+
      "of his bandages.\n");
   
   set_level(19);
   set_hp(550+random(50));
   set_al(-1000);
   set_ac(17);
   set_aggressive(0);
   set_wc(38);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("The Elder Mummy moans.\n");
   load_chat("Elder Mummy whispers: I know of a secret.\n");
   load_chat("The Elder Mummy moans.\n");
   load_chat("Elder Mummy groans: Let me tell you my secret, please!\n");
   load_chat("Elder Mummy groans: "+HIW+"Listen"+NORM+" to my "+HIW+"secret"+NORM+".\n");
   load_chat("Elder Mummy groans: "+HIW+"Listen"+NORM+" to my "+HIW+"secret"+NORM+".\n");
   set_a_chat_chance(15);
   load_a_chat("The Mummy engulfs you in a shadow of demons!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(2000+random(1000));
   move_object(gold,this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The mummy turns to ashes, the bandages slump to the ground in a pile.\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   MOCO("/players/jaraxle/3rd/pyramid/items/bandages.c"),environment());
 MOCO("/players/jaraxle/3rd/pyramid/items/ash.c"),environment());
return 0; }

init(){
    ::init();
  add_action("lstn","listen");
  add_action("ask","ask");
}

lstn(arg){
if(arg == "secret" || arg == "to secret" || arg == "to mummy secret" || arg == "to elder mummy secret"){
switch(random(2)){
case 0: secret1(this_player()); return 1; break;
case 1: secret2(this_player()); return 1; break;
}
notify_fail("Listen to what?\n"); return 0; }
}
ask(arg){
if(arg == "about sacrifice" || arg == "about the sacrifice"){
write("\nThe Elder Mummy speaks: In order to obtain the evil\n"+
      "that the demon one possesses you must first take these\n"+
      "items to his throne room and "+HIW+"sacrifice"+NORM+" the "+HIW+"items to"+NORM+" him\n"+
      "by using his "+HIW+"name"+NORM+".\n");
write("\nThe Elder Mummy continues:\n"+
      "\tThe items are as follows:  The "+HIY+"Summersword"+NORM+" and the "+HIY+"Glowing Sword"+NORM+".\n"+
      "\tLay these items on the floor of the throne room and sacrifice\n"+
      "\tthem to the evil one.\n");
return 1; }
notify_fail("Ask about what?\n"); return 0; }


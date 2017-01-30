inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(300);
   move_object(gold, TOB);
   set_name("billy");
   set_alias("boy");
   set_short("Little Billy");
   set_long("Puf's friend Billy he seems to be looking for puf\n" +
            "who obviously is not in.\n");
   set_level(7);
   set_wc(11);
   set_ac(6);
   set_hp(105);
   set_al(450);
   set_aggressive(0);
   set_gender(1);
   set_race("human");
   set_chat_chance(30);
   load_chat("Billy asks: Have you seen Puf anywhere?\n");
   load_chat("Billy sighs: Puf where are you.\n");
   load_chat("Billy looks around in vain.\n");
   load_chat("Billy searches the chest for a game\n");
 }
}      
   

inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
object gold;
 ::reset(arg);
  if(!arg){
   gold = clone_object("obj/money");
   gold->set_money(600+random(400));
   move_object(gold, TOB);
   set_name("owner");
   set_alias("man");
   set_short("A Slave Owner");
   set_long("A wealthy looking slave owner who seems to be in the market\n" +
            "for more slaves.\n\n");
   set_level(15);
   set_wc(20);
   set_ac(12);
   set_hp(225);
   set_al(0);
   set_aggressive(0);
   set_gender(1);
   set_race("human");
   set_chat_chance(20);
   load_chat("Owner inspects the slave.\n");
   load_chat("Owner pokes you in the ribs\n");
   load_chat("Owner nods his head in bidding\n");
 }
}

inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, gold;

ob = clone_object("/players/saber/stuff/power.c");
move_object(ob,this_object());
gold = clone_object("obj/money");
/* rnd(1000) + 2500 averages 3000.. + the valu of the power.c is far over the max - mythos <9-10-96>
gold->set_money(random(1000) + 2500);
*/
gold->set_money(random(1000) + 500);
move_object(gold,this_object());

     set_name("boomer");
     set_short("An advanced combat Boomer");
     set_race( "robot");
     set_alias("boomer");
     set_gender("creature");
     set_long("An evil looking bio-mechanical cyborg terminator,\n"+
       "the boomer is layered with synthetic muscles and\n"+
       "plated dermal armor.  It has targeting needles\n"+
       "sticking out of it's eyes, and a laser cannon\n"+
       "extending from it's mouth.\n");
     set_level(19);
     set_ac(16);
     set_wc(28);
     set_hp(475);
     set_al(-1000);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("The boomer glares at you.\n");
     load_chat("The boomer guns down a passing civilian.\n");
     load_a_chat("The boomer flies into the air as it continues to attack.\n");
     load_a_chat("The boomer charges you.\n");
     load_a_chat("The boomer slams you with a huge metal fist.\n");
     set_spell_mess1("The boomer's chest opens up into a tri part solar blaster.\n"+
       "The boomer fries it's opponent with a searing solar blast.");
     set_spell_mess2("The boomers chest opens up into a tri part solar blaster.\n"+
       "The boomer fries you with a searing solar blast.\n");
 set_chance(10);
 set_spell_dam(20);
   }

}

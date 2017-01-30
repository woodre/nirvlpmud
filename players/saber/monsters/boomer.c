inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, gold;

gold = clone_object("obj/money");
/* power.c value is 1000 which is max treasure... - mythos <9-10-96> .
gold->set_money(random(1000) + 1500);
move_object(gold,this_object());
*/
ob = clone_object("/players/saber/stuff/power.c");
move_object(ob,this_object());

     set_name("boomer");
     set_short("A combat Boomer");
     set_race( "robot");
     set_alias("boomer");
     set_gender("creature");
     set_long("An evil looking bio-mechanical cyborg terminator,\n"+
       "the boomer is layered with synthetic muscles and\n"+
       "plated dermal armor.  It has targeting needles\n"+
       "sticking out of it's eyes, and a laser cannon\n"+
       "extending from it's mouth.\n");
     set_level(18);
     set_ac(15);
     set_wc(26);
     set_hp(450);
     set_al(-1000);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("The boomer glares at you.\n");
     load_chat("The boomer guns down a passing civilian.\n");
     load_a_chat("The boomer flies into the air as it continues to attack.\n");
     load_a_chat("The boomer charges you.\n");
     load_a_chat("The boomer slams you with a huge metal fist.\n");
     add_spell("solar blast",
"The boomers chest opens up into a tri part solar blaster.\n"+
"The boomer fries you with a searing $HY$solar blast$N$.\n",
"The boomers chest opens up into a tri part solar blaster.\n"+
"The boomer fries #TN# with a searing $HY$solar blast$N$.\n",
10,20,"other|light");
     /* converted spell to add_spell format - illarion dec 2004
     set_spell_mess1("The boomer's chest opens up into a tri part solar blaster.\n"+
       "The boomer fries it's opponent with a searing solar blast.");
     set_spell_mess2("The boomers chest opens up into a tri part solar blaster.\n"+
       "The boomer fries you with a searing solar blast.\n");
 set_chance(10);
 set_spell_dam(20);
 */
   }

}

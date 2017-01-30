inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, ob2, gold;

ob = clone_object("/players/saber/armor/mshades.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/hrev.c");
move_object(ob2,this_object());
gold = clone_object("obj/money");
gold->set_money(random(200) + 550);
move_object(gold,this_object());

     set_name("leon");
     set_short("Leon McNichol <A.D. Police>");
     set_race( "human");
     set_alt_name("a d police");
     set_alias("police");
     set_gender("male");
     set_long("A tall, suave cop with slicked back black hair and\n"+
       "mirrorshades.  He is carrying the biggest revolver\n"+
       "you have ever seen.\n");
     set_level(19);
     set_ac(16);
     set_wc(28);
     set_hp(475);
     /* Going by the theme of the area this monster should be good-aligned  
     - illarion 2 dec 2004 */
     set_al(200);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("Leon says 'I'm Leon.  Assigned to the AD Police to protect\n"+
       "citizens from boomers.'\n");
     load_chat("Leon hums a tune by Priss and the Replicants.\n");
     load_a_chat("Leon says 'You're under arrest!'\n");
     load_a_chat("Leon says 'Just try it.\n");
     load_a_chat("Leon says 'I can't loose yet.  If I don't finish this off fast, this\n"+
       "city is going to turn into ash!'\n");
     set_spell_mess1("Leon levels his Colt .68 Heavy Revolver at his foe.\n"+
       "Leon bracers himself.\n"+
       "Leon fires.\n"+
       "               * * * * B O O M * * * *");
     set_spell_mess2("Leon levels his Colt .68 Heavy Revolver at you.\n"+
       "Leon bracers himself.\n"+
       "Leon fires.\n"+
       "             * * * *  B O O M  * * * *");
 set_chance(10);
 set_spell_dam(20);
   }

}

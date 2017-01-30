inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, ob2, ob3, gold;

ob2 = clone_object("/players/saber/weapons/lgun.c");
move_object(ob2,this_object());
ob = clone_object("/players/saber/stuff/brief.c");
move_object(ob,this_object());
ob3 = clone_object("/players/saber/armor/dshades.c");
move_object(ob3, this_object());
gold = clone_object("obj/money");
gold->set_money(random(100) + 250);
move_object(gold,this_object());
init_command("wield gun");

     set_name("mason");
     set_short("A man named Mason");
     set_race( "human");
     set_gender("male");
     set_alt_name("man");
     set_long("An evil looking man with slicked back blue hair\n"+
       "wearing a business suit.  He looks like he knows\n"+
       "exactly what is goin on around here.\n");
     set_level(10);
     set_ac(8);
     set_wc(39);
     set_hp(150);
     set_al(-1000);
     set_aggressive(0);
     set_whimpy(1);
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("Mason asks: 'The Knight Sabers?'\n");
     load_chat("Mason says, 'Genom will benefit greatly from your death!'\n");
     load_chat("Mason yells: 'Boomers, attack this scum!'\n");
     load_a_chat("Mason yells: 'Where are my Boomers?'\n");
     load_a_chat("Mason yells: 'DIE!'\n");
     add_spell("lazer gun",
"#MN# blasts you with #MP# automatic lazer gun.\n",
"#MN# blasts #TN# with #MP# automatic lazer gun.\n",
15,10,"other|laser");
     /* converted spell to add_spell format - illarion 2 dec 2004
     set_spell_mess2("Mason blasts you with his gun.");
     set_spell_mess1("Mason blast his foe with an automatic lazer gun.");
 set_chance(15);
 set_spell_dam(10);
 */
   }

}

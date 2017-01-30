inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, gold;

ob = clone_object("/players/saber/armor/hardsuit1.c");
move_object(ob,this_object());
gold = clone_object("obj/money");
gold->set_money(random(1000) + 3500);
move_object(gold,this_object());

     set_name("celia");
     set_short("Celia Stingray <Knight Saber>");
     set_race( "human");
     set_alt_name("knight saber");
     set_alias("knight");
     set_gender("female");
     set_long("A willowy and graceful lady with blue tinted hair\n"+
       "and a cold smile.  Celia is wearing a light blue\n"+
       "combat hardsuit.\n");
     set_level(20);
     set_ac(19);
     set_wc(27);
     set_hp(500);
     /* By all indications, this character should be good-aligned
      - illarion 2 dec 2004 */
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("Celia says 'We are the Knight Sabers.'\n");
     load_chat("Celia says 'We fight to bring peace and justice to the world and rid it of evil.\n");
     load_a_chat("Celia says 'The boomers are acting differently this time.'\n");
     load_a_chat("Celia dodges nimbly away from you.\nDamn she's fast!\n");
     load_a_chat("Celia ducks under your attack.\n");
     load_a_chat("Celia speaks into her helmet radio.\n");
     add_spell("lazer blade",
"Celia swings a blade of dazzling white lazerlight.\n"+
"You feel a numbing sensation as the blade hits you.\n",
"Celia slices into #TN# with a blade of white lazerlight.\n",
15,14,"other|laser");
     /* converted spell to add_spell - illarion dec 2004
     set_spell_mess1("Celia slices through her opponent with a blade of white laser light.");
     set_spell_mess2("Celia swings a blade of dazzling white lazerlight.\n"+
          "You feel a numbing sensation as the blade hits you.");
 set_chance(15);
 set_spell_dam(14);
 */
   }

}

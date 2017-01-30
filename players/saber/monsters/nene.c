inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, gold;

ob = clone_object("/players/saber/armor/hardsuit1.c");
ob->set_short("A purple Hardsuit <with pink legs!>");
move_object(ob,this_object());

     set_name("nene");
     set_short("Nene Romanova <Knight Saber>");
     set_race( "human");
     set_alt_name("knight saber");
     set_alias("knight");
     set_gender("female");
     set_long("A short redhead who looks like she belongs in front\n"+
       "of a computer terminal.  Nene's hardsuit is purple\n"+
       "with pink legs.\n");
     set_level(18);
     set_ac(16);
     set_wc(24);
     set_hp(450);
     /* By all indications, this character should be good-aligned
      - illarion 2 dec 2004 */
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("Nene looks around.\n");
     load_chat("Nene speaks into her helmet radio:\n"+
       "'That's 8 cases already; every time it's the same.  It's the vampire.'\n"+
       "\nYou hear Leon reply over the radio:\n"+
       "'You never get bored of this town.'\n");
     load_a_chat("Nene says 'The boomers are acting differently this time.'\n");
     load_a_chat("Nene screams 'Help!  Help!'\n");
     load_a_chat("Nene ducks under your attack.\n");
     load_a_chat("Nene speaks into her helmet radio.\n");
     add_spell("automatic laser",
"#MN# fires a fully automatic laser burst at you.\n"+
       "  * zap *     * zap*\n",
"#MN# fires a fully automatic laser burst at #TN#.\n"+
       "  * zap *     * zap*\n",
10,10,"other|laser");
     add_spell("laser blade",
"#MN# swings a blade of dazzling white lazerlight.\n"+
"You feel a numbing sensation as the blade hits you.\n",
"#MN# swings a blade of dazzling white lazerlight at #TN#.\n",
5,10,"other|laser");
       
/* converted spells to add_spell format
     set_spell_mess1("Nene fires a burst from her fully automatic laser.\n"+
       "  * zap *     * zap*");
     set_spell_mess2("Nene fires a burst from her fully automatic laser.\n"+
       "  * zap *    * zap *");
     set_spell_mess2("Nene swings a blade of dazzling white lazerlight.\n"+
          "You feel a numbing sensation as the blade hits you.");
 set_chance(15);
 set_spell_dam(10);
*/
   }

}

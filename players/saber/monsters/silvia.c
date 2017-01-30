inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob = clone_object("/players/saber/armor/cbikini.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/2longswords.c");
move_object(ob2, this_object());
     set_name("silvia");
     set_short("Silvia the Gladiator");
     set_race( "human");
     set_alias("gladiator");
     set_gender("female");
     set_long(
     "A slender woman with beautiful blond hair and blazing blue eyes.\n"+
     "She appears to be wearing a skimpy chainmail bikini.\n"+
     "Silvia is wielding a pair of magical longswords.\n");
     set_level(17);
     set_ac(14);
     set_wc(24);
     set_hp(425);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Silvia bounces around.\n");
     load_chat("Silvia smiles a smile to melt your heart.\n");
     load_chat("Silvia looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Silvia punches you across the face!\n");
     load_a_chat("Silvia kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Silvic slices her foe across the face.\n");
     set_spell_mess2("Silvia slices you across the face.\n");
 set_chance(10);
 set_spell_dam(10);
   }

}

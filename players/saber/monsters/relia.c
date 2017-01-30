inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob = clone_object("/players/saber/armor/stdleather.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/mspear.c");
move_object(ob2, this_object());
     set_name("relia");
     set_short("Relia the Amazon");
     set_race( "human");
     set_alias("amazon");
     set_gender("female");
     set_long(
     "A lean, muscular woman with flashing eyes and an evil smile.\n"+
     "She is wielding a spear in an unusual strange two handed style.\n"+
     "Relia appears to be missing her left breast.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(250);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Relia smiles evilly.\n");
     load_chat("Relia looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Relia punches you across the face!\n");
     load_a_chat("Relia kicks you in the groin.\n");
     load_a_chat("Relia says: You will die by my hands...\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Relia impales her foe with her magic spear.");
     set_spell_mess2("Relia impales you upon her magic spear.\n");
 set_chance(10);
 set_spell_dam(10);
   }

}

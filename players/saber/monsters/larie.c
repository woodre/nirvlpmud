inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob4 = clone_object("/players/saber/gems/bloodstone.c");
move_object(ob4,this_object());
ob3 = clone_object("/players/saber/weapons/whip.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/skinleather.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/longsword.c");
move_object(ob2, this_object());
     set_name("larie");
     set_short("Larie the Gladiator");
     set_race( "human");
     set_alias("gladiator");
     set_gender("female");
     set_long(
     "A lean yet well muscled woman with silky black hair and killer eyes.\n"+
     "She is wearing a rather skimpy suit of studded leather armor.\n"+
     "Larie wields a longsword in one hand and a whip in the other.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Larie glances up at you with the eyes of a killer.\n");
     load_chat("Larie smiles evilly.\n");
     load_chat("Larie looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Larie punches you across the face!\n");
     load_a_chat("Larie kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Larie ducks under your attack.\n");
     set_spell_mess1("Larie slices her opponent across the chest.");
     set_spell_mess2("Larie slices you across the chest with her longsword.");
 set_chance(10);
 set_spell_dam(10);
   }

}

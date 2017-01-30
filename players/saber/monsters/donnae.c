inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob3 = clone_object("/players/saber/weapons/net.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/halfchain2.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/longsword.c");
move_object(ob2, this_object());
     set_name("donnae");
     set_short("Donnae the Gladiator");
     set_race( "human");
     set_alias("gladiator");
     set_gender("female");
     set_long(
     "A lean woman with flaming red hair and bright green eyes.  She moves with\n"+
     "an almost feline grace, and is almost wearing a suit of half chain.\n"+
     "Donnae is wielding a longsword and carrying a combat net.\n");
     set_level(16);
     set_ac(14);
     set_wc(21);
     set_hp(390);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Donnae smiles evilly.\n");
     load_chat("Donnae looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Donnae punches you across the face!\n");
     load_a_chat("Donnae kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Donnae ducks under your attack.\n");
     set_spell_mess1("Donnae smashes her foe in the face with the pommel of her sword.");
     set_spell_mess2("Donnae smashes you in the face with the pommel of her sword.");
 set_chance(10);
 set_spell_dam(10);
   }

}

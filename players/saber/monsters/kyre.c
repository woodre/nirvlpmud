inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob4 = clone_object("/players/saber/gems/moonstone.c");
move_object(ob4,this_object());
ob3 = clone_object("/players/saber/gems/moonstone.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/halfchain2.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/trident.c");
move_object(ob2, this_object());
     set_name("kyre");
     set_short("Kyre the Gladiator");
     set_race( "human");
     set_alias("gladiator");
     set_gender("female");
     set_long(
     "A well proportioned woman with a fierce scowl wearing half chain.\n"+
     "She is wielding a wicked looking trident.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Kyre flexes.\n");
     load_chat("Kyre smiles evilly.\n");
     load_chat("Kyre looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Kyre punches you across the face!\n");
     load_a_chat("Kyre kicks you in the groin.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Kyre impales her foe upon a wicked looking trident.");
     set_spell_mess2("Kyre impales you with her wicked looking trident.");
 set_chance(10);
 set_spell_dam(10);
   }

}

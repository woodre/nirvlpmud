inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4;
ob3 = clone_object("/players/saber/gems/moonstone.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/stdleather.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/bastard.c");
move_object(ob2, this_object());
     set_name("sickle");
     set_short("Sickle the Beast Master");
     set_race( "human");
     set_alias("beast master");
     set_alt_name("master");
     set_gender("male");
     set_long(
     "Sickle is a tall man with long dark hair and dark eyes.\n"+
     "He is wearing leather armor and wields a massive bastard sword.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-650);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Sickle flexes.\n");
     load_chat("Sickle smiles evilly.\n");
     load_chat("Sickle whistles for his kitty. (fang?)\n");
     load_chat("Sickle looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Sickle punches you across the face!\n");
     load_a_chat("Sickle kicks you in the groin.\n");
     load_a_chat("Sickle wipes the blood off of his blade.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Sickle slashes his foe with a massive bastard sword.");
     set_spell_mess2("Sickle slashes you with a massive bastard sword.");
 set_chance(10);
 set_spell_dam(10);
   }

}

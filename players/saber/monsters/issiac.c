inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob,ob2,ob3;
ob3 = clone_object("/players/saber/weapons/wartrident.c");
move_object(ob3,this_object());
ob2 = clone_object("/players/saber/armor/halfchain.c");
move_object(ob2,this_object());
ob = clone_object("/players/saber/weapons/net.c");
move_object(ob,this_object());
     set_name("issiac");
     set_gender("male");
     set_short("Issiac the gladiator");
     set_race( "human");
     set_long("A large man with flowing golden hair and the eyes of a hero.\n"+
       "His face is like that of a man operating within a dream.\n");
     set_level(19);
     set_ac(15);
     set_wc(28);
/* Changed from 485 to 850, due to the trident power -Snow 3/00 */
     set_hp(850);
     set_al(-850);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(20);
     load_chat("Issiac looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
     load_chat("Issiac smiles.\n");
     load_chat("Issiac grins evilly.\n");
    load_a_chat("Issiac punches you across the face!\n");
     load_a_chat("Issiac offers to let you surrender.\n");
     load_a_chat("Issiac blocks your weapon, using his net as a shield.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Issiac grabs his foe and squeezes them between his massive arm muscles.\n");
      set_spell_mess2("Issiac grabs you and squeezes you in the bear hug fromhell.\n"+
 "You choke and sputter blood.");
 set_chance(10);
 set_spell_dam(10);
   }
}

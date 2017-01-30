/* 10/10/05 Earwax: Changed 'White wolf' to 'Whitewolf' */

inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob,ob2,ob3;
ob3 = clone_object("/players/saber/gems/garnet.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/whitecloak.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/2battleaxe.c");
move_object(ob2, this_object());
     set_name("white wolf");
     set_short("Whitewolf the Barbarian");
     set_race( "human");
     set_alias("wolf");
     set_alt_name("barbarian");
     set_gender("male");
     set_long(
     "A huge barbarian of a man wielding a two handed battle axe.\n"+
     "White Wolf stands just over six and one half foot lengths tall.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(10);
   set_a_chat_chance(15);
     load_chat("Whitewolf flexes.\n");
     load_chat("Whitewolf bellows loudly.\n");
     load_chat("Whitewolf looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Whitewolf punches you across the face!\n");
     load_a_chat("Whitewolf wipes the blood of of his axe.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Whitewolf slams his battle axe deeply into his foe.");
     set_spell_mess2("Whitewolf slams his massive battle axe into you.\n");
 set_chance(10);
 set_spell_dam(10);
   }

}
init() {
  ::init();
}



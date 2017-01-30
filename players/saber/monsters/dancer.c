inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, ob2, ob3, gold;

ob2 = clone_object("/players/saber/armor/halter.c");
move_object(ob2,this_object());
ob = clone_object("/players/saber/armor/mini.c");
move_object(ob,this_object());
gold = clone_object("obj/money");
gold->set_money(random(100) + 725);
move_object(gold,this_object());

     set_name("dancer");
     set_short("A dancing girl");
     set_race( "human");
     set_gender("female");
     set_alt_name("girl");
     set_long("A sleek looking female wearing a skin tight halter top and what might\n"+
       "pass for a mini-skirt.  She moves as one with the bass, swayiing in an\n"+
       "alluring rhythm.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-800);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("A girl winks at you.\n");
     load_chat("A girl dances up against your body.\n");
     load_chat("A girl flails wildly to the music.\n");
     load_chat("A girl sways to the rhythm with alluring motions.\n");
     load_chat("A girl boogs and froogs.\n");
     load_chat("Priss sings 'Konya wa Hurricane' loudly.\n");
     load_a_chat("Priss sings 'Big City Kodoku na Heart to Heart'.\n");
     load_a_chat("A girl scream!\n");
     load_a_chat("The girl tries to slam you.\n");
     load_a_chat("A girl rakes her nails across your face.\n");
   }

}

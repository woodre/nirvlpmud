inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, ob2, ob3, gold;

ob2 = clone_object("/players/saber/armor/lpants.c");
move_object(ob2,this_object());
ob = clone_object("/players/saber/armor/lboots.c");
move_object(ob,this_object());
gold = clone_object("obj/money");
gold->set_money(random(100) + 725);
move_object(gold,this_object());

     set_name("dancer");
     set_short("A dancing guy");
     set_race( "human");
     set_gender("male");
     set_alt_name("guy");
     set_long("A slender yet well muscled man with sweat glistening off his bare\n"+
       "chest.  He wears black leather pants, and appears to be lost in the\n"+
       "rythum of the music.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-800);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("A guy looks across the room.\n");
     load_chat("A guy dances up to you.\n");
     load_chat("A guy spirals to the music.\n");
     load_chat("A guy trances to the music.\n");
     load_chat("Priss sings 'Kodoku No Angel'.\n");
     load_chat("Priss sings 'Nemuranai omoi o yusabura dake'.\n");
     load_a_chat("Priss sings 'Mad Machine'.\n");
     load_a_chat("Priss sings 'Big City Namida wa Day by Day.'\n");
     load_a_chat("A guy screams in pain!\n");
     load_a_chat("The guy slams against you.\n");
     load_a_chat("A guy punches you in the face.\n");
   }

}

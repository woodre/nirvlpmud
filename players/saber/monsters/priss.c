inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){

object ob, ob2, ob3, gold;

ob2 = clone_object("/players/saber/armor/slboots.c");
move_object(ob2,this_object());
ob3 = clone_object("/players/saber/armor/halter.c");
move_object(ob3,this_object());
ob = clone_object("/players/saber/stuff/mic.c");
move_object(ob,this_object());
gold = clone_object("obj/money");
gold->set_money(random(100) + 750);
move_object(gold,this_object());

     set_name("priss");
     set_short("A rock star named Priss");
     set_race( "human");
     set_gender("female");
     set_alt_name("star");
     set_long("A stunningly beautiful caucasian woman with long,\n"+
       "teased blond hair and a look of determination.  She\n"+
       "wears a short, skin tight leather mini-skirt and\n"+
       "black leather halter top, as well as black fish-net\n"+
       "stockings and high heels.\n"+
       "Priss is singing to something with a hard beat and lots of bass.\n");
     set_level(18);
     set_ac(15);
     set_wc(26);
     set_hp(450);
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(15);
     load_chat("Priss sings 'Konya wa Hurricane' loudly.\n");
     load_chat("Priss sings 'Big City Kodoku na Heart to Heart\n");
     load_chat("Priss sings 'Minna ai no mayoigo'\n");
     load_chat("Priss sings 'Big City Namida wa Day By Day'\n");
     load_chat("Priss sings 'Nemuranai omoi o yusabura dake'\n");
     load_chat("Priss sings 'Kodoku No Angel' while looking directly at you.\n");
     load_chat("Priss rocks the song 'Mad Machine' to the audience.\n");
     load_a_chat("Priss says 'Instead of chasing girls, why don't you chase boomers?'\n");
     load_a_chat("Priss dodges nimbly away from you.\nDamn she's fast!\n");
    load_a_chat("Priss slaps you across the face.\n");
    load_a_chat("Priss ducks under your attack.\n");
    load_a_chat("Priss punches you across the face!\n");
    set_spell_mess2("Priss produces a knife from somewhere and slashes\n"+
          "you across the face.");
     set_spell_mess1("Priss slashes her foe with a sharp knife.");
 set_chance(15);
 set_spell_dam(10);
   }

}

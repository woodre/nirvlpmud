/* Ryan Stiles */

inherit "/obj/monster.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(51) + 700);
  move_object(gold,this_object());

     set_name("ryan");
     set_alias("stiles");
     set_short("Ryan Stiles");
     set_race("human");
          set_alt_name("entertainer");
     set_long("Ryan Stiles makes a silly face at the audience, his large\n"+
              "eyes filled with laughter.  He is unusually tall and thin,\n"+
	      "yet not clumsy.  He stands ready to match his quick wit\n"+
	      "against the other 'contestants' of 'Whose Line Is It Anyway'.\n");
     set_level(14);
     set_ac(10 + random(2));
     set_wc(17 + random(2));
     set_hp(200 + random(21));
     set_al(-1);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(25);
   load_chat("Ryan quips, 'If I were a man with gills, I would be a fish!'\n");
     load_chat("Ryan cautions, 'Never trust sheep.'\n");
     load_chat("Ryan gripes, 'I look like Walt Disney just threw up.'\n");
     load_chat("Ryan threatens, 'Back off, or the lizard gets it!'\n");
     load_chat("Ryan admits, 'You know, I've got a confession to make.\n"+
	"I'm not really a priest, I've just got my shirt on backwards.'\n");
     
     load_a_chat("Ryan stalks across the stage, his face twisted in anger!\n");
     load_a_chat("Ryan drops into a bad parody of a martial arts stance!\n");
     load_a_chat("Ryan kicks out at you with his size 14 shoes!\n");
     load_a_chat("Ryan hides behind Colin!\n");
   }
}


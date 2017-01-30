inherit "/obj/monster";

reset(arg){
object gold;
  ::reset(arg);

move_object(clone_object("/players/daranath/qualtor/obj/keyone.c"),this_object());

  if (!arg){
          
     set_name("ghost");
     set_short("Ghostly form of a Qual'tor Guardsman");
     set_alias("guard");
     set_alt_name("ghost guard");
     set_race("undead");
     set_gender("male");
     set_long("Another of Qual'tors Guardsmen killed in the severe fighting\n"+
              "during the cities fall, this guard's duty was to keep the\n"+
              "prisoners of the king secure.\n");

     set_level(18);
     set_ac(16);
     set_wc(35);
     set_hp(500);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("A chilling breeze fills the small chamber.\n");
     load_a_chat("The ghost of the dwarf seems pleased you are releasing him from his torment.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(2000)+3500);
     move_object(gold,this_object());
     }
    }

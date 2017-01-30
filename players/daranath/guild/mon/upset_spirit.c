inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Upset Spirit");
     set_short("A spirit that seems rather upset");
     set_alias("spirit");
     set_alt_name("upset spirit");
     set_race("undead");
     set_gender("creature");
     set_long("A rather badly decomposed corpse that was brought back from\n"+
              "its eternal rest, the undead spirit of the corpse has come\n"+
              "back from the grave to extra its revenge.\n");
     set_level(16);
     set_ac(15);
     set_wc(29+random(8));
     set_hp(390+random(100));
     set_al(-1000);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(10);
/*
     set_no_experience(1);
*/
     load_chat("A chilling breeze fills the small chamber.\n");
     load_a_chat("The spirit howls in anger and fury...\n");

     }
    }

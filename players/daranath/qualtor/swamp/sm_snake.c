inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("small snake");
     set_short("A small striped snake moves about the swamp");
     set_alias("snake");
     set_alt_name("critter");
     set_race("reptile");
     set_gender("creature");
     set_long("A small striped snake moves quietly about the swamp. The\n"+
              "snake itself doesn't look very dangerous.\n");
     set_level(2);
     set_ac(3);
     set_wc(8);
     set_hp(50);
     set_al(-250);
     set_aggressive(0);

     }
    }

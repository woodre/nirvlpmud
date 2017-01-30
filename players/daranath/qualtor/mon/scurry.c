inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Scurry rat");
     set_short("A large rat scurries about the area");
     set_alias("scurry");
     set_alt_name("rat");
     set_race("rodent");
     set_gender("creature");
     set_long("An oversized black rat crawls about the area looking for a piece of\n"+
              "food or something else to eat. These rats usually run at the first\n"+
              "sign of danger, thus giving them their nickname of 'scurry rats.\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(75);
     set_al(-750);
     set_aggressive(0);

     }
    }

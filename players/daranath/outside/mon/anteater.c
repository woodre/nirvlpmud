/* Monster used in tallgrass.c to prevent players from making ants all day */

inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Angry anteater");
     set_short("An angry anteater growls at you");
     set_alias("anteater");
     set_alt_name("eater");
     set_race("marsupial");
     set_gender("creature");
     set_long("A large furry creature with a long snout and toungue, the anteater\n"+
              "is furious at you for killing its food. Large claws will settle the\n"+
              "issue for the anteater.\n");
     set_level(16);
     set_ac(12);
     set_wc(20+random(10));
     set_hp(250+random(100));
     set_al(-500);
     set_aggressive(1);

     }
    }

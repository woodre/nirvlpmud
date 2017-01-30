inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/toadstool.c"),this_object());

     set_name("Ra'gor ant");
     set_short("A large ant has crawled from the mound");
     set_alias("ant");
     set_race("insect");
     set_gender("creature");
     set_long("A large black ant has crawled from the mound in response to your\n"+
              "pounding on it. The ant itself has a pair of razor sharp mandibles\n"+
              "and it aggressivly stands before you.\n");
     set_level(5);
     set_ac(4);
     set_wc(9);
     set_hp(70+random(25));
     set_al(-950);
     set_aggressive(0);

     }
    }

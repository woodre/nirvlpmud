inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Crystal shard");
     set_short("A Shard of pure crystal");
     set_alias("shard");
     set_alt_name("crystal");
     set_race("elemental");
     set_gender("creature");
     set_long("A living shard of a clear crystal.\n");
     set_level(7);
     set_ac(9);
     set_wc(15);
     set_hp(125);
     set_al(-1000);
     set_aggressive(1);

     }
    }

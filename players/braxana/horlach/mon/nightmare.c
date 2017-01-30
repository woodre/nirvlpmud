inherit "players/mythos/closed/guild/spells/monster2";
reset(arg) {
::reset(arg);
  if(arg) return;
    set_name("nightmare");
    set_race("demon");
    set_alias("demonling");
    set_short("Demonling");
    set_long("A thing of hideous features. \n"+
             "A being that exists to torment others.\n");
    set_al(-random(1000));
    set_hp(500+random(1000));
    set_level(10+random(30));
    set_wc(10+random(40));
    set_ac(10+random(10));
    set_aggressive(1);
    set_spec_aggres();
    set_a_chat_chance(10);
       load_a_chat("The Demonling screams!\n");
       load_a_chat("The Demonling lashes out with its claws!\n");
    if(random(3)==0) {
     set_mult(2);
     set_mult_chance(20);
     set_mult_dam1(5);
     set_mult_dam2(10); }
}

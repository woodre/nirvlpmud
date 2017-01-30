inherit "obj/monster";

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("goblin");
          set_race("goblin");
          set_level(5);
          set_hp(75);
          set_al(-100);
          set_short("a goblin");
          set_long("This orange-skinned humanoid may be small, but it is\n"+
                   "still rather dangerous.\n");
          set_aggressive(0);
          set_wc(9);
          set_ac(5); 
          money=clone_object("obj/money");
          money->set_money(200);
          move_object(money, this_object()); }
}
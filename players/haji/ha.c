
inherit "obj/monster";
int old_money, money;

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("haji");
          set_level(9);
          set_hp(175);
          set_al(-200);
            set_alias("haj");
           set_short("Oh I'm too sexy for this mud sings: Haji ran over all  the smurfs just for fun.");
          set_aggressive(1);
          set_wc(10);
          set_ac(5); 
          set_object(this_object());
          set_type("gives");
          money=clone_object("obj/money");
          money->set_money(700);
          move_object(money, this_object()); }
}

init() {
     set_heart_beat(1);
     add_action("west", "west");
     ::init();
}

west() {
     say("Troll says: Pay me 50 coins if you want to pass!\n");
     return 1;
}


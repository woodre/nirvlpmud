
inherit "obj/monster";
int old_money, money;

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("ladyfinger");
          set_level(9);
          set_hp(175);
          set_al(-200);
            set_alias("lady");
           set_short("Oh I'm idle too damn long sings: Ladyfinger the ever idle.");
           set_long("Hi I am wondering why you are always idle. Haji\n");
          set_aggressive(0);
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


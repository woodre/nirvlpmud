inherit "obj/monster";
int old_money, money;

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("troll");
          set_race("troll");
          set_level(9);
          set_hp(135);
          set_al(-200);
          set_short("a troll");
          set_long("It's dull, black eyes consider your smaller frame.\n"+
                   "A crop of wiry, green hair tops its mottled body.\n");
          set_aggressive(0);
          set_wc(13);
          set_ac(7); 
          set_object(this_object());
          set_function("give_troll");
          set_type("gives");
          money=clone_object("obj/money");
          money->set_money(400);
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

give_troll(str) {
     money=this_object()->query_money();
     if(money >= (old_money + 50)) {
          old_money = money;
          write("The troll waves you past.\n");
          say("The troll waves " + this_player()->query_name() + " past.\n");
          move_object(this_player(),
             "players/bastion/antaria/belgaers/road10");
          return 1;
     }
     write("The troll turns his nose up at your offer.\n");
     return 1;
}
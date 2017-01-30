
inherit "obj/monster";

reset(arg) {
     object money, amulet;
     ::reset(arg);
     if(!arg) {
          set_name("iron golem");
          set_race("golem");
          set_level(30);
          set_hp(1000);
          set_al(0);
          set_short("a large, iron golem");
          set_long("The golem regards you without intelligence. It seems\n"+
                   "content to remain motionless as long as you don't try\n"+
                   "leaving south or west.\n");
          set_aggressive(0);
          set_wc(50);
          set_ac(27); 
          set_chance(20);
          set_spell_mess1("The iron golem breathes poison.");
          set_spell_mess2("The iron golem breathes poison at you!");
          set_spell_dam(random(40)); 
/*
          money=clone_object("obj/money");
          money->set_money(2000 + random(1500));
*/
          amulet=clone_object("players/morgar/amulet");
          move_object(amulet, this_object()); }
}

init() {
     set_heart_beat(1);
     add_action("out", "west");
     add_action("out", "south");
     ::init();
     return 1;
}

out() {
     string who;
     who=this_player()->query_real_name();
     if (who=="bastion" || who=="damian")
          return 0;
     write("The golem bars your way.\n");
     say(who +
          " tries to get past the golem and fails.\n");
     return 1;
}

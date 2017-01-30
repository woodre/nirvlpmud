
inherit "obj/monster";

reset(arg) {
     object money, sword;
     ::reset(arg);
     if(!arg) {
          set_name("marilith");
          set_alias("demon");
          set_race("demon");
          set_level(30);
          set_hp(1500);
          set_al(-1000);
          set_short("A demon");
          set_long("A towering shadow stands over your puny form, outlined\n"+
                   "only by the aura of flame surrounding the creature.\n"+
                   "Huge, shadowy wings flutter as it advances.\n");
          set_aggressive(0);
          set_chance(20);
          set_spell_dam(random(50));
          set_spell_mess1("The demon's aura consumes its opponent.");
          set_spell_mess2("You are consumed within the demon's fire!");
          set_wc(50);
          set_ac(27); 
          money=clone_object("obj/money");
          money->set_money(5000);
          sword=clone_object("players/bastion/obj/flamesword");
          move_object(money, this_object());
          move_object(sword, this_object()); } 
}

heart_beat() {
   object ob;
   if (ob = present("quest_ob", environment())) {
      string who;
      who = ob->query_who();
      if (ob = find_player(who))
         attack_object(ob);
   }
  if(query_attack() && !present(query_attack(), environment())) {
    tell_object(query_attack(), format("The demon drags you back through " +
     "the ether!\n"));
    say(format(query_attack()->query_name() + " is vommited from a sudden " +
     "rift in space!\n"));
    move_object(query_attack(), environment());
  }
  ::heart_beat();
}

/*
 * THE GREAT DRAGON, ANDRIAKAS
 * Cloned from /pl/m/rowan/mtn/lair.c
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg) return;
   set_name("andriakas");
   set_alias("dragon");
   set_alt_name("wyrm");
   set_race("dragon");
   set_short("Andriakas, the black dragon");
   set_long("Andriakas is a magical black dragon created by the\n"+
            "Overfiend to wreak havoc on the town of Rowan.\n");
   set_level(30);
   set_hp(1000);
   set_wc(15);
   set_ac(10);
   set_heal(3,90);
   set_al(-1000);
   set_ep(1000000);
   set_aggressive(0);
   set_dead_ob(this_object());
   set_single_chance(35);  /* all chances must add up to 100 */
   set_single_dam(30);
   set_single_mess1("The dragon opens his giant maw and lunges!\n");
   set_single_mess2("Andriakas bites you!\n");
   set_number_of_attacks(3);
   set_multiple_chance(35);
   set_multiple_dam(20);
   set_multiple_mess1("The black dragon lashes out with his claws.\n");
   set_multiple_mess2("You're racked across your body by sharp talons!\n");
   set_mass_chance(20);
   set_mass_dam(80);
   set_mass_divisor(1); /* if divide mass_dam among players in room */
   set_mass_mess1("Andriakas breathes a cloud of acid!\n");
   set_mass_mess2("The acid sears your flesh!\n");
   set_regular_chance(10);
   set_can_kill(1);
   ::reset();
}

monster_died(ob) {
   object dest;
   object list;
   int i;
   dest = environment(ob);
   log_file("molasar.ck","\n");
   log_file("molasar.ck","**Andriakas killed => "+ctime(time())+" by:\n");
   list = users();
   for(i=0; i < sizeof(list); i++) {
      if(present(list[i], dest))
        log_file("molasar.ck","            "+
           capitalize(list[i]->query_real_name())+"       "+
           "Level: "+list[i]->query_level()+"    Extra_level: "+
           list[i]->query_extra_level()+"\n");
   }
   return 0;
}


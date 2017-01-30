duel(str) {
   object creature,weap;

weap = clone_object("obj/weapon");
weap->set_id("staff");
weap->set_short("A heavy bamboo staff");
weap->set_class(12);
weap->set_weight(2);
weap->set_value(50);

   creature = clone_object("obj/monster");
   creature->set_name("monk");
   creature->set_level(15);
   creature->set_hp(100);
   creature->set_al(500);
   creature->set_short("Monk of the White Zephyr");
   creature->set_wc(6);
   creature->set_ac(6);
   move_object(creature,environment(this_player()));
move_object(weap,creature);
call_other(creature,"init_command","wield staff");
   return 1;
}

inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "barpik" );
     set_alias("barpik");
     set_short("Barpik");
set_long("Barpik is a cruel slave trader.  He enjoys making a profit from\n"+
"the marketing other peoples souls.\n");
     set_level(15);
     set_ac(12);
     set_wc(18);
     set_hp(225);
     set_al(-1000);
     set_chat_chance(1);
     set_a_chat_chance(20);
 load_chat("Barpik doesn't appear too happy about your interuppting his bussiness.\n");
 load_chat("Barpik says 'Hey..wanna but a good slave?'\n");
 load_a_chat("Barpik says 'You will bring a good price!\n");
     set_dead_ob(this_object());
     money = (10);

 }
}

  monster_died() {
   object ob, attk;
   attk=this_object()->query_attack();
  tell_object(attk, "After you kill the cruel slave master a boney human male crawls up\n");
   tell_object(attk, "to you on his hands and knees.  He looks up at you sheepishly\n");
   tell_object(attk, "and says 'Master!'. 'I live but to serve you!'\n");
  tell_object(attk, "Behlliad is now your faithful servant.\n");

    if(this_player()) {
  ob = clone_object("/players/pavlik/closed/slave.c");
      move_object(ob, environment(this_player()));
    ob->set_owner(this_player()->query_real_name());
    ob->go();
       return 1;
}
 return 0;
}


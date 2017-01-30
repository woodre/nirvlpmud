inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "barpik" );
     set_alias("barpik");
     set_short("Barpik");
       set_long("Barpik is a devilish fellow.  There is a cold steel glint\n"+
       "in his eyes that tells you he wouldnt mind shoving his dagger into\n"+
       "you one bit.\n");
     set_level(11);
     set_ac(8);
     set_wc(15);
     set_hp(170);
     set_al(-150);
     set_chat_chance(1);
     set_a_chat_chance(20);
       load_chat("Barpik spins his dagger and growls at you\n");
       load_chat("Barpik says 'It might be wise to leave now nieghbor\n");
       load_a_chat("Barpik twist his dagger into your stomach\n");
       load_a_chat("You will learn what it means to mess with me!\n");
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


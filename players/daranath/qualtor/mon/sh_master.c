inherit "/obj/monster";
#define ROOT "/players/daranath/qualtor/"

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object(ROOT+"wep/jewl_dag.c"),this_object());
move_object(clone_object(ROOT+"obj/face_mask.c"),this_object());
move_object(clone_object(ROOT+"obj/black_boots.c"),this_object());
move_object(clone_object(ROOT+"obj/shm_armor.c"),this_object());

     set_name("The Shadow Master");
     set_short("A short person dressed in black");
     set_alias("person");
     set_alt_name("master");
     set_race("gnome");
     set_gender("male");
     set_long("A short person is lurking in the nearby shadows, confident that\n"+
              "his stealth abilities are keeping him hidden from your sight.\n"+
              "He is completly covered in black, including a mask that barely\n"+
              "fits over his huge nose. A large black cloak keeps any\n"+
              "weapons hidden from sight, with the exception of a dagger\n"+
              "in his right hand.\n");
     set_level(20);

     init_command("wield dagger");
     init_command("wear armor");
     init_command("wear boots");
     init_command("wear mask");

     set_ac(18);
     set_wc(30 + random(4));
     set_hp(525 + random(50));
     set_al(-1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(15);
     load_chat("The short person fumbles about with a small wooden box.\n");
     load_chat("The short person looks you over.\n");
     load_chat("The short person holds his hand triumphantly in the air and proclaims:\n"+
               "So says the Shadow Master!!!!\n");

   }
}

monster_died() {
write_file("/players/daranath/closed/log/terse_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}

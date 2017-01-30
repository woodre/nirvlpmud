inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("goblin");
   set_short("A short goblin");
   set_long("Despite being quite small goblins are known for their fierce attacks\n"+
            "and hardiness.  Beware when fighting these!\n");
   set_level(3);
   set_hp(45);
   set_wc(7);
   set_ac(4);
   set_al(-100);
   set_chat_chance(3);
   load_chat("Lets killem!\n");
   set_a_chat_chance(2);
   load_a_chat("Goblin suddenly shoots a loogie at you!\n");
   weapon=clone_object("/players/dersharp/weapons/dagger");
   move_object(weapon, this_object());
}

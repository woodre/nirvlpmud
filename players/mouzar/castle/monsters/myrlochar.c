inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("myrlochar");
set_alias("spider");
set_race("beast");
set_short("Myrlochar");
set_long("This is a large skeletal spider.  It hasn't noticed you yet.  You'd better\n"+
            "kill it before it notices you.\n");
set_al(0);
set_level(12);
set_wc(16);
set_ac(9);
set_hp(180);
set_aggressive(0);
set_chat_chance(5);
load_chat("The myrlochar spins within its web.\n");
set_dead_ob(this_object());
}

monster_died(ob) {
  tell_room(environment(ob), "You find a suit of armor in the remains of the spider's web.\n");
 move_object(clone_object("/players/feldegast/equip/ringmail.c"),present("corpse",environment()));
}

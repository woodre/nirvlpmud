inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Quickling");
  set_alias("quickling");
  set_short("A speeding blur of motion");
  set_long(
  "The viscous Quickling is a little impish creature with mottled green skin.\n"+
  "He is another twisted creation of evil wizards.  The quickling has been empowered\n"+
  "with supernatural speed and a habit for mischief!  His tiny body is merely a blur\n"+
  "of motion around you!\n");
  set_race("quickling");
  if(random(2)==1) set_gender("male"); else set_gender("female");
  set_level(17);
  set_hp(425);
  set_ac(25);
  set_al(-1000);
  set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(40);
  set_dead_ob(this_object());
  load_chat("A blur of motion speeds past you.\n");
  load_chat("Something behind you snickers softly.\n");
  load_chat("A blur of motion darts between your legs.\n");
  load_chat("You catch a glimpse of movement from the corner of your eye.\n");
  load_a_chat("Quickling spurts: YousonofabitchIllkillyouforthat!\n");
  load_a_chat("Quickling attempts to push you off the mountain trail.\n");
  load_a_chat("Quickling spurts: HaHaYouaretooslowtocatchme!\n");
  load_a_chat("Quickling darts between your legs.\n");
  load_a_chat("The viscous Quickling is just a blur of motion before you.\n");
  move_object(clone_object("players/pavlik/ilstkarn/weapons/quick_dagger"),
  this_object());
  command("wield dagger");
  set_wc(30);
  money = 400 + random(100);
}

id(str) {
  return (str=="quickling" || str=="quick" || str=="ilstkarn_monster"||str=="blur");
}


monster_died() {
  object ob;

  ob = present("corpse", environment(this_object()));
  if(!ob) return 0;

  if(random(3)==2) {
    move_object(present("dagger", ob), environment(this_object()));
  }

  tell_room(environment(this_object()),
  "The Quickling's beaten corpse disappears in a streaking flash of light!\n");
  move_object(ob, "room/void");
  destruct(ob);

  write_file("/players/pavlik/ilstkarn/KILL_LOG",
        ctime() + "\t"+query_name()+" killed by "+capitalize(this_player()->query_name())+" ("+ 
        this_player()->query_level()+")\n");

  return 0;
}


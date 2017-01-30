inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
       object item;
   item = clone_object("/players/bagera/weapons/collar.c");
move_object(item, this_object());
command("wield collar", this_object());
   set_name("ravish");
   set_alias("tiger");
   set_alias("ravish");
   set_short("Ravish, a huge tiger");
   set_long("A huge tiger that stands on guard over her mistress' room.\n");
   set_aggressive(0);
set_ac(20);
   set_wc(25);
   set_level(19);
   set_race("animal");
   set_hp(1000);
   set_al(-1000);
   set_chat_chance(2);
   load_chat("Ravish follows you with her eyes, seeing no harm comes to her mistress.\n");
   set_chance(70);
   set_a_chat_chance(50);
   load_a_chat("Ravish sinks her teeth deep into your arm, ripping a piece of flesh out!\n");
   load_a_chat("Ravish claws at your face, shredding it to pulp!\n");
   set_spell_dam(800);
   set_spell_mess1("The diamond studs fly from the collar, driving deep into your skin!\n");
   set_spell_mess2("You feel the diamonds ignite, setting you on fire!\n");
  }
 }

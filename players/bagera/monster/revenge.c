inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
       object item;
   item = clone_object("/players/bagera/weapons/collar.c");
move_object(item, this_object());
command("wield collar", this_object());
   set_name("revenge");
   set_alias("tiger");
   set_alias("revenge");
   set_short("Revenge, a large tiger");
   set_long("A huge tiger that stands on guard over his mistress' room.\n");
   set_aggressive(0);
  set_ac(15);
   set_wc(16);
   set_level(19);
   set_race("animal");
   set_hp(3000);
   set_al(-1000);
   set_chat_chance(1);
   load_chat("Revenge stands at guard growling when you get too close to his mistress.\n");
   load_chat("Revenge growls deep in his throat.\n");
   set_chance(10);
  }
 }

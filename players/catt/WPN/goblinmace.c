inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("goblin mace");
   set_alias("mace");
   set_short("A Goblins Mace");
   set_long("A small nasty looking mace with several small iron spikes\n"+
            "protruding from the head of the weapon.\n");
   set_value(75);
   set_weight(3);
   set_class(5+random(5));
}

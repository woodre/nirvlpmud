inherit "/obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("cannon");
   set_alias("phaser");
   set_short("A Disintegrator Cannon");
   set_long("A large disintegrator ray for wizzes only.\n");
   set_class(1000);
   set_weight(1);
   set_value(0);
}

inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("small double bladed battleaxe");
   set_alias("battleaxe");
   set_short("small double bladed battleaxe");
   set_long(
      "A small double bladed battleaxe that appears to be of low quality and yet\n"+
      "ruggedly useful.\n");
   set_value(50+random(25));
   set_weight(2);
   set_class(8+random(5));
}

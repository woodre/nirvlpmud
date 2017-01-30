inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("orc hammer");
   set_alias("warhammer");
   set_short("orc warhammer");
   set_long(
      "A warhammer of poor quality, its head is covered in dried blood and pieces\n"+
      "of flesh from prior victims of its use.\n");
   set_value(50+random(25));
   set_weight(2);
   set_class(8+random(5));
}

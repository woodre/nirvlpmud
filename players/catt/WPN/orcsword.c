inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("wicked sword");
   set_alias("sword");
   set_short("wicked sword");
   set_long(
      "A sword of poor quality with a wicked serrated edge. It might be useful.\n");
   set_value(50+random(25));
   set_weight(2);
   set_class(8+random(5));
}

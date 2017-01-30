
inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("mace");
   set_short("a mace");
   set_class(12);
   set_value(300);
   set_weight(3);
}


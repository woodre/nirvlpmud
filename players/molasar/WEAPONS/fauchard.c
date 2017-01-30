
inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("fauchard");
   set_short("a fauchard");
   set_weight(2);
   set_value(500);
   set_class(14);
}


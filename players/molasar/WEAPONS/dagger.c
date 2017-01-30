
inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("dagger");
   set_short("a dagger");
   set_weight(1);
   set_class(7);
   set_value(100);
}


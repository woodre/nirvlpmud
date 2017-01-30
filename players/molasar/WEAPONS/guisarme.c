
inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("guisarme");
   set_short("a guisarme");
   set_value(300);
   set_class(10);
   set_weight(2);
}


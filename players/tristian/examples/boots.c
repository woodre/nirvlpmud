inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("ring");
   set_short("A tinfoil ring");
   set_long(
      "This is a small silver ring made out of tinfoil. It won't\n"+
      "provide much protection.\n"
   );
   set_ac(1);
   set_type("boots");
   set_value(0);
}

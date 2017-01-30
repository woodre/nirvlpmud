inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("helm");
   set_short("A tinfoil helm");
   set_long(
      "This is a small silver ring made out of tinfoil. It won't\n"+
      "provide much protection.\n"
   );
   set_ac(2);
   set_type("helmet");
   set_value(0);
}

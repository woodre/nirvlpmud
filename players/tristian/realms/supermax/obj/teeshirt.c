inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("tee shirt");
   set_alias("shirt");
   set_short("A white t-shirt");
   set_long(
      "A thin, prison issue tee shirt.\n"
   );
   set_ac(1);
   set_type("chest");
   set_value(500);
}

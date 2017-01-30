inherit "obj/monster";


reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("missy");
   set_alias("cat");
   set_level(1);
   set_wc(1);
   set_ac(20);
   set_al(350);
   set_short("Missy");
   set_long("A rather large calico Main Coon cat.\n");

}

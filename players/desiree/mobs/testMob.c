inherit "obj/monster";


reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("tester");
   set_alias("mob");
   set_level(1);
   set_wc(1);
   set_ac(20);
   set_al(350);
   set_short("a tester mob");
   set_long("a guy for testing.\n");

}


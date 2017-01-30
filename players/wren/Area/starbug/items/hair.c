	/* Ace Rimmer's Hair */

inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("hair");
   set_alias("helm");
   set_short("Perfect Hair");
   set_long("This is the hair from Ace Rimmer. It is perfect just like him.\n"+
            "What a guy! They all swoon. Maybe you'd look as good wearing it.\n");
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(500);
}

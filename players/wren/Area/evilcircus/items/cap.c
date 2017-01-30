	/* Tusk's helmet */

inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("cap");
   set_alias("helmet");
   set_short("A tight leather cap");
   set_long("Tight leather cap with metal studs and the \n"+
            "words 'Tusk the Projectile' embroidered in \n"+
            "dark letters across its sooted brim.   \n");
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(500+random(100));
}

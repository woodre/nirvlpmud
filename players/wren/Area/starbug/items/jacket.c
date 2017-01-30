	/* armor basis */

inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("jacket");
   set_alias("armor");
   set_short("Lister's leather jacket");
   set_long("This is Lister's jacket. He wears this and hit cap \n"+
            "everywhere. Iron ons and badges from Titan and clubs \n"+
            "around Liverpool. It needs washed.\n");
   set_ac(2);
   set_type("armor");
   set_weight(1);
   set_value(600);
}

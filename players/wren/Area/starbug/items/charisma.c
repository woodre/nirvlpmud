	/* rimmers charisma */

inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("charisma");
   set_alias("aura");
   set_short("a charismatic aura");
   set_long("Those that know him have to say what a 'Smeghead'.\n"+
            "You don't know if you really want to use this aura.\n"+
            "It seems rather unusual.   \n");
   set_ac(-1);
   set_type("misc");
   set_weight(1);
   set_value(50);
}

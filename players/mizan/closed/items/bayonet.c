inherit "obj/weapon";

reset(arg) 
{
   ::reset(arg);

   if(!arg) 
   {

       set_name("cold steel bayonet");
       set_long("This is a blued steel bayonet with a slight curve in its foot-long\n"+
          "blade, complete with blood groove and crown.\n");

       set_short("A cold steel bayonet");
       set_class(10);
       set_value(300);
       set_alias("plugin_bayonet");
       set_alt_name("bayonet");
       set_weight(1);
       set_hit_func(this_object());
    }
}

weapon_hit(attacker)
{
   if(random(100) < 11) 
   {
   	write("You score a wicked slash to " + attacker->query_name() + "\n");
   	say((this_player()->query_name()) + " scores a wicked slash on " +
          attacker->query_name() + "!\n");
   	return 2;
	}
}

query_plugin_type()
{
   return "bayonet";
}

query_plugin_name()
{
   return "generic_bayonet";
}
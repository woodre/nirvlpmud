inherit "obj/weapon";

reset(arg) 
{

   ::reset(arg);
   if(arg) return;
	set_name("monkey wrench");
	set_class(15);
	set_value(350);
	set_weight(12);
	set_alias("wrench");
	set_short("A HUGE monkey wrench");
   set_long("This is an obscenely large tool. It must weigh nearly 20 pounds\n"+
      "and seems to be used for removing nuts and bolts meant to hold large\n"+
      "buildings together or something. It is a formidable weapon but you must\n"+
      "be strong as an elephant to really make use of it.\n");

}

query_save_flag() { return 1; }

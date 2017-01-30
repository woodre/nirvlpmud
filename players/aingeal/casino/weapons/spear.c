/* Robin Williams' spear from 'Jumanji' */

inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if(arg) return;
	
   set_name("spear");
   set_alias("bamboo spear");
   set_short("Bamboo Spear");
   set_long
     ("This long, primitive bamboo spear is sparsely decorated with dark\n"+
     "green leaves.  It is the same spear Robin Williams used in 'Jumanji'.\n");
   set_class(10);
   set_weight(3);
   set_value(200);
   set_type("spear");
   
}



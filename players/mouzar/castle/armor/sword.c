inherit "/obj/weapon.c";
reset(arg) {
if (arg) return;
::reset(arg);
         set_name("sword");
         set_short("A sword");
	set_long("A very nice sword.");
         set_value(400);
         set_class(13);
       }
 

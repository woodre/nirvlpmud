inherit "obj/armor";
reset(arg){
   ::reset(arg);
	set_short("Shroud");
   set_arm_light(0);
set_long(
	"A shroud that was once on a dead corpse.  You get the creeps when\n" +
"you think about wearing it.\n");
   set_ac(1);
   set_weight(1);
   set_value(500);
   set_alias("shroud");
   set_name("shroud");
   set_type("cloak");
}

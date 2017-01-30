inherit "obj/armor.c";
reset(arg){
  if(arg) return;
set_name("plate");
set_ac(4);
set_weight(4);
set_type("armor");
set_alias("breastplate");
set_arm_light(1);
set_short("A Black Breastplate with Red Decore");
set_long("A Large Breastplate with Red Decore...\n"+
       "It has a Large Red Eye on It...\n"+
       "This is Obviously the Battle Gear of the Nazguls...!!!\n");
set_value(6000);
}

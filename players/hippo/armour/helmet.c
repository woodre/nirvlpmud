inherit "obj/armor";
int i;
reset(arg){
   ::reset(arg);
   set_short("nutshell helmet");
   set_arm_light(0);
set_long(
      "The sharf of a nutshell, which might be worn\n"+
      "by people with small heads.\n");
   set_ac(1);
set_weight(1);
   set_value(75);
   set_alias("helmet");
set_name("nutshell");
set_type("helmet");
   i=random(2)+1;
   set_size(i);
}

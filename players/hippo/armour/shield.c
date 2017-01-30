inherit "obj/armor";
int i;
reset(arg){
   ::reset(arg);
   set_short("lap of meat");
   set_arm_light(0);
set_long(
    "A piece of meat strong enough to be used as a shield,\n"+
    "when you have found a size that matches your own size.\n"+
    "But remember: meat is heavy, more meat weights more...\n");
   set_value(100);
set_alias("meat");
   set_name("meat shield");
   set_type("shield");
   set_ac(1);
   i=random(5)+1;
   set_size(i);
   set_weight(i);
}

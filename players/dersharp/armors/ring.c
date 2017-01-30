inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("A plain gold ring");
   set_long("Once, long ago this ring had the power to defeat legions of undead\n"+
            ",but now it can only serve as an armor.\n");
   set_ac(1);
   set_weight(1);
   set_value(100);
   set_arm_light(4);
   set_alias("ring");
   set_type("ring");
}

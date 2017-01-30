inherit "/obj/armor.c";

void reset(status arg){
   if(arg) return;
   set_short("Glowing Band");
   set_long("Rumplemintz's Glowing Band.\n");
   set_arm_light(2);
   set_ac(2);
   set_type("ring");
   set_weight(1);
}

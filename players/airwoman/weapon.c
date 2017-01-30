inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("air blaster");
set_short ("air blaster");
set_alias ("blaster");
set_long("a powerful air blaster that blasts the air out of ditzheads\n");
set_value(10000);
set_weight(4);
set_class(19);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 100) {
write("x\n");
say(" \n");
return 10;
   }
return 0;
 }

inherit"obj/weapon";
reset(arg) {
if(arg) return;
set_name("klezmeer sword");
set_class(5);
set_weight(2);
set_value(30);
set_short("A Klezmeer sword");
set_long("A long arching sword.  Amazingly the effects of space\n"
        +"have not effected it in the least.  As you wield it\n"
        +"the weapon seems to mold itself to your hand and becomes\n"
        +"an extention of your arm.  You feel a hum of energy\n"
        +"emanating from it.  Somehow wielding the sword makes you feel\n"
        +"more at one with your surroundings, more in tune with\n"
        +"yourself...\n");
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 30) {
write("The Klezmeer sword flashes as it slices "+attacker->query_name()+" clean through !\n");
say(this_player()->query_name()+" slices "+attacker->query_name()+" with the Klezmeer sword !\n");
return 6;
   }
return 0;
 }

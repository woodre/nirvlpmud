inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
                set_class(1);
                set_value(0);
                set_weight(10);
                set_alias("razor");
set_long("This sword has been in the vampires guard for centuries. It is made of polished steel plated with silver.\n");
set_hit_func(this_object());
}
weapon_hit(attacker) {
int a;
   a=random(10);
   if(a == 0) {
   say("You are hit with a volley of magic missiles!\n");
   return 5;
   }
   if(a == 1) {
   say("The mage mubles and his spell fizzles.\n");
   return 1;
   }
   if(a == 2) {
   say("A fireball flys from the mage and into you!\n");
   return 10;
   }
   if(a == 3) {
   say("The mage raises his hand, points to you and spews a cone of cold at you!\n");
   return 18;
   }
}

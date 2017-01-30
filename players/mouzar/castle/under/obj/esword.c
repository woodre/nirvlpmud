inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("sword");
set_alias("evil sword");
set_short("Sword");
set_long(
"A normal looking sword.\n");
set_value(300);
set_weight(2);
set_class(15);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100)<25 && attacker->query_race() == "dwarf") {
write("You sword is guided by some unseen force driving deep into the "+attacker->query_name()+"\n");
say(this_player()->query_name()+"'s sword dives into the "+attacker->query_name()+"\n");
return 5;
   }
return 0;
 }

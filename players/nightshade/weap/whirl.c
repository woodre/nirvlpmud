/* changed the weapon random to 3 and added backlash...
    all multiple attack weapons must have severe drawbacks
    - mythos <5-10-96> */
    
inherit "obj/weapon";
int n;
reset(arg)
{
if(arg) return;
set_name("whirling blades of death");
set_short("Whirling blades of Death");
set_long("Theses are a set of steel blades.\n");
set_weight(5);
set_class(15);
set_alias("blades");
set_value(10000);
set_hit_func(this_object());
}
get() {
set_short(capitalize(this_player()->query_real_name())+
       "'s Whirling Blades of Death");
return 1;
}
weapon_hit() {
if(random(2) == 0) 
  environment()->heal_self(-1-random(10)); /* added the damage - mythos <5-10-96> */
   if(!n) {
      while(!random(3) && n < 3) {
      n++;
   if(environment()->query_hp() < 130) {
     environment()->heal_self(-5-random(10)); /* added the damage - mythos <5-10-96> */
   }
   environment()->attack();
}
call_out("nzero", 2); 
} 
}
nzero() {
   n = 0;
   return 1;
}

/* approved by mythos on 10/26/95   please talk to him if there is a problem  */

int w,n,ahp;
inherit "obj/weapon.c";
reset(arg) {
    if (arg) return;
    ::reset();
    set_name("icepick");
    set_alias("ice pick");
set_short("A Sharp Ice Pick");
set_long("A long sharp ice pick, looks like it could be deadly...\n");
    set_class(18);
    set_weight(3);
    set_type("knife"); /* 6.6.01 by verte */
    set_value(1000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   if(call_other(this_player(), "query_attrib", "str") > random(50)) {
write("You jab your enemy in the eye with your sharp ice pick.\n");
write("The Ice Pick is covered with the blood of your enemy!\n");
n = random(10);
return n;
   }
   return;
}

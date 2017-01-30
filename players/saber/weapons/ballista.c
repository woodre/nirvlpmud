#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("ballista");
    set_alias("crossbow");
    set_type("crossbow");         /* set type added by Pavlik */
    set_short("A LARGE ballista");
     set_long("A very large crossbow, ususally mounted upon castle walls.\n");
    set_class(17);
    set_weight(7);
    set_value(1100);
   set_hit_func(this_object());
}

weapon_hit(attacker){
w = random(10);
if (w>8) {
write("You hit your opponent dead center with a bolt.\n"+
       "Your foe is impaled upon a huge crossbow bolt.\n");
say(tp+"hits their opponent dead center with a huge crossbow bolt.\n");
return 7;
}
return;
}

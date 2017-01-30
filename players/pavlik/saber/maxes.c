#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("magical axes");
    set_alias("axe");
   set_alt_name("axes");
    set_type("axe");         /* set type added by Pavlik */
   set_short("A pair of magical hand axes");
   set_long("A pair of very sharp magical hand axes.\n");
    set_class(17);
    set_weight(2);
    set_value(875);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(13);
   if (w>10) {
say(tp+" hurls an axe at "+attacker->query_name()+".\n"+
   "The axe magicially returns to the hand of "+tp+".\n");
write("You hurl an axe at "+attacker->query_name()+".\n"+
   "The axe magicially reaturns to your hand.\n");
return 5;
    }
    return;
}

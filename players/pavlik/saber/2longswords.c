#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("two longswords");
   set_alias("longsword");
   set_type("sword");         /* set type added by Pavlik */
   set_alt_name("longswords");
   set_short("A pair of Magical Longswords");
   set_long("A pair of enchanted longswords forged from cold iron.\n"+
     "They are covered with silver runes.\n");
   set_read("Forged by Laura, Weapons Master of the Bards.\n");
   set_class(17);
   set_weight(3);
   set_value(800);
   set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(15);
   if (w>11) {
say(tp+" is bathed in a blue aura as the silver runes on the\n"+
     "longswords pulse with ancient power.\n");
write("You are bathed in a blue aura as the silver runes on your\n"+
     "longswords pulse with ancient power.\n");
return 7;
    }
    return;
}

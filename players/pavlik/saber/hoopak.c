#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("hoopak");
    set_alt_name("hoopak of doom");
     set_short("Hoopak of Doom");
    set_type("staff");         /* set type added by Pavlik */
    set_long("An exquisite Hoopak, constructed from a beautiful mahogany wood.\n"+
          "The hoopak is covered with strange silver runes, and appears to\n"+
          "be heavily enchanted.\n");
    set_class(17);
    set_weight(2);
    set_value(2000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
   write("You *whop* your foe over the head with the hoopak.\n");
write(""+capitalize(attacker->query_real_name())+" looks very confused.\n");
   say(tp+" *whops* "+capitalize(attacker->query_real_name())+" over the head with a hoopak.\n");
say(" "+attacker->query_real_name()+" looks very confused.\n");
      return 6;
    }
    return;
}

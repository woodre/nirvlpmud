#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
   set_name("dueling knife");
   set_alias("blade_knife");
   set_alt_name("knife");
   set_short("A dueling knife");
   set_long("A very sharp dueling knife.\n"+
        "It is a weapon for duels to first blood.\n");
    set_class(10);
    set_weight(0);
    set_value(0);
    set_hit_func(this_object());
}

  drop()  { return 1; }
  can_put_and_get()   { return 0; }

weapon_hit(attacker){
   w=random(15);
   if (w>12) {
say(tp+" slices "+attacker->query_name()+" across the face.\n");
write("You slice "+attacker->query_name()+" across the face.\n");
return 6;
    }
    return;
}

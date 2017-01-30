#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
   set_name("kitty_claws");
   set_short("A pair of razor sharp claws");
   set_long("Razor sharp retractable claws extending from your fingers.\n");
    set_class(14);
    set_weight(0);
    set_value(0);
    set_hit_func(this_object());
}

  drop()  { return 1; }
  can_put_and_get()   { return 0; }

weapon_hit(attacker){
string gender;
   w=random(15);
   if (w>12) {
gender = this_player()->query_possessive();
say(tp+" slices through "+gender+" opponent with razor sharp claws.\n");
write("You slice through your opponent with razor sharp claws.\n");
return 2;
    }
    return;
}

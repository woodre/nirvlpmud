inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shotgun");
    set_short("A powerful shotgun");
    set_long("You look down the sawed off barrel of the 12 gauge shotgun\n" +
             "It looks as every bit powerful as you could have imagined.\n");
    set_class(17);
    set_weight(6);
    set_value(10000);
    set_hit_func(this_object());
}

query_save_flag() { return 1; }
 
weapon_hit() {
int W;
    W = random(20);
  if((W < 8) && (W > 3)) {
      this_player()->add_spell_point(-W);
      write("The shotgun tears a hole into your opponent!\n");
      say(capitalize(this_player()->query_real_name())+"'s shotgun tears a hole into their foe.\n");
      return W;
  } else if(random(10) < 2) {
      return (2 + random(4));
    }  
}


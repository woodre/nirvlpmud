inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("purse");
    set_short("A nasty looking purse");
    set_long("You see an old bag-lady's purse.  It is filled with useless\n" +
             "things.  It looks like it could be a decent weapon.\n");
    set_class(14);
    set_weight(3);
    set_value(5000);
    set_hit_func(this_object());
}
 
weapon_hit() {
int W;
    W = random(20);
   if((W < 4) && (W > 1)) {
      say(capitalize(this_player()->query_name())+" clobbers their opponent with their purse!\n");
      write("You clobber your opponent with your purse!\n");
      return W;
    } else { 
      return 0; 
    }  
}


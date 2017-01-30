inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("ice dagger");
    set_alias("dagger");
    set_short("A scintillating dagger");
    set_long("A beautiful shimmering dagger made of living ice crystals.\n");
    set_class(16);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(8);
  if(W > 6)  {
  say("The shimmering dagger of ice leaves a burning sliver\n" +
         "of living crystal in its foe.\n");
  write("Your ice dagger shudders as it enters your foe.\n"+
           "Your unlucky opponent falls screaming to the floor. \n");
return (3 + random(4));
 
   }
       return;
}

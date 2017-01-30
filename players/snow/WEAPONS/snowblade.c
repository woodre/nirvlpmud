inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("snowblade");
    set_alias("blade");
    set_short("A flake of snow");
    set_long("A fine flake of snow. \n");
    set_class(200);
    set_weight(1);
    set_value(450000);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(12);
  if(W > 3) {
     say("You are chilled to the bone.\n");
  write("Your snowflake freezes the flesh of your enemy.\n"+
           "The frozen flesh crumbles and falls off.\n");
return 10000;
 
   }
       return;
}

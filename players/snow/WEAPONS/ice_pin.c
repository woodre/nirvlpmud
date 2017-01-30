inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("ice pin");
     set_alias("pin");
     set_short("A small pin of frozen water");
     set_long("A weapon made of ice. Use it quickly for it will melt.\n");
     set_class(12);
     set_weight(1);
     set_value(0);
    set_hit_func(this_object());
call_out("melt_pin",200);
}
weapon_hit() {
int W;
    W = random(8);
  if(W > 6)  {
  say(this_player()->query_name()+" goes wild with the ice pin!\n");
  write("You go wild with the ice pin!\n");
return (random(4));
 
   }
       return;
}

melt_pin() {
if(wielded) {
 say("The pin melts from your grasp... the water flows away...\n");
destruct(this_object());
return 1;
       }
else
  say("An ice pin melts and leaves your clothes wet...\n");
 destruct(this_object());
return 1;
}

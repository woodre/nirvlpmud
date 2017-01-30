inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("darkblade");
  set_alias("blade");
  set_short("A dark blade");
  set_long("A Blade of Darkness- a cold and dark blade.\n" +
     "If looked closely shadowy runes are written in it.\n");
  set_read("Soul Seeker\n");
  set_class(17);
  set_weight(3);
  set_value(800);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say("The Dark Blade seems to Suck the Soul from its foe.\n"+
   "You sense that something evil has occured.\n");

  write("The Dark Blade seems to suck the Soul from your foe.\n"+
    "You sense Evil has been done.\n");
return 5;

   }
   return;
}

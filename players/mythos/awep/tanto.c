inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("tanto");
  set_alias("dagger");
  set_short("Tanto");
  set_long("This dagger- or short blade- has a keen edge.\n"+
    "it has been made with great care.\n");
  set_class(12);
  set_weight(1);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(5);
if(W==0)  {
  say("You squirm as you see the dagger dig deep into the\n"+
    "belly of its foe!\n");
  write("You feel good as you watch the dagger stab deep into the\n"+
    "belly of your foe.\n");
return 5;
   }

   return;
}

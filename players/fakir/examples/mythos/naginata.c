inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("naginata");
  set_alias("naginata");
  set_short("Naginata");
  set_long("This two-and-a-half meter glaive is a weapon to behold.\n"+
    "Its hefty wooden shaft ends in a gleaming curved blade.\n");
  set_class(15);
  set_weight(2);
  set_value(500);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(20);
if(W>14)  {
  say("\nThe Naginata carves into its foe.\n\n"+
    "    ~~~~~~~~~ S L A S H ~~~~~~~~~\n\n"+
    "You see BLOOD fly everywhere.\n");
  write("\nThe Naginata carves into your foe.\n\n"+
    "     ~~~~~~~~ S L A S H ~~~~~~~~\n\n"+
    "The BLOOD flies everywhere.\n");
return 4;

   }
   return;
}

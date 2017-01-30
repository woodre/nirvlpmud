inherit "obj/weapon";
int i, j;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_id("lich axe");
      set_alias("axe");
      set_short("A Lich Axe");
set_long("This weapon was hidden from some very powerful clerics by a lich to"
+" hide\nit's true powers.\n");
      set_class(19);
      set_weight(8);
      set_value(4500);
      set_hit_func(this_object());
}
weapon_hit(attacker) {
  j = attacker->query_alignment();
  if (j<-100) {
   i=random(20);
   if (i<7) {
say(this_player()->query_name()+" attacks the soul of the evil being.\n");
   write("You drain the soul out of this evil being.\n");
   return 7;
  }
  }
return 1;
}

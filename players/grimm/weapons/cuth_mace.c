inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("mace");
      set_short("St. Cuthbert's Mace");
set_long("This is the famous mace that once belonged to St. Cuthbert, a\n"+
"very powerful cleric of olden days.\n");
      set_class(17);
      set_weight(7);
      set_value(3500);
      set_name("St. Cuthbert's Mace");
      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i<4) {
say(this_player()->query_name()+"'s mace hit his opponent's jaw, sending out"
+" a fine red mist.\n");
write("You hit your opponent across the jaw sending out a fine red mist.\n");
   return 7;
}
return 0;
}

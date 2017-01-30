inherit "obj/weapon";
int w;
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_class(12);
      set_value(750);
      set_weight(4);
      set_name("sword");
      set_alias("sword");
set_type("sword");
      set_short("A Power Sword");
      set_long("Jason, the Red Ranger's Power Sword.\n");
      set_hit_func(this_object());
   }
}
wield(arg) {
   if(::wield(arg));
   if(id(arg)) {
      write("You feel a surge of...POWER!\n");
   }
   return 1;
}
weapon_hit(attacker)
{
   w=random(20);
   if (w>10) {
      say("The Power Sword slices through the enemy.\n");
      write("Your Power Sword slices your opponent in two.\n");
      return 10;
   }
}
query_save_flag() { return 1; }

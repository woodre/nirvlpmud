inherit "obj/weapon";

reset(arg) {
   if (arg) return;
   ::reset(arg);
   set_name("blade");
   set_alt_name("sword");
   set_short("An onyx blade");
   set_alias("blade");
   set_long("A forgotten relic of the dark ages. You notice a powerful\n"+
      "dark aura surrounding the hilt.\n");
   set_class(17);
   set_hit_func(this_object());
   set_weight(5);
   set_value(6000);
}

weapon_hit(attacker) {
   if (random(30) > 20) {
      write("The blade slices through the air with a keen whistle.\n");
      say(capitalize(this_player()->query_name())+"'s blade slices through "+
         "the air with a keen whistle.\n\n", this_player());
      return 5;
   }
   else if(random(30) < 5) {
      write("The blade slices keenly through your opponent!!\n");
      say(capitalize(attacker->query_real_name())+"'s blade slices keenly through "+
         attacker->query_possessive()+" opponent!!\n");
      return 7;
   }
}

int w, z;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("revolver");
    set_alias("colt");
    set_type("gun");         /* set type added by Pavlik */
    set_short("A Colt .68 Heavy Revolver");
    set_long("The biggest Heavy Revolver you have ever seen!\n");
    set_class(17);
    set_weight(2);
    set_value(800);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(100);

   if (w>70) {

say(this_player()->query_name()+" blows "+attacker->query_name()+" away with a well aimed shot from "+this_player()->query_possessive()+" Colt .68\n");
write("You knock "+attacker->query_name()+" back with a well placed shot from your Colt .68\n");

   if(w> 90)  {
  z = random(6);

  tell_room(environment(this_player()),
   this_player()->query_name()+" fires again at "+attacker->query_name()+".\n");

  while (z < 6)  {

  tell_room(environment(this_player()),
   "\n BAMN!\n");
   z = z + 1;
       }

  write("\n");
  say("\n");
attacker->heal_self(-5);
        }
  return 7;
    }
    return;
}

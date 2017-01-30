inherit "obj/weapon";
 int x;
#define who this_player()->query_real_name() 
#define att call_other(attacker, "query_name", 0)

reset(arg) {
   if(arg) return;
   set_name("longbow");
   set_alias("longbow");
   set_short("longbow");
   set_long("A longbow.\n");
   set_weight(3);
   set_class(19);
   set_value(5000);
   set_hit_func(this_object());
}

query_save_flag() { return 1; }

weapon_hit(attacker) {
   int mm, nn;
   mm = 100;
   nn = 350;
   if(random(mm) < 80 && random(mm) > 10) {
  write("You smashed "+capitalize(att)+" with a bone crushing sound.\n");
    say(capitalize(who)+ " smashed " +capitalize(att)+" with a bone crushing sound.\n");
if(this_player()->query_spell_point() < 0) {return 1;}

      second();
   }
   if(random(nn) > 25) {
   write("You hit "+capitalize(att)+" very hard.\n");
  say(capitalize(who) +" hit " +capitalize(att)+" very hard.\n");
      third();
   }
   else if(random(100) < 80) return 3; }

second() {
write("The longbow strikes another magical arrow into your opponent\n");
  this_player()->add_spell_point(-2);
  return 5;
}
  third() {
  write("The longbow strikes another magical arrow into your opponent\n");
  this_player()->add_spell_point(-2);
  return 5;
}

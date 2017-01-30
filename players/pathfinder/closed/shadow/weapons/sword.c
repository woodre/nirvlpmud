inherit "obj/weapon";
 
string owner;
 
set_owner(own) { owner = own; }
 
drop(silently) {
  ::drop(silently);
  if(wielded) {
    call_other(environment(this_object()),"stop_wielding");
  }
  destruct(this_object());
  return 1;
  }
 
reset(arg) {
  ::reset(arg);
  set_name("shadow sword");
  set_alias("sword");
  set_class(16);
  set_weight(4);
  set_value(0);
  set_short("A Shadow Sword");
  set_long(
  "As you peer down the shadowy blade you see a mysterious and shadowy\n"+
  "figure embedded deep within the blade, radiating a shadowy power\n"+
  "from the blade and into you.  You can feel the presence of a power\n"+
  "greater than yourself as you hold it.  You feel much more powerful\n"+
  "with the Shadow Sword in your possession.\n");
  set_hit_func(this_object());
}
 
init() {
  ::init();
  if(environment(this_object())->query_real_name() != owner) {
    write("You are not the owner of this Shadow Sword!\n");
    destruct(this_object());
    return 1;
    }
}
 
query_save_flag() { return 1; }
 
weapon_hit(attacker) {
  object me, mark;
  int al, num, lev;
  me = find_living(environment(this_object())->query_real_name());
  mark = present("shadow-mark",me);
  num = mark->query_shlevel();
  al=environment(this_object())->query_alignment();
  if(random(15) < 7) {
   if(al > 0) {
     write("You feel the good within you shatter the blade as you try to attack\n");
     write("your foe.\n");
     say(capitalize(environment(this_object())->query_real_name())+"'s sword shatters.\n");
     destruct(this_object());
     return 1;
     }
   if(al > -500) {
     lev = random(2);
     }
   if(al > -1000) {
     lev = random(3);
     }
   if(al > -2000) {
     lev = random(4);
     }
   write("You are completely overwhelmed by the power of the sword as\n");
   write("you inflict major damage upon your opponent\n");
   say(capitalize(environment(this_object())->query_real_name())+" is engulfed in a shadow cast by their\n");
   say("sword as they deal immense damage to their foe.\n");
   return lev;
     }
}


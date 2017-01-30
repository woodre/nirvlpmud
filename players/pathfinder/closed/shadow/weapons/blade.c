/* Coded by Pathfinder as a guild weapon that is only usable */
/* by its owner, which is set in the guild obj. */
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
  set_name("shadow blade");
  set_alias("blade");
  set_class(15);
  set_weight(4);
  set_value(0);
  set_short("A Shadow Blade");
  set_long(
  "As you lock your eyes upon the shadowy darkness of the Shadow Blade you\n"+
  "notice the blade seems alive with energy, radiating it in all directions\n"+
  "You are encompassed in some of this energy and feel your body grow\n"+
  "more powerful as you hold the blade in your hand.\n");
  set_hit_func(this_object());
}
 
init() {
  ::init();
  if(environment(this_object())->query_real_name() != owner) {
    write("You are not the owner of this Shadow Blade!\n");
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
  if(random(15) < lev) {
   if(al > 0) {
     write("You feel the good within you shatter the blade as you try to attack\n");
     write("your foe.\n");
     say(capitalize(environment(this_object())->query_real_name())+"'s sword shatters.\n");
     destruct(this_object());
     return 1;
     }
   if(al < -500) {
     lev = 1;
     }
   if(al < -1000) {
     lev = random(2);
     }
   if(al < -2000) {
     lev = random(3);
     }
   write("You are completely overwhelmed by the power of the blade as\n");
   write("you inflict major damage upon your opponent\n");
   say(capitalize(environment(this_object())->query_real_name())+" is engulfed in a shadow cast by their\n");
   say("sword as they deal immense damage to their foe.\n");
   return lev;
  }
}


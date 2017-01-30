/* appoved on 10/26/95 by mythos.. please talk to him if there is a problem */

/* This weapon is so kick ass because to get it the player must find */
/* 3 parts and kill 2 Very tough monsters then assemble it, plus it */
/* does not store. */
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w,n,ahp;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
set_name("gun");
set_short("A Tommy gun");
set_long("This Tommy gun looks like one the mobsters would use...\n");
    set_save_flag(1);
   set_class(21);
   set_weight(3);
   set_value(450);
   set_hit_func(this_object());
}
weapon_hit(attacker){
if(random(3) == 0) { 
  this_player()->heal_self(-1-random(10));
  write("You feel a deep bite as the Tommy gun fires.\n");
}
  if(call_other(this_player(),"query_attrib","str")>random(50)){
say(tp+" lets off a few rounds with his Tommy gun, filling his victim with holes!\n");
write("You let off a few rounds with your Tommy gun, filling your victim with holes!\n");
    n=random(15);
return n;
    }
    return;
}

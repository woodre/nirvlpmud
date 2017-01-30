/*  approved on 10/26/95 by mythos  please talk to him if 
    you have a problem
*/
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w,n,ahp;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
set_name("foot");
set_alias("big foot");
set_short("A BIG foot");
set_long("A big hairy foot with razor sharp toenails\n");
   set_class(20);
   set_type("club");
   set_weight(6);
   set_value(1000);
   set_hit_func(this_object());
}
weapon_hit(attacker){
  if(call_other(this_player(),"query_attrib","str")>random(60)){
say(tp+" leaves a size 22 imprint on its victims forehead!\n");
write("You leave a size 22 imprint on your victims forehead!\n");

  /* added in a drawback of backlash to cmpensate for a wc 20 + return of 12  - mythos  */
    if(!random(30)){
    this_player()->heal_self(-1-random(10));
    write("You stub your toe!\n");
  }

return 12;
    }
    return;
}

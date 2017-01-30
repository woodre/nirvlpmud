#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("filthy spear");
   set_alias("spear");
set_short("A Filthy Spear");
   set_class(15);
   set_type("polearm");
   set_weight(2);
   set_value(1100);
   set_broke(1);
   set_hit_func(this_object());
}
weapon_hit(attacker){
         w = random(20);
   if (w>18) {
say(tp+" shoots a fountain of poison blood from the tip of their spear.\n");
write("Your spear shoots out a fountain of poison blood.\n");
     attacker->hit_player(random(7), "other|poison");
    }
    return;
}

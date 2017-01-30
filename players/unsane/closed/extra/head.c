#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
set_name("head");
set_alias("al's head");
set_short("Al Bundy's head");
set_long("That last headbutt must have been to much for poor Al.  At least now, you\n"+
"can use this deadly weapon in combat.");
set_save_flag(1);
   set_class(19);
   set_weight(10);
   set_value(2000);
   set_hit_func(this_object());
}
weapon_hit(attacker){
         w = random(20);
  if(w>15) {
say(tp+" swings Al Bundy's head and smashes his foe.\n");
write("You swing Al Bundy's head and smash your foe!\n");
return 3;
}
    return;
}

/* this weapon should not save as is so the query_save_flag() is added
                        - mythos */

query_save_flag() { return 1;}

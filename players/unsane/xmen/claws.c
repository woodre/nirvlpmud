#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
set_name("claws");
  set_alias("adamantium claws");
set_short("Adamantium Claws");
set_long(
"These are the legendary claws ripped from Wolverine's corpse.  Somewhere\n"+
"in the process they lost their invulnerability, but they're probably\n"+
"still tougher than ordinary metal.\n");
   set_class(19);
   set_weight(5);
   set_value(5000);
   set_hit_func(this_object());
}

query_save_flag() { return 1; }
weapon_hit(attacker){
         w = random(20);
  if(w>16) {
say(tp+" slices up his foe with the claws!\n");
write("SNIKT!\n");
return 8;
}
    return;
}
query_wear() { return ::query_wear()*3/4; }

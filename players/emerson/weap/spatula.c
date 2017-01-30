#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("spatula");
    set_short("Spatula");
set_long("A stainless steel spatula.\n");
   set_class(10);
   set_weight(3);
   set_value(650);
   set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(15);
   if (w>11) {
say(tp+" slaps his victim across the face with the spatula\n");
write("You slap your opponent across the face with the spatula!\n");
return 7;
    }
    return;
}

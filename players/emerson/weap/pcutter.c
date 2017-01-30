#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("pizza cutter");
   set_alias("cutter");
    set_short("Pizza Cutter");
    set_long("A very sharp stainless steel pizza cutter.\n"+
    "It looks like it could cause a serious cut!\n");
   set_class(16);
   set_weight(3);
   set_value(800);
   set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(15);
   if (w>11) {
say(tp+" slashes his victim across the face with the pizza cutter\n");
write("You slash your opponent across the face with the pizza cutter!\n");
return 7;
    }
    return;
}

#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("trident of war");
    set_alias("trident");
    set_type("trident");         /* set type added by Pavlik */
     set_short("The Trident of War");
     set_long("A trident of cold black iron.\n"+
       "The trident quivers slightly in your hand.\n");
    set_class(18);
    set_weight(3);
    set_value(1000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
 if(call_other(this_player(), "query_attrib", "str") > random(80)) {
say("The Trident of War pulses with dark shadows of power as it drains\n"+
   "lifeforce from the very soul of its foe.\n"+
   tp+" looks stronger.\n");
write("The Trident of War pulses with dark shadows of power as it drains\n"+
   "lifeforce from the very soul of your foe.\n"+
   "You feel stronger.\n");
call_other(this_player(),"heal_self",3);
return 4;
    }
    return;
}

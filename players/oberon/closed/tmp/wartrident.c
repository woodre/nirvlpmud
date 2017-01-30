#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("trident of war");
    set_alias("trident");
    set_type("polearm");         /* set type added by Pavlik */
     set_short("The Trident of War");
     set_long("A trident of cold black iron.\n"+
       "The trident quivers slightly in your hand.\n");
    set_class(18);
    set_weight(3);
    set_value(1000);
    /* changed special to magical type - illarion dec 2004
    set_hit_func(this_object());
    */
    set_params("magical",0,"magic_hit");
}
/* changed to use wil instead of str for special
   non-players are assumed to have a wil of their level
 */
magic_hit(attacker){
  int w;
  if(this_player()->is_player())
    w=random(this_player()->query_attrib("wil"));
  else
    w=random(this_player()->query_level());
  if(w>15) { /* 25% chance of success with 20 in attrib, same as before changes */
    say("The Trident of War pulses with dark shadows of power as it drains\n"+
       "lifeforce from the very soul of its foe.\n"+
       tp+" looks stronger.\n");
    write("The Trident of War pulses with dark shadows of power as it drains\n"+
       "lifeforce from the very soul of your foe.\n"+
       "You feel stronger.\n");
    call_other(this_player(),"heal_self",3);
    return 5;  /* 0-4 magic damage */
  }
  return;
}

#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
set_name("visor");
   set_alias("ruby visor");
set_short("Cyclops's Ruby Visor");
set_long("This visor contains ruby crystals that help Cyclops to control his\n"+
"powerful optic blasts.  Who knows?  Maybe when you don it, you will\n"+
"awaken your own mutant abilities?\n");
   set_class(18);
   set_weight(2);
   set_value(3000);
   set_hit_func(this_object());
}
weapon_hit(attacker){
         w = random(20);
  if(w>16) {
say(tp+" jerks back when an optic blast shoots out of their visor.\n");
write("You unleash an optic blast at your foe!\n");
this_player()->add_spell_point(-10);
/* I DONT think so... because of sp drain and low chance ... 1 in 4 .. the return is 8 - Mythos <9-30-96>
return 13;
*/
/* I DONT think so.. uh.. because.. I am gay. */
/*
return 8;
*/
attacker->hit_player(random(8), "other|laser");
}
    return;
}

init()
{
     ::init();
      add_action("wield", "don");
}

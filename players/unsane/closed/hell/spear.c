#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("poisoned spear");
   set_alias("spear");
set_short("A Dangerous Poisoned Spear");
set_long("This weapon was used by the harpies to kill many adventurers.  It oozes\n"+
"poison blood while you watch it.  It is a formidable weapon.\n");
   set_class(17);
   set_weight(2);
   set_value(3000);
   set_hit_func(this_object());
}
weapon_hit(attacker){
         w = random(50);
   if (w>46) {
say(tp+" shoots blood down the throat of their foe!\n");
write("You have poisoned your foe with the blood of the spear.\n");
return 10;
    }
if (w < 3) {
say(tp+" has poisoned themself!\n");
write("The spear turns on you and you are poisoned!\n");
this_player()->add_spell_point(-10 - random(30));
return 0; }
if (w > 25 && w < 35) {
write("You drive the point of your spear into your foe!\n");
say(tp+" drives their spear right into their foe!\n");
return 5;}
    return;
}

query_save_flag() { return 1; }
/* should not save when it has such a big return - mythos <6-15-96> */

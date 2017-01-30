#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("boulder");
   set_alias("huge boulder");
set_short("A Huge Boulder");
set_long("This massive object was being used by the masses to bludgeon each other.\n"+
"Perhaps if you are tough you could wield it?\n");
set_class(20); /* Have fun kids */
   set_weight(15); /* ahahaha */
   set_value(random(2000));
   set_hit_func(this_object());
}
weapon_hit(attacker){
         w = random(20);
if (w>16) {
say(tp+" smashes his foe on the head with their boulder!\n");
write("You smash your foe with the giant bolder!\n");
return 5;
    }
    return;
}

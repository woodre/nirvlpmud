#define tp this_player()->query_name()
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("silver ring");
  set_alias("ring");
  set_short("Silver Ring");
  set_long("The ring gleams softly in the light.  Something about it makes\n"+
    "it seem very special.  There is something etched into it.\n");
  set_read("       FIRE\n");
  set_class(12);
  set_weight(1);
  set_value(200);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(20);
if(W>16)  {
  say(tp+"'s hand glows with a strange light.\n"+
    "\n  The hand BURSTS into FLAME!\n\n"+
    "You see "+tp+"'s foe topple back in pain.\n");

  write("As you punch at your foe, you hand glows with a strange light.\n"+
    "\n    Your hand BURSTS into FLAME!\n\n"+
    "Your foe topples back in pain.\n");
return 6;

   }
   return;
}

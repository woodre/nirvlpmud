inherit "obj/monster.c";
#define attacked (this_object()->query_attack())


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("bat");
set_race("creature");
set_short("A large bat");
set_long(
  "  This bat is much larger than any you have every seen.  Its\n"+
  "only goal in life is to feed off of unsuspecting intruders into\n"+
  "its domain\n");
 
set_level(13);
set_hp(195);
set_al(0);
set_ac(10);
set_wc(17);
set_dead_ob(this_object());
set_aggressive(1);
}
 
monster_died(){
  object wings;
  tell_object(attacked,
   "The bat lets out one last screech as it falls to the ground dead.\n");
  wings = clone_object("/players/catacomb/Cavern/items/batwing.c");  
  move_object(wings, this_object());
}   
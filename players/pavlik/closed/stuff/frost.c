inherit "obj/armor";
object player, chill;
 reset(arg) {
 ::reset(arg);
if (arg) return;
set_name("frost armor");
set_short("Frost Armor");
 set_long("Heavy black armor that surrounds the room with a cold chill.\n"+
    "The armor is inscribed with silver runes that glow softly.  You\n"+
   "can feel the power from this armor surge around you.\n");
   set_type("armor");
   set_ac(3);
   set_weight(6);
   set_value(65000);
   set_alias("armor");
}
init() {
 ::init();
if (player && player != worn_by) {
   if (chill)   desctruct(chill);
player = 0;
if (worn_by) {
player = worn_by;
}
}
  }
wear(str) {

   if(this_player()->query_will_power() > 5) {
     write("You are not strong enough to wear this armor!\n");
         return 1;
              }
  ::wear(str);
if (worn_by && !player) {
  player = worn_by;
  if (chill) destruct(chill);
  chill = clone_object("/players/pavlik/closed/stuff/shock.c");
  chill->shadow_target(player);

  if(this_player()->query_luck() < 3) {
   this_player()->raise_luck(-2);
   } else {
    this_player()->raise_will_power(-2);
 }
 write("It feels is if you just wrapped yourself up in an icecube.\n"+
   "But, you can feel the power of this armor flow through your veins\n");
return 1;
      }
}

take_off() {
::take_off();
player = 0;
if (chill) destruct(chill);
}
remove(str) {
if (!::remove(str)) return 0;
player = 0;
if (chill) destruct(chill);
return 1;
}

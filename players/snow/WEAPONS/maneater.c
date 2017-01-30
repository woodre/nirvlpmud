/*
This wc15 scythe derives its extra_hit from the attribute strength.
It has a max return of 4 unless against the monster race "man"
In which case it does a max of 10 -all dependent on strength.
*/
 
#define MEAT this_player()->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define GEN this_player()->query_possessive()
#define TPS call_other(this_player(),"query_attrib","str")
#define TPN capitalize(this_player()->query_name())
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("maneater");
    set_alias("scythe");
    set_short("ManEater, the Scythe");
    set_long(
"As you gaze upon this weapon of destruction, your eyes are drawn to its\n"+
"1.5 meter curved blade. Writhing images dance across the shining black\n"+
"metal. You realize the distorted figures are humans, screaming in agony.\n"+
"You are drawn closer to the blade, then withdraw with an unnamed fear.\n");
    set_class(15);
    set_weight(6);
    set_value(2000);
    set_hit_func(this_object());
set_save_flag(0);
}
weapon_hit() {
int W;
    W = random(30);
  if(W < TPS)  {
  say(TPN+
" swings "+GEN+" scythe through "+MEATN+" in a massive display of strength!\n");
  write(
"You swing your scythe through "+MEATN+" in a massive display of strength!\n");
    if(MEAT->query_race() == "man" || MEAT->query_race() == "human") {
man_hit();
    }
return TPS/5;
   }
       return;
}
 
man_hit() {
  say(TPN+"'s scythe glows in a sickly red aura!\n");
  write("Your scythe glows in a sickly red aura!\n");
call_other(MEAT,"heal_self",-(TPS/2));
return 1;
}

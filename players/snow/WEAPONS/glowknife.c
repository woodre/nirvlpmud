/*
The glowknife casts light and hurts creatures of the darkness.
*/
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define MRACE MEAT->query_race()
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("glowing knife");
    set_alias("knife");
    set_short("A glowing knife");
   set_type("dagger");
    set_long("The soft glow of this knife warms your heart.\n");
    set_class(12);
    set_weight(1);
    set_light(1);
    set_value(500);
    set_hit_func(this_object());
}
weapon_hit() {
  int W,dam;
    dam = random(10)+5;
    W = random(20);
  if(W > 12)  {
    if(MRACE == "shadowcreature" || MRACE == "demon" ||
       MRACE == "devil" || MRACE == "daemon" ||
       MRACE == "shadow" || MRACE == "spirit" || MRACE == "undead" ||
       MRACE == "ghost") {
  if(!MEAT->query_npc()) return 7;
  say(TPN+"'s knife burns a glowing trail across "+MEATN+"!\n");
  write("Your glowing knife burns a glowing trail across "+MEATN+"!\n");
  if(dam > MEAT->query_hp()) dam = MEAT->query_hp() -1;
   call_other(MEAT,"hit_player",dam);
   }
  return 2;
  }
       return;
}

quest_ob() { return 1; }

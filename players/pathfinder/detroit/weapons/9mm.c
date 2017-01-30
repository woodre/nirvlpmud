inherit "obj/weapon.c";
int shots;
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("pistol");
   set_alias("beretta");
   set_short("9mm Beretta Pistol");
   set_long("A 9mm Beretta Pistol.  A sleek black weapon.\n");
   set_class(7);
   set_weight(2);
   set_value(3000);
    set_hit_func(this_object());
}
 
weapon_hit(attacker) {
int W,i,j;
    W = random(45);
   if(W < 15) {
   if(shots > 0) {
     write("You pull the trigger several times and hit the bastard!\n");
     say("The Beretta slams several slugs into the beast!\n");
    j = random(5) + 2;
   if(shots < j) {
      j = shots;
       shots = 0;
       i = j * (random(3) + 1);
     write("You hear the bolt lock back as you realize you are out of ammo!\n");
     say(capitalize(this_player()->query_name())+" runs out of ammo!\n");
       return i;
      } else {
       shots = shots - j;
       i = j * (random(3) + 1);
      return i;
      }
    } else {
     write("You are out of Ammo!\n");
    return;
    }
     } else {shots = shots - 1; return 1; }
}

load() {
  shots = 16;
  }

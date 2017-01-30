inherit "obj/weapon.c";
int shots;
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("uzi");
   set_short("9mm Uzi");
   set_long("A fully automatic Uzi locked cocked and ready to rock!\n");
   set_class(10);
   set_weight(4);
   set_value(3000);
    set_hit_func(this_object());
}
 
weapon_hit(attacker) {
int W,i,j;
    W = random(45);
   if(W < 15) {
   if(shots > 0) {
     write("You slap the selector on Full auto and rock and roll!\n");
     say("The Uzi goes on full auto and rips its opponent to shreds!\n");
    j = random(4) + 2;
   if(shots < j) {
      j = shots;
       shots = 0;
       i = j * (random(3) + 1);
       return i;
      } else {
       shots = shots - j;
       i = j * (random(3) + 1);
      return i;
      }
    } else {
     write("You hear the bolt lock kick in as you realize your ammo runs out!\n");
     say(this_player()->query_cap_name()+" runs out of ammo!\n");
    return;
    }
    } else { shots -= 1; return 1; }
}

load() {
  shots = 30;
  }

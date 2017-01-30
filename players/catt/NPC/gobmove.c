#include "living.h"
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
if(arg) return;
  set_heart_beat(1);
name = "goblin";
  cap_name = "goblin";
msgin = "slinks up to you";
  msgout = "leaves";
  max_hp = 100;
  hit_point = 100;
  level = 5;
  experience = 3383;
  weapon_class = 7;
  armor_class = 5;
  alignment = -200;
  is_npc = 1;
  enable_commands();
weapon();
}
short() { return "roving goblin"; }
long() {
        write("A roving goblin. He looks at you very warily.\n");
        }
id(str) { return str == name; }
random_move() {
  int n;
  n = random(6);
   if(n == 0)
    command("west");
   if(n == 1)
    command("east");
   if(n == 2)
    command("north");
   if(n == 3)
    command("south");
   if(n == 4)
    command("up");
   if(n == 5)
    command("down");
  }

weapon() {
object weapon;
   weapon = clone_object(WPN+"goblinaxe");
 move_object(weapon, this_object());
 command("wield axe");
}
heart_beat()
{
  age += 1;
  attack();
  if(random(5) == 0) random_move();
}

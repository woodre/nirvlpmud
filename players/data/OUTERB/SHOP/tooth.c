inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("A old Tooth");
set_alias("tooth");
set_short("A old Tooth");
set_long(
  "A broken tooth that belonged to some monster, it may be useful if \n"+
  "you try to 'wield' this weapon.\n"); 

set_type("knife");  /*  sword/knife/club/axe/bow/polearm  */

set_class(8);
set_weight(3);
set_value(500);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>8)  {
  say(
  "Stabs his foe with the old tooth, but it barely flinches.\n");

  write(
  "You stab your foe with the old tooth, but it laughs at your attack. \n");
  return 0;
   }
return;
}


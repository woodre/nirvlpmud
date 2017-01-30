/*  A Colt 45 Revolver */

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("revolver");
  set_alias("colt");
set_alt_name("gun");
set_short("A Colt .45 cal revolver");
set_long(
	"  This simple and rugged revolver was designed for long and hard \n"+
	"use by Samuel Colt in 1835 and patented a year later.  The notches\n"+
	"in the hand grip indicate it is a lethal weapon. \n");
set_type("bow");
  set_class(17);
  set_weight(1);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>10)  {
  say("\nThe big handgun fires...... \n\n"+
	"       POW  \n\n"+
	"                POW......POW  \n\n"+
	"                                 POW \n\n");

  write("\nYour wrist jerks back as the big handgun fires... \n\n"+
	"        POW \n\n"+
	"                  POW.......POW \n\n"+
	"                                     POW \n\n");
  return 4;
   }
return;
}

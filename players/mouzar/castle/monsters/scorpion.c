inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("scorpion");
set_short("A deadly scorpion");
set_long("A vicious scorpion has a green carapace and yellowish green legs and pincers.\n"+  
         "It's segmented tail is black, with a vicious stinger on the end.  There is a\n"+
         "bittter smell asssociated with the it, which probably comes from the venom.\n");
set_al(0);
set_level(19);
set_wc(28);
set_ac(16);
set_hp(475);
set_aggressive(1);
if(!present("stinger")) {
weapon = clone_object("players/mouzar/castle/weapons/stinger.c");
move_object(weapon,this_object());
}
}
 

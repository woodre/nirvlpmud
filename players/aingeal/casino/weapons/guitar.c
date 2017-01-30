/* Elvis's guitar */

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("guitar");
    set_alias("gibson");
    set_short("A Gibson J-200 acoustic guitar");
    set_long("This maple and rosewood acoustic guitar has gold tuners and an\n"+
		    "antique natural lacquer finish complete with mother of pearl\n"+
		    "accents on the fingerboard.  The guitar appears to have a \n"+
		    "name inscribed upon it.  It is well cared for and quite sturdy.\n");
    set_read("It reads  <<< Elvis Presley >>>\n");
    set_class(18);
    set_weight(2);
    set_value(1200);
    set_hit_func(this_object());
}

/* Random special attack */

weapon_hit(attacker){
int g;
g = random(10);
if(g > 8)  {
  write("The Gibson sails through the air to smash solidly\n"+
		  "into its foe with a sickening *THUNK*!\n");
  say("The Gibson sails through the air to smash solidly\n"+
		  "into its foe with a sickening *THUNK*!\n");
return 8;

    }
    return 8;
}


#include <ansi.h>
#define tp this_player()->query_name()
#define POSS this_player()->query_possessive()
#define TARG attacker->query_name()

int a, w;

inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
set_name("flamesword");
set_alias("flame sword");
set_type("sword");
set_short(RED+"Flaming "+WHT+"broadsword"+NORM);
set_long("The wide blade of the flaming sword can easily slice through the\n"+
         "of nearly anything, and the flame running along its edge gives\n"+
         "extra damage to what it strikes.\n");
set_class(18);
set_weight(2);
set_value(3750);
set_hit_func(this_object());
}

weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "wil") > random (60)) {
a = random(3);
  if(a == 0){
write("\nYou step into and slash "+TARG+" with the "+RED+"Flaming "+WHT+"broadsword"+NORM+".\n");
write(TARG+" doubles over in pain, screaming that his body is "+HIR+"aflame"+NORM+"!\n\n");
say(tp+" slashes at the "+TARG+" with the "+RED+"Flaming "+WHT+"broadsword"+NORM+".\n");
return 5;
}
if(a == 1){
write("\nYou instictivly hold the "+RED+"Flaming"+WHT+" broadsword "+NORM+"and intone:\n");
write(HIR+"\n         UGATH SU BEL'DRITH"+NORM+"\n\n");
write(TARG+" is shrouded in a cloud of fire and brimstone!\n\n");
return(random(20));
}
if(a == 2){
write("\nYou spin the "+RED+"Flaming"+WHT+" broadsword "+NORM+" high over your head\n");
write("You chop down with the sword and gash the "+TARG+" deeply.\n");
say(tp+" leaps into the air and chops down at "+TARG+" with the "+RED+"Flaming"+WHT+" broadsword "+NORM+"!\n");
return 5; 
}
        }
    return;
        }

query_save_flag()  { return 1; }

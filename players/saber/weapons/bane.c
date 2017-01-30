#include <ansi.h>

#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("sword of banishment");
    set_alias("sword");
    set_type("sword");         /* set type added by Pavlik */
    set_short("The "+HIK+"B"+NORM+"road"+HIK+"S"+NORM+"word of "+HIK+"BANISHMENT"+NORM);
     set_long("A wicked looking broadsword covered with golden runes.\n"+
     "The sword gives you a feeling of great power.\n");
    set_class(19);
     set_read("This sword enchanted by the servants of Arate.\n"+
     "Have a nice life untill this sword claims your soul.\n");
    set_weight(3);
    set_value(2000);
    set_hit_func(this_object());
  call_out("glow_glow", random(500));
}
weapon_hit(attacker){
 if(call_other(this_player(), "query_attrib", "str") > random(100)) {
say("The Broadsword of Banishment splatters gore across the chamber\n"+
   "as it slices through its foe.\n");
write("You feel the sword tug at your soul.\n");
write("The Broadsword of Banishment splatters gore across the chamber\n"+
    "as it slices through your foe.\n");
call_other(this_player(), "add_exp", - random(35)*this_player()->query_level());
return 16;
    }
    return;
}

query_save_flag() { if(broke) return 1; return 0; } /* broke check added by wocket */

glow_glow()  {
say("The runes on the broadsword glow an evil purple.\n"+
        "You feel a tug at your soul.\n");
  call_out("glow_glow", random(1000));
  return 1;
        }

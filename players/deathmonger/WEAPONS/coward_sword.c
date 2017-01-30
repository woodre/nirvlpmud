
inherit "obj/weapon";

my_init(){
if(this_object()->query_wielded() == 1){
add_action("drop","drop");
add_action("drop","give");
add_action("drop","sell");
add_action("drop","xsell");
add_action("drop","unwield");
}
}
reset(arg){
set_name("sword of destruction");
set_alias("sword");
set_class(18);
set_short("The Sword of Utter Monster Destruction");
set_long("Forged when the world was young, the Sword is unique in\n"+
     "every way.  The finest quality steel, the most brilliant \n"+
     "jewels...this Sword is magnificent.\n");
set_weight(3);
set_value(2000);
set_hit_func(this_object());
set_wield_func(this_object());
}
weapon_hit(attacker){
     write("Suddenly an uncontrollable fear comes over you!\n");
     this_player()->run_away();
     return 1;
}
wield(weap){
     write("The Sword become fused to your hand, undroppable.\n");
     return 1;
}
drop(){
     write("The Sword is fused with your hand!\n");
     return 0;
     }
}
}

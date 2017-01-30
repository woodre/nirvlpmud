#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
#include <ansi.h>
 reset(arg) {
    ::reset(arg);
    if (arg) return;
set_name("semper paratus");
set_alias("shank");
set_alias("semper");
set_alias("paratus");
set_type("knife");

set_short(""+RED+"Semper Paratus"+NORM+"");
set_long("While still a shank, this knife appears to be forged with careful craftsmanship.\n"+
"Semper Paratus, or always ready, rewards the agile generously .\n");
set_class(15);
 set_weight(1);
    set_value(1000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
 if(call_other(this_player(), "query_attrib", "dex") > random(45)) {
say("Semper Paratus springs forward, cutting straight and true,\n"+
 "it's user is emboldened both physically and spiritually.\n"+
tp+" looks inspired.\n");
write("Semper Paratus works so capably you are inspired to fight harder, \n"+
 "pushing through both physical and mental fatigue.\n"+
"You feel more capable.\n");
call_other(this_player(),"heal_self",4);
return 4;
    }
    return;
}

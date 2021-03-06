inherit "/obj/weapon.c";
#include "/players/jenny/define.h"
object ob;
int x;
int close;
int gotcha;
reset(arg) {
    if(arg) return;
    set_name("bow and arrow");
    set_alias("bow");
set_type("bow");
set_save_flag(1);
    set_short(CYN+"-----> "+RED+"Bow and Arrow "+CYN+"<-----"+NORM);  
    set_long(
     "This is a compound bow and arrow that rightfully belongs to Bo and Luke\n"+
     "Duke.  They can't carry guns, on the count of their probation, so they\n"+
     "use this.  This weapon is even more useful with dynamite tipped arrows.\n");

set_hit_func(this_object());
set_class(16);
set_value(1100);
set_weight(3);
}
init() { 
::init();
}

weapon_hit(attacker) {
ob = TP->query_attack();
x = random(31);
gotcha = 6+random(8);
close = 3+random(4);

if(x < 6 && ob->query_hp() > close) {
say(YEL+""+TPN+" shoots a dynamite tipped arrow at "+ob->query_name()+".\n"+
"\n"+
""+WHT+"It flies through the air.\n"+
"\n"+
""+CYN+"       <------\n"+
"\n"+
""+RED+"The arrow lands close to "+ob->query_name()+" and EXPLODES."+NORM+"\n");
write(YEL+"You shoot a dynamite tipped arrow at "+ob->query_name()+"."+NORM+"\n"+
"\n"+
""+WHT+"It flies through the air.\n"+
"\n"+
""+CYN+"       <------\n"+
"\n"+
""+RED+"The arrow lands close to "+ob->query_name()+" and EXPLODES."+NORM+"\n");
ob->hit_player(close);  
return 1; }

if(x > 28 && TP->query_attrib("wil") > random(20) && ob->query_hp() > gotcha) {
say(YEL+""+TPN+" shoots a dynamite tipped arrow at "+ob->query_name()+".\n"+
"\n"+
""+WHT+"It flies through the air.\n"+
"\n"+
""+CYN+"       <------\n"+
"\n"+
""+WHT+"The arrow sticks into "+ob->query_name()+"'s chest and "+RED+"EXPLODES!"+NORM+"\n"+
"\n");
write(YEL+"You shoot a dynamite tipped arrow at "+ob->query_name()+"."+NORM+"\n"+
"\n"+
""+WHT+"It flies through the air.\n"+
"\n"+
""+CYN+"       <------\n"+
"\n"+
""+WHT+"The arrow sticks into "+ob->query_name()+"'s chest and "+RED+"EXPLODES!\n"+
"\n"+

"                                             "+YEL+"+   +  +  +  +  +"+RED+"\n"+
"        ###############################       "+YEL+"+  + +   +   + "+RED+"\n"+
"       #                            #  #       "+YEL+"+ + + +  + + +"+RED+"\n"+
"       #                           # ========================\n"+
"       #                            #  #      "+YEL+"+   + +  + + +"+RED+"\n"+
"        ###############################       "+YEL+"+ + +   ++ +  +\n"+
"                                            +   +  +  +  + "+NORM+"\n");
tell_object(ob,
"                                             "+YEL+"+   +  +  +  +  +"+RED+"\n"+
"        ###############################       "+YEL+"+  + +   +   + "+RED+"\n"+
"       #                            #  #       "+YEL+"+ + + +  + + +"+RED+"\n"+
"       #                           # ========================\n"+
"       #                            #  #      "+YEL+"+   + +  + + +"+RED+"\n"+
"        ###############################       "+YEL+"+ + +   ++ +  +\n"+
"                                            +   +  +  +  + "+NORM+"\n");

ob->hit_player(gotcha);  
return 1; }
}

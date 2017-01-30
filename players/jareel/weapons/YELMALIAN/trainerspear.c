#include "/players/jareel/ansi.h"
inherit "/obj/weapon";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

  reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("yelmalian sun spear");
    set_id("spear");
    set_alias("sun spear");
    set_short(HIY+"Y"+NORM+BOLD+"elmalian "+HIY+"S"+NORM+BOLD+"un "+HIY+"S"+NORM+BOLD+"pear"+NORM);
    set_long("This finely crafted spear was forged in the heat of the yelmalian\n"+
      "blast furnaces, that are powererd with yelmalian solar magiks.  Its golden\n"+
      "glow from the spears tip strikes fear in the hearts of evil.\n");
    set_class(20);
    set_weight(1);
    set_type("spear");
    set_value(500);
    set_light(1);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(5);
if(i==1){
       tell_room(environment(USER),
""+BOLD+"The Yelmalian light spear  unleashes itself...."+NORM+"\n"+
"\n");

       tell_room(environment(USER),
"                                                       "+BOLD+HIY+" ,___  ____"+NORM+"\n"+
"            "+YEL+".__________________    ______________    "+BOLD+HIY+"__/   /__\\  '\\"+NORM+"\n"); 

tell_room(environment(USER),
"            "+YEL+"||_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\\\"+NORM+YEL+"________"+MAG+"|==|"+YEL+
"__"+HIY+"\\"+NORM+YEL+"__"+HIY+"\\"+NORM+"");
tell_room(environment(USER),
""+YEL+"__"+HIY+"\\"+NORM+YEL+"_____"+MAG+"|==|"+BOLD+HIY+"__ "+RED+"---"+HIY+"___"+RED+"  --"+BOLD+HIY+" >"+NORM+"     \n");

tell_room(environment(USER),
"                                                       "+BOLD+HIY+"\\___\\  /__,/"+NORM+" \n"+
"\n");

tell_room(environment(USER),
"\n"+
"\n");

tell_room(environment(USER),
""+BOLD+"                                                 .........Solar energy burns flesh"+NORM+"\n"); 
return 8;
}
}

#include "/players/wocket/closed/ansi.h"
#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
#define EN environment(this_object())
#define ME capitalize(environment(this_object())->query_name())
#define IT capitalize(environment(this_object())->query_attack()->query_name())
#define GUILDID "mageobj"
#define BONUS_TYPE "power"
#define BONUS_AMOUNT 3 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name(""+YEL+"Staff"+NORM+" of "+HIB+"Spell"+HIC+"power"+NORM+"");
    set_alias("staff");
    set_type("staff");
    message_hit = ({
        BOLD+""+HIB+"SLAMMED"+NORM," in the chest with with "+HIB+"MAGICAL ENERGY"+NORM+"",
        BOLD+""+HIC+"BASHED"+NORM," in the throat with the "+YEL+"Staff"+NORM+" of "+HIB+"Spell"+HIC+"power"+NORM+"",
        BOLD+""+BLU+"CRUSHED"+NORM," on the head with a great impact",           
        BOLD+""+HIR+"CRACKED"+NORM," with the staff",
        BOLD+""+HIY+"CLUBED"+NORM," in the legs",
        BOLD+""+HIM+"BEAT"+NORM," on the arm",
        BOLD+"GRAZED"+NORM," with the staff"
        });
     set_short(""+YEL+"Staff"+NORM+" of "+HIB+"Spell"+HIC+"power"+NORM+"");
     set_long("  This long slender "+YEL+"staff"+NORM+" is made from "+HIY+""+BLK+"ironwood"+NORM+" and wrapped in "+CYN+"mythril"+NORM+".\n"+
              "It "+HIC+"PUL"+HIB+"SES"+NORM+" in your hands and calls out to users of the "+HIB+"arcane craft"+NORM+". The\n"+
              ""+NORM+""+YEL+"staff"+NORM+" has a "+HIC+"+3 weapon enhancement"+NORM+" bonus.\n");
    set_class(18);
    set_params("other|magic",1,0);
    set_weight(3);
    set_value(20000);
    set_hit_func(this_object());
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}
remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->remove_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

weapon_hit(attacker){
 if(call_other(this_player(), "query_attrib", "int") > random(80)) {
say("The staff glows brightly\n"+
    ""+HIB+"########################################################\n"+
    "#######################"+HIC+"POWER DRAIN!"+HIB+"#####################\n"+
"########################################################"+NORM+"\n");
   say("The spell staff seems to heal "+tp+" mentally.\n");
write("The staff glows brightly\n"+
    ""+HIB+"########################################################\n"+
    "#######################"+HIC+"POWER DRAIN!"+HIB+"#####################\n"+
    "########################################################"+NORM+"\n"+
    "The spell staff seems to heal you mentally.\n");
call_other(this_player(),"add_spell_point",6);
return 4;
    }
    return 0;
}

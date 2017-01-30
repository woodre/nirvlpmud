#include <ansi.h>
inherit "players/pavlik/armor/armor";
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "strength"
#define BONUS_AMOUNT 2

reset(arg){
 if(arg) return;
 ::reset(arg);
 set_short("Storm Shield");
 set_long(
 "A blazing sheet of lightning-forged metal.  Kreeg's Storm Shield is an\n"+
 "armor of incalculable worth.\n");
 set_ac(2);
 set_weight(2);
 set_value(50000);
 set_alias("storm shield");
 set_name("the Storm Shield");
 set_type("shield");
 set_params("other|electric", 3, 10, "do_elec_special");
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus() {
  if(present(GUILD_ID, this_player()))
        present(GUILD_ID,this_player())->add_pow_bonus(BONUS_AMOUNT);
}

remove_guild_bonus() {
  if(present(GUILD_ID, this_player()))
        present(GUILD_ID, this_player())->add_pow_bonus(-BONUS_AMOUNT);
}

do_elec_special(owner)
{
  if(!random(8))
    tell_object(owner, "Your "+query_name()+" absorbs some of the "+HIY+"Electricity"+NORM+"!\n");
}

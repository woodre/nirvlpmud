inherit "players/pavlik/armor/armor";
#include "/open/ansi.h"
#define GUILD_ID "pavlik_guild_obj"
#define BONUS_TYPE "strength"
#define BONUS_AMOUNT 2

reset(arg){
 ::reset(arg);
  set_short(BLU+"S"+BOLD+BLK+"torm "+NORM+BLU+"S"+BOLD+BLK+"hield"+NORM);
 set_long(
 "A blazing sheet of lightning-forged metal.  Kreeg's Storm Shield is an\n"+
 "armor of incalculable worth.\n");
 set_ac(2);
 set_weight(2);
 set_value(50000);
 set_alias("storm shield");
 set_name("the Storm Shield");
 set_type("shield");
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus() {
  if(present(GUILD_ID, this_player()))
        present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus() {
  if(present(GUILD_ID, this_player()))
        present(GUILD_ID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}


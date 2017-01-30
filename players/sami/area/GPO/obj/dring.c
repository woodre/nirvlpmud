inherit "/obj/armor";
#include "/obj/ansi.h"
#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_AMOUNT 3

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("earring");
  set_alias("ring_1");
  set_short(""+HIG+"M"+HIK+"ikal's"+NORM+" earring");
  set_long("A ring seeming to be made of Jade and set with a bloodstone.");

  set_params("other|dark",0,3,0);
  set_params("other|evil",0,3,0);
  set_ac(1);
  set_type("earring");
  set_weight(1);
  set_value(3000);
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
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}

init() {
  ::init();
  add_action("read_inscription","read");
  }
  read_inscription(str) {
  if(!str) return 0;
  if(str == "earring" || str == "inscription")  {
  write("**********~~~~~~~~~Ring of Darkness~~~~~~~~~~~~~~~**********\n");
  write("This ring has been forged from liquid hatred, and hardened by\n"+
        "the darkness which it protects its wearer from.\n");
  write("**********~~~~~~~~~Ring of Darkness~~~~~~~~~~~~~~~~**********\n");
return 1; } }
do_special(owner)
{
        if(!worn) 
        {
                return; 
        }
        
    if(owner->query_level() > 10)
    {
            int X;
        X=random(100);
        if (X <15)
        {
                tell_object(owner, "The"+HIK+" Shadows "+NORM+"expand and you feel "+HIR+"Healthier"+NORM+"\n");
                        owner->add_spell_point(random(10));
        }
        }
        
        else
        {
                return;
        }
}
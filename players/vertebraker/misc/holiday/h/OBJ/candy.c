/* candy distributed for trick or treat */

#include "../std.h"
inherit ITEM;
int heal;

set_name(str)
{
   set_id(str);
}

reset(x)
{
   if(x) return;
   pick_candy_type();
   if(!random(10)) heal = 1;
   set_long("A scrumdidlyumptious "+CAP(name)+".\n");
   set_value(0);
   set_weight(0);
}

init()
{
   ::init();
   add_action("cmd_eat","eat");
}

cmd_eat(str)
{
   if(id(str))
      {
      write("  You quickly gulp down "+short()+".\n");
      say(TPN+" munches on "+short()+".\n");
      if(heal) TP->heal_self(1+random(2));
      destruct(TO);
      return 1;
   }
}

pick_candy_type()
{
   switch(random(10))
   {
      case 0:
      set_name("krackle");
      set_alias("bar");
      set_short(BRED+HIW+"A Krackle Bar"+NORM);
      break;
      case 1:
      set_name("peanut butter cup");
      set_alias("cup");
      set_short(BYEL+HIY+"A Peanut Butter Cup"+NORM);
      break;
      case 2:
      set_name("smarties");
      set_alias("pack");
      set_short("A pack of "+HIY+"S"+HIM+"m"+HIC+"a"+HIG+"r"+HIM+"t"+HIG+"i"+HIY+"e"+HIC+"s"+NORM);
      break;
      case 3:
      set_name("sweettarts");
      set_alias("pack");
      set_short("A pack of "+BGRN+HIM+"Sweet"+HIC+"Tarts"+NORM);
      break;
      case 4:
      set_name("chocolate bar");
      set_alias("bar");
      set_short("A "+BOLD+BLK+"chocolate"+NORM+" bar");
      break;
      case 5:
      set_name("chocolate kiss");
      set_alias("kiss");
      set_short("A "+BOLD+BLK+"wrapped chocolate kiss"+NORM);
      break;
      case 6:
      set_name("butterscotch");
      set_alias("candy");
      set_short(YEL+"A piece of butterscotch candy"+NORM);
      break;
      case 7:
      set_name("caramel");
      set_alias("caramel cream");
      set_short(YEL+"A c"+HIW+"ara"+NORM+YEL+"mel cre"+HIW+"am"+NORM);
      break;
      case 8:
      set_name("almond joy");
      set_alias("joy");
      set_short(BOLD+BLU+"An Almond Joy"+NORM);
      break;
      case 9:
      set_name("candy corn");
      set_alias("corn");
      set_short("A pack of "+HIR+"candy c"+HIY+"or"+HIW+"n"+NORM);
      break;
   }
}

id(str)
{
   return str == name || str == alias_name || str == "candy";
}

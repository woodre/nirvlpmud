inherit "obj/armor";
#include "/players/pavlik/closed/colors.h"

/*
 * Stone Armor:
 * armor class: 6      type: armor
 * restrictions: the player cannot wear any other armor except
 * type ring and misc while this armor is being worn.  This armor is also
 * quite heavy.  The object is storable at times.
 * verte: cleaned up code.
 * made savable since can't wear additional armor.
 *
 * from: ~/monsters/ilstkarn/basalisk
 */

reset(arg){
 ::reset(arg);
 if(arg) return;
 set_short("a Stone Hide");
 set_long(
 "This is the rock-hard hide of a slain Basalisk.  The stone shell\n"+
 "is the perfect sculpture of the deadly beast.  The hide is immensely\n"+
 "heavy, but if you were able to wear it about your shoulders it would\n"+
 "provide unparralled protection.\n");
 set_name("the Basalisk's Hide");
 set_ac(6);
 set_weight(7);
 set_value(5000);
 set_alias("hide");
 set_arm_light(0);
 set_type("armor");
}

stone_type(str) {
  return str == "armor" || str == "helmet" || str == "boots" ||
  str == "amulet" || str == "shield";
}

wear(str)
{
  if(environment() == this_player() && id(str) && !worn)
  {
    object ob, oc;
    ob = first_inventory(environment());
    while(ob)
    {
      oc = next_inventory(ob);
      if(stone_type(ob->query_type()) && ob->query_worn())
     {
        write("You cannot wear "+query_name()+" whiel "+ob->query_name()+" is equipped.\n");
        return 1;
      }
      ob = oc;
     }
  }
  return ::wear(str);
}

id(str)
{
  object c;
  if(c && (c->query_type()=="armor"||c->query_type()=="helmet"||
         c->query_type()=="boots"||c->query_type()=="amulet"||
       c->query_type()=="shield")
     && c->is_armor())
    return (::id(str) || str=="notarmor");
  return ::id(str);
}

display_notarmor_msg()
{
  write("You cannot wear "+previous_object()->query_name()+" while "+query_name()+" is equipped.\n");
  return 1;
}

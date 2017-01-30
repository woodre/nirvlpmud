#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()
#define SEX tp->query_possessive()

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("cat o nine tails");
  set_alias("whip");
  set_short("Cat 'o nine tails");
   set_long("A large double headed purple dildo, this item has brought pleasure\n"+
            "to countless women in need. However, in your hands, it becomes a\n"+
            "deadly weapon, able to bring down armies. Just make sure you \n"+
            "clean it afterwards...\n"+
            "type: "+MAG+"dildo_power"+NORM+" for a list of commands this weapon gives you.\n");

  set_class(15);
  set_weight(1);
  set_value(450);
  set_hit_func(this_object());
}

query_save_flag() { return 0; }

weapon_hit(attacker){
  if(tp->query_attrib("wil") > random(35)) {
   write("You smash you foe over the head with your "+MAG+"dildo"+NORM+"\n");
  return 7; }
   return;
}


#include <ansi.h>
#define tpn this_player()->query_name()
#define ATT USER->query_attack()
#define ME TP->query_possessive()
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define MEE TP->query_objective()
inherit "/obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("pure evil");
  set_alias("evil");
  set_short(""+HIR+"P"+HIK+"U"+HIR+"R"+HIK+"E "+HIR+"E"+HIK+"V"+HIR+"I"+HIK+"L"+NORM+"");
  set_long(
      "There is no words to describe this horrible device. It appears to link with\n"+
      "Your brain via the Central Nervous System. Its powers are unknown.\n");
   set_weight(4);
   set_class(20);
   set_value(3500);
   set_type("staff");
  message_hit = ({
    HIR+"flayed"+NORM," central nervous system",
    HIY+"ripped"+NORM," mind in twain",
    HIG+"sliced"+NORM," brain into bits",           
    RED+"hit"+NORM," as mental walls start to break",
    YEL+"clipped"+NORM," in the skull",
    GRN+"hacked"+NORM," in the gut",
    BOLD+"poked"+NORM," annoying them"
  });
  set_hit_func(this_object());
}
init() {
   ::init();
}
weapon_hit(attacker) {
  int dam;
  string *message;
  int i, times;
  string tname;

  if(!attacker) return 0;
  if(!TP || TPRN == "Vark") return 0;
  times = 1+random(2);
  while(attacker && times--) {
    tname = (string)attacker->query_name();
    if (!tname) tname = "your target";
    dam = (int)attacker->hit_player(random(class_of_weapon), "other|evil, other|mental");
    message = query_message_hit(dam);
    write("You "+message[1]+" "+tname+message[0]+".\n");
    say((string)this_player()->query_name()+" "+message[1]+" "+tname+message[0]+".\n");
  }
  return 1+times;
}
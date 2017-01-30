/* The code of this thing turned into a tangled mess.  See stick.2011.6.18.c */
#include "/players/jenny/define.h"
#define ME TP->query_possessive()
#define MEE TP->query_objective()
inherit "/obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("necro_tool");
  set_alias("stick");
  set_short("A Copy of a Hockey Stick");
  set_long(
      "This is a very old hockey stick.  It is made of wood, and is a little heavy.\n"+
      "The word 'LOUISVILLE' is written on the shaft in bold letters.  This stick\n"+
      "belongs to Gordie Howe, and helped him score 801 career goals in the NHL.\n");
   set_weight(4);
   set_class(20);
   set_value(3500);
   set_type("blade");
  message_hit = ({
    BOLD+"speared"+NORM," in the eye",
    BOLD+"wacked"+NORM," in the throat",
    BOLD+"chopped"+NORM," over the head",           
    BOLD+"slashed"+NORM," in the groin",
    BOLD+"butt ended"+NORM," in the ribs",
    BOLD+"hacked"+NORM," on the knee",
    BOLD+"slashed"+NORM," on the hand"
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
  if(!TP || TPRN == "Gordie Howe") return 0;
  if(random(100) > 75) hithim(attacker);
  times = 1+random(2);
  while(attacker && times--) {
    tname = (string)attacker->query_name();
    if (!tname) tname = "your target";
    dam = (int)attacker->hit_player(random(class_of_weapon), "physical");
    message = query_message_hit(dam);
    write("\t\t\tWH You "+message[1]+" "+tname+message[0]+".\n");
    say((string)this_player()->query_name()+" "+message[1]+" "+tname+message[0]+".\n");
  }
  return 1+times;
}

void hithim(object target) {
  int slapshot;
  object puck;
  slapshot = (random(30) + 80);
  if(!TP) return 0;
  puck = present("jennypuck",TP);
  if(!target || !puck) return;
  write("\nYou take a few steps back, drop a "+BLK+"puck "+NORM+"on the ground, and nail "+target->query_name()+"\nwith a "+slapshot+" mph slapshot.\n");
  say("\n"+TPN+" takes a few steps back, drops a "+BLK+"puck "+NORM+"on the ground, and nails "+target->query_name()+"\nwith a "+slapshot+" mph slapshot.\n");
  target->hit_player(10+random(6));
  transfer(puck,"/room/void");
  destruct(puck);
}

query_wear() {
  return 3*::query_wear()/4;
}

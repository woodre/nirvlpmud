inherit "obj/weapon.c";
#include "/players/pavlik/closed/colors.h"
#define TP this_player()

reset(arg) {
  ::reset();
  if (arg) return;
  set_name("long sword");
  set_alias("sword");
  set_short("A Long Sword");
  set_long(
  "A long well balanced blade.  This sword is perfect for\n"+
  "cutting deep into an enemy's body.  You can use 'swcolor'\n"+
  "to set the color of the sword's hit messages.\n");
  set_class(18);
  set_save_flag(0);
  set_weight(5);
  set_type("sword");
  set_value(2000);
  set_hit_func(this_object());
  message_hit = ({
        HIC+"BURY "+NORM+"the sword into ", "'s chest",
        HIC+"cut deeply"+NORM+" into", "'s body",
        HIC+"bashed"+NORM, " with the hilt of the sword",
        HIC+"hacked"+NORM, "",
        HIC+"sliced"+NORM, "",
        HIC+"struck"+NORM, " in the head",
        HIC+"nicked"+NORM, " with the sword tip",
  });
}

weapon_hit(attacker) {
  if(random(20) > 15) {
	tell_room(environment(this_player()),
	"Blood "+HIR+"flows"+NORM+" freely from "+capitalize(attacker->query_name())+
        "'s wounds.\n");
	return 7;
  }
}

init() {
  ::init();
  add_action("sword_color","swcolor");
}

sword_color(str) {
  string color;
  int ran_col;

  if(!str) ran_col = random(6) + 1;
  if(str == "white" || ran_col == 1) color = HIW;
  else if(str == "red" || ran_col == 2) color = HIR;
  else if(str == "blue" || ran_col == 3) color = HIB;
  else if(str == "yellow" || ran_col == 4) color = HIY;
  else if(str == "green" || ran_col == 5) color = HIG;
  else if(str == "magenta" || ran_col == 6) color = HIM;
  else if(str == "cyan" || ran_col == 7) color = HIC;
  else {
	write("Invalid color.\n");
	return 1;
  }
  message_hit = ({
        color+"BURY"+NORM+"the sword into ", "'s chest",
        color+"cut deeply"+NORM+" into", "'s body",
        color+"bashed"+NORM, " with the hilt of the sword",
        color+"hacked"+NORM, "",
        color+"sliced"+NORM, "",
        color+"struck"+NORM, " in the head",
        color+"nicked"+NORM, " with the sword tip",
  });
  write("Longsword's messages are now "+color+str+NORM+".\n");
  return 1;
}


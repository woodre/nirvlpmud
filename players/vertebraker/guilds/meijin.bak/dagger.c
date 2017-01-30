inherit "obj/weapon.c";
#include "/players/pavlik/closed/colors.h"
#define TP this_player()

reset(arg) {
  ::reset();
  if (arg) return;
  set_name("dagger");
  set_alias("dagger");
  set_short("A Dagger");
  set_long(
  "A narrow sharp blade.  This dagger is perfect for\n"+
  "piercing deep into an enemy's body.  You can use\n"+
  "'dagcolor' to set the color of the dagger's hit message.\n");
  set_class(18);
  set_save_flag(0);
  set_weight(5);
  set_type("dagger");
  set_value(2000);
  set_hit_func(this_object());
  message_hit = ({
        HIR+"plunged"+NORM+" the dagger "+RED+"deep"+NORM+" into", "'s heart",
        HIR+"stabbed"+NORM+" viscously into", "'s body",
        HIR+"gutted"+NORM, "",
        HIR+"gashed"+NORM, "",
        HIR+"sliced"+NORM, "",
        HIR+"scratched"+NORM, "",
        HIR+"pricked"+NORM, "",
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
  add_action("sword_color","dagcolor");
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
        color+"plunged"+NORM+" the dagger "+RED+"deep"+NORM+" into", "'s heart",
        color+"stabbed"+NORM+" viscously into", "'s body",
        color+"gutted"+NORM, "",
        color+"gashed"+NORM, "",
        color+"sliced"+NORM, "",
        color+"scratched"+NORM, "",
        color+"pricked"+NORM, "",
  });
  write("Longsword's messages are now "+color+str+NORM+".\n");
  return 1;
}


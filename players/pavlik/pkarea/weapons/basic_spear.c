inherit "players/pavlik/pkarea/lib/weapon.c";
#include "/players/pavlik/pkarea/lib/damage_types.h"
#include "/players/pavlik/closed/colors.h"
#define TP this_player()

reset(arg) {
  ::reset();
  if (arg) return;
  set_name("spear");
  set_alias("spear");
  set_short("A Barbed Spear");
  set_long(
  "You hold a 5 foot shaft of wood with a deadly barbed spearhead, perfect for\n"+
  "stabbing into an enemy's body.  You can use 'spcolor' to set the color of\n"+
  "the spear's attack messages.\n");
  set_class(0);
  set_save_flag(0);
  set_weight(2);
  set_type("spear");
  set_value(500);
  set_damage_type(PIERCE, 15);
  set_hit_func(this_object());
  message_hit = ({
        HIC+"BURY"+NORM+"the spear into ", "'s chest",
        HIC+"gouge"+NORM+" a chunk of flesh from", "' body",
        HIC+"bashed"+NORM, " soundly with the oak shaft",
        HIC+"stabbed"+NORM, " with the barbed spear",
        HIC+"pierced"+NORM, "",
        HIC+"whacked"+NORM, " with the solid oak shaft",
        HIC+"nicked"+NORM, " with the spear tip",
  });
}

/*
 * weapon_hit should always return an array, the array should simply be
 * empty of there is no bonus hit.
 */
weapon_hit(attacker) {
  int dmg;
  dmg = allocate(DAMAGE_TYPES);

  if(random(50) < 15) {
	dmg[PIERCE] = random(6);
  }
  return dmg;
}

init() {
  ::init();
  add_action("spear_color","spcolor");
}

spear_color(str) {
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
	write("Select from: white, red, blue, yellow, green, magenta, cyan\n");
	return 1;
  }
  message_hit = ({
        color+"BURY"+NORM+"the spear into ", "'s chest",
        color+"gouge"+NORM+" a chunk of flesh from", "' body",
        color+"bashed"+NORM, " soundly with the oak shaft",
        color+"stabbed"+NORM, " with the barbed spear",
        color+"pierced"+NORM, "",
        color+"whacked"+NORM, " with the solid oak shaft",
        color+"nicked"+NORM, " with the spear tip",
  });
  write("The spear's messages are now "+color+str+NORM+".\n");
  return 1;
}


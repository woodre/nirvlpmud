#include "/players/pavlik/closed/colors.h"
#define IT capitalize(attacker->query_name())
inherit "obj/weapon.c";

/*
 * This weapon is only usable by players with good alignment.
 */

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("Ice Wand");
  set_alt_name("wand");
  set_short("an "+HIB+"Ice Wand"+NORM);
  set_long("A short rod of silvery metal tipped with ivory.\n");
  set_type("staff");
  set_class(19);
  set_weight(1);
  set_value(500);
  message_hit = ({
    HIB+"FREEZE"+NORM,  " with a massive  "+HIB+"Cone of Cold"+NORM,
    BLU+"Chilled"+NORM, " with a "+BLU+"Sleet"+NORM+" spell",
    BLU+"Speared"+NORM, " with a volley of "+BLU+"Ice Daggers"+NORM,
    HIB+"Iced"+NORM,    " with an "+HIB+"Artic Blast"+NORM,
    "hit",              " with a "+HIB+"Sleet Storm"+NORM+" spell",
    "grazed",           " with a Frostbite spell",
    "showers",          " with the sparks of a fizzled spell",
  });
  set_save_flag(1);
  set_hit_func(this_object());
}

weapon_hit(attacker){
  int i, aln;

  aln = this_player()->query_alignment();
  i = random(50);

  if((aln < 0) && (i > call_other(this_player(), "query_attrib", "wil"))) {
    write("The wands cold metal causes "+HIB+"frostbite"+NORM+" on your fingers.\n");
    this_player()->hit_player(random(5));
    return 0;
  }
  if((aln > 0) && (call_other(this_player(), "query_attrib", "wil") > i)) {
    if(i < 2) {
      write(
      "A "+HIB+"Massive Hailstorm"+NORM+" erupts fromt he ivory wand!\n"+
      IT+" is ripped to pieces by a flurry of sharp-edged hail stones!\n");
      this_player()->add_spell_point(-5);
      return 3+random(5);
    }
    else {
      write(
      "An "+HIB+"Artic Blast"+NORM+" burts from the wand and freezes your\n"+
      "enemy "+BLU+"to the bone!"+NORM+"\n");
      return 3;
    }
  }

  if(random(5)==1)
	write("The ivory tipped wand hums powerfully in your hand.\n");
  else if(random(5)==3)
	write("Sparking ice crystals form on the silver metal of the Ice Wand.\n");
  else if(random(5)==4)
	write("A shiver runs down your arm as the Ice Wand gleams brilliantly.\n");

  return 1;
}


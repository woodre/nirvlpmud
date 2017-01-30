#include "std.h"

int OS;
object gold_stick, orc_slayer, shaman;

#undef EXTRA_RESET
#define EXTRA_RESET fix_shaman();

fix_shaman()
{
OS = 1;
    if (!shaman || !living(shaman)) {
  gold_stick = clone_object("obj/treasure");
  call_other(gold_stick, "set_id", "staff");
  call_other(gold_stick, "set_alias", "golden staff");
  call_other(gold_stick, "set_short", "A golden staff");
  call_other(gold_stick, "set_value", 300);
  shaman = clone_object("obj/monster.talk");
  call_other(shaman, "set_name", "shaman");
  call_other(shaman, "set_alias", "orc shaman");
  call_other(shaman, "set_race", "orc");
  call_other(shaman, "set_level", 10);
  call_other(shaman, "set_al", -300);
  call_other(shaman, "set_short", "An orc shaman");
  call_other(shaman, "set_wc", 10);
  call_other(shaman, "set_ac", 1);
  call_other(shaman, "set_aggressive", 1);
  call_other(shaman, "set_chance", 20);
  call_other(shaman, "set_spell_mess1",
      "You are hit by a magic missile");
  call_other(shaman, "set_spell_mess2",
      "The shaman casts an magic missile");
  call_other(shaman, "set_spell_dam", 20);
  move_object(shaman, this_object());
  move_object(gold_stick, shaman);
    }
}

#undef EXTRA_INIT
#define EXTRA_INIT\
  add_action("search", "search");

ONE_EXIT("room/fortress", "south",
   "The orc treasury",
   "You are in the orc treasury. It is normally heavily guarded.\n", 1)


search(str) {
if(present("shaman")) {
  write("The orc shaman pokes you in the chest with his staff and\n"+
  "says, 'This is ours, be gone with you!'\n");
  return 1; }
if(!str) { write("You search generally and find nothing.\n"); return 1; }
if(str != "treasury") {
  write("What is it you want to search?\n"); return 1; }
if(str == "treasury" && OS == 1) {
  write("You search the nooks and crannies of the orc treasury and\n"+
  "find an interesting sword safely tucked away.\n");

  orc_slayer = clone_object("obj/weapon.c");
  call_other(orc_slayer,"set_name","short sword");
  call_other(orc_slayer,"set_alias","sword");
  call_other(orc_slayer,"set_short","short sword");
  call_other(orc_slayer,"set_alt_name","orc slayer");
  call_other(orc_slayer,"set_long","This is a very fine blade.\n"+
  "It's covered with ancient runes.\n"+
  "Engraved on it is a picture of the\n"+
  "sword slicing an orc.\n");
  call_other(orc_slayer,"set_read","The only thing you can read is 'orc'\n");
  call_other(orc_slayer,"set_class",9);
  call_other(orc_slayer,"set_weight",2);
  call_other(orc_slayer,"set_value",200);
  move_object(orc_slayer,this_player());
  OS = 0;
  return 1; }
else {
  write("You search the nooks and crannies of the orc treasury and\n"+
  "find nothing but dusty shelves.\n");
  return 1; }
}

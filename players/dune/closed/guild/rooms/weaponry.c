inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
#include DEFS_WEAPONS
#include DEFS_COLORPAD



init() {
  add_action("register","register");
  add_action("select_weapon","select_weapon");
  add_action("change_weapon","change_weapon");
  add_action("show_weapons","show_weapons");
   add_action("name_weapon","name_weapon");
  add_action("links","links");
  add_action("buy_link","buy_link");
  ::init();
}

reset(arg){
  if(!present(WEAPON_NPC)) {
    move_object(clone_object(ROOMDIR + "/WeaponmasteR.c"),
    this_object());
  }

  if(!arg){
  set_light(1);
  short_desc=FUNKYNAME+" Weapons Shop";
  long_desc=
"     An impressive assembly both familiar and mysterious weapons\n"+
"hang upon the walls around you.  Some you have never seen before,\n"+
"and others you've seen all to many times.  A large desk and a small\n"+
"training area lie in the center of the room.\n"+
"Please type 'register' to list the services available to you.\n";

 items=({
"weapons", "Hundreds of weapons hang on bolts attached to the walls",
"walls","The walls are covered with hundreds of different weapons",
"desk","This is the central service desk",
"area","The training area is for your use any time of the day",
"training area","The training area is for your use any time of the day",
  });

  dest_dir=({
    ROOMDIR + "/shop.c", "west",
  });
  }
}


status register() {
  write(
  "Services available:\n\n"+
  "select_weapon <weapon>....Buy a brand new ninja weapon\n"+
  "                          --costs vary as per weapon type\n"+
  "change_weapon <weapon>....Change your ninja weapon to another\n"+
  "                          --costs xp and coins\n"+
  "show_weapons..............shows available weapons\n"+
  "name_weapon <name>........Give your weapon an original name\n"+
  "                          For color help, type 'name_weapon' by itself.\n"+
  "links.....................Describes SmartWeapon links\n");
  tell_room(TP, TPN+" registers "+TP->POS+" name.\n");
  return 1;
}

status select_weapon(string str) {
  if(!IPTP) return 0;
  if(!present(WEAPON_NPC, environment(TP))) {
    write("The weaponsmith is not present.\n");
    return 1; }
  if(!str) {
    write("Usage: select_weapon <weapon>.\n");
    return 1; 
  }
  write("You attempt to select the '"+str+"' weapon.\n");
  if(call_other(WEAPOND, "select_weapon", TP, str)) {
    write("WeaponMaster says: Ouch! Be careful with that thing!\n");
  }
  return 1;
}

status change_weapon(string str) {
  if(!IPTP) return 0;
  if(!present(WEAPON_NPC, environment(TP))) {
    write("The weaponsmith is not present.\n");
    return 1; }
  if(!str) {
    write("Usage: change_weapon <weapon>.\n");
    return 1; 
  }
  write("You attempt to change to the '"+str+"' weapon.\n");
  if(call_other(WEAPOND, "change_weapon", TP, str)) {
    write("WeaponMaster says: Ooo. Mighty fine weapon there.\n");
  }
  return 1;
}

status show_weapons() {
  if(!IPTP) return 0;
  call_other(WEAPOND, "list", TP);
  return 1;
}

status name_weapon(string str)
{
  string wepName;
  if(!IPTP) return 0;
  if(!present(WEAPON_NPC, environment(TP))) {
    write("The weaponsmith is not present.\n"); return 1; }
  if(!str) {
    write("Usage: name_weapon <name>.\n"+
          "Weapon naming supports color. Specify the following color\n"+
          "codes to give your weapon name some sparks:\n"+
          color_help()+
          "......example: name_weapon $HR$Red$C$Shark\n");
    return 1;
  }
  wepName = (string)call_other(WEAPOND, "name_weapon", TP, str);
  if (wepName)
  {
    write("Your weapon is now called: "+wepName+"\n");
    return 1;
  }
  else
    write("The weapon naming process has failed.\n");
  return 1;
}

status links() {
  if(!IPTP) return 0;
  write("--To order a SmartWeapon link, buy_link--\n");
  call_other(WEAPOND, "list_links", TP);
  return 1;
}

status buy_link() {
  int result;
  if(!IPTP) return 0;
  if(!present(WEAPON_NPC, environment(TP))) {
    write("The weaponsmith is not present.\n");
    return 1; }
  if(call_other(WEAPOND, "buy_link", TP) == 0) {
    write("Attempt to buy Smartweapon Link failed.\n");
  }
  else 
    write("WeaponMaster says: Har, har. That'll do ya just fine.\n");
  return 1;
}

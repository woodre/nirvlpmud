inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
#include DEFS_GLEVELS



init() {
  add_action("register",     "register");
  add_action("upgrade_list", "my_upgrades");
  add_action("set_brand",    "new_chip");
  add_action("brand_list",   "chips");
  add_action("fab_chip",     "fab_chip");
  ::init();
}

reset(arg)
{
  if(!present(FAB_NPC))
  {
    move_object(clone_object(ROOMDIR + "/TecH.c"),
    this_object());
  }

  if(!arg){
  set_light(1);
  short_desc=FUNKYNAME+" Chip Fabrication Facility";
  long_desc=
"     Large cilindrical vats thunder with a rythmic rumbling\n"+
"as air-cleaning engines and turbines purify the fab atmosphere.\n"+
"Neural microprocessors of all shapes, sizes, and functionality\n"+
"are carefully created in a myriad of acid baths, laser etching,\n"+
"xray exposure, and bio-quantam processes.\n"+
"Here is where you may have a new chip, of your own choosing,\n"+
"installed. Also, you may observe a list of same-quality chips,\n"+
"or a list of chip upgrades. Keep in mind only a \n"+
"Please 'register' for a list of commands.\n";

  items=({
"vats", "The exhaust vats spew water vapors into the atmosphere",
"microprocessors", "Several, but not hundreds, of chips rest in racks",
"engines", "The huge engines rumble overhead and beneath your feet",
"turbines", "The turbines hum softly, causing gusts of pure air",
  });

  dest_dir=({
    ROOMDIR + "/hallway1.c","west",
  });
  }
}


status register() {
  tell_object(TP,
"Services available:\n\n"+
"new_chip <brand> .... installs a new chip of your choosing\n"+
"my_upgrades ......... list of upgrades available to you\n"+
"chips ............... list of same-quality chips available to you\n");
  if(IPTP && IPTP->guild_lev() >= MAX_QUALITY_LEVEL)
  tell_object(TP,
"fab_chip ............ have the technician create a die set for you\n");
  tell_room(TP, TPN+" registers "+TP->POS+" name.\n");
  return 1;
}


status set_brand(string str) {
  string brand;
  if(!IPTP) return 0;
  if(!present(FAB_NPC, environment(TP))) {
    write("The technician is not present.\n");
    return 1; }
  if(!str) {
    write("\n~~~Available Chips~~~~\n");
    call_other(GLEVELD, "checkBrand", TP, (int)IPTP->guild_lev(), 0);
    write("~~~~~~~~~~~~~~~~~~~~~~\n");
    return 1;
  }
  if(!call_other(GLEVELD, "new_chip", TP, str))
    write("You have not selected a neural chip.\n");
  return 1;
}


status upgrade_list(string str) {
  string brand;
  if(!IPTP) return 0;
  if(!present(FAB_NPC, environment(TP))) {
    write("The technician is not present.\n");
    return 1; }
  write("\n~~Available Upgrades~~\n");
  call_other(GLEVELD, "checkBrand", TP, ((int)IPTP->guild_lev())+1, 0);
  write("~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}


status brand_list() {
  if(!IPTP) return 0;
  if(!present(FAB_NPC, environment(TP))) {
    write("The technician is not present.\n");
    return 1; }
  if((int)IPTP->guild_lev() == 0) {
    write("You are at the beginning level. See the list of upgrades.\n");
    return 1; }
  write("\n~~Neural Microprocessors~~\n");
  call_other(GLEVELD, "checkBrand", TP, (int)IPTP->guild_lev(), 0);
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}


status fab_chip() {
  if (IPTP && IPTP->guild_lev() < 1)
  {
    write("You are not of sufficient guild level to fab chips.\n");
    return 1;
  }
  if(!present(FAB_NPC, environment(TP))) {
    write("The technician is not present.\n");
    return 1; }
  write("You tell the technician to fab you a processor die set.\n");
  tell_room(this_object(), 
    "The technician dances to the sound of disco, pushing various buttons with\n"+
    "with various groovin' body parts. A new neural processor die set pops out\n"+
    "of a huge vat side door. The technician gives the set to "+TPN+"\n");
  move_object(clone_object(CHIPOBJ), TP);
  write("You now have a new neural processor die set.\n");
  return 1;
}

exit() {
   object dset;
   if(this_player()) if(dset = present("die",this_player())) destruct(dset);
}

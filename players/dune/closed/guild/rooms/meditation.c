inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"


init() {
  add_action("advance_member","upgrade_chip");
  add_action("set_brand",     "new_chip");
  add_action("list_brands",   "list_chips");
  add_action("exchange_exp",  "exchange");
  ::init();
}

reset(arg){
  if(!arg){
  set_light(1);
  short_desc=FUNKYNAME+" Meditation Room";
  long_desc=
"     You are in a place of silence and solitude.  The lighting\n"+
"is dark here.  Several pillows and soft silk sheets cover the\n"+
"floor.  This is a place for meditation.  A place to improve one's\n"+
"mental and physical being by tapping into the riches of cyberspace.\n"+
"Here you may perform one of the following actions:\n"+
"'new_chip' to select a chip if you do not already have one,\n"+
"'list_chips' to view other chips of the same category as yours,\n"+
"'upgrade_chip' to view chips in the next higher category,\n"+
"'upgrade_chip <brandName>' to upgrade to the specified chip,\n"+
"'exchange <#xp>' to convert normal xp into guild xp.\n"+
"*Note: Once you upgrade to a specific chip, you cannot\n"+
"       change it until you are able to upgrade again.\n";

  items=({
"pillows", "The pillows are soft and comfortable",
"sheets","Several sheets lie upon the floor for kneeling on",
  });

  dest_dir=({
    ROOMDIR + "/hallway1.c","west",
  });
  }
}


status set_brand(string str) {
  string brand;
  if(!IPTP) {
    tell_object(TP, "You are not a "+FUNKYNAME+".\n");
    return 1; 
  }
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


status advance_member(string str)
{
  string brand;
  if(!IPTP) {
    tell_object(TP, "You are not a "+FUNKYNAME+".\n");
    return 1; 
  }
  if(!str)
  {
    write("\n~~Available Upgrades~~\n");
    call_other(GLEVELD, "checkBrand", TP, ((int)IPTP->guild_lev())+1, 0);
    write("~~~~~~~~~~~~~~~~~~~~~~\n");
    return 1;
  }
  if(call_other(GLEVELD, "advance_member", TP, str))
  {
    brand = capitalize((string)IPTP->query_brand());
    call_other(CHANNELD, "overchannel", 
      TRN+" has now upgraded to a "+
      brand+" neural processor!\n");
    tell_object(TP, "Congratulations!\n");
  }
  else write("You did not upgrade your neural chip.\n");
  return 1;
}


status exchange_exp(string str) {
  int amount;
  if(!IPTP) {
    tell_object(TP, "You are not a "+FUNKYNAME+".\n");
    return 1; 
  }
  if(!str || !sscanf(str, "%d", amount)) {
    tell_object(TP, "Usage: exchange <amount>.\n");
    return 1; 
  }
  call_other(GLEVELD, "exchange_exp", TP, amount);
  return 1;
}


status list_brands() {
  if(!IPTP) {
    tell_object(TP, "You are not a "+FUNKYNAME+".\n");
    return 1; 
  }
  write("\n~~Neural Microprocessors~~\n");
  call_other(GLEVELD, "checkBrand", TP, (int)IPTP->guild_lev(), 0);
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}

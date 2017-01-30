#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit WEAPON;
int tank;

reset(arg) {
   if(arg) return;
   tank = 20;
   set_id("chainsaw");
   set_alias("gory chainsaw");
   set_short("A gory chainsaw");
   set_long(
      "This double-edged steel beauty has a rotating chain with 1.5 inch spikes on\n"+
      "either side of the blade.  The blade itself is attached to a dark red handle\n"+
      "and engine.\n"+
      "You can 'refuel' the chainsaw if the gas is low.\n");
   set_type("axe");
   set_weight(3);
   set_hit_func(this_object()); 
   set_value(500+random(100));
   set_class(18); 
   set_message_hit(({
            HIW+"gored"+NORM," with the chainsaw",
            RED+"ripped the flesh from"+NORM,"'s bones",
            "slashed"," viciously",
            "plunged the chainsaw into","'s heart",
            "jerked the chainsaw up into","'s spleen",
            "jabbed"," with the chainsaw",
            "zipped the blades in front of","", }));
}

init() {
   ::init();
   add_action("offwield","offwield");
   add_action("refuel","refuel"); }

refuel(arg) {
   int hmm;
   object gas_can;
   gas_can = present("gas_can",TP);
   if(!arg) { write("Refuel what?\n"); return 1; }
   if(arg == "chainsaw") {
      if(tank) {
         write("Use the rest of this gas before you refuel!\n"); return 1; }
      if(!gas_can) {
         write("You don't have a gas tank to refuel the chainsaw with!\n"); return 1; }
      hmm = gas_can->query_fuel();
      if(!hmm) { write("There is no more fuel remaining in your gas can!\n"); return 1; }
      write("\n          ...glug glug glug...\n"+
         "You refuel the chainsaw successfully!\n");
      say(TPN+" refuels the chainsaw successfully!\n");
      tank = 20;
      gas_can->add_fuel(-20);
      return 1; } }

weapon_hit(attacker){
   int x; string msg1, msg2;
   x = 1+random(6);
   if(!attacker) return;
   if(!tank) { 
      write("Your chainsaw sputters . . .\nIt seems to need more fuel.\n"); 
      say(TPN+"'s chainsaw sputters . . .\n"); 
      if(!USER->query_npc()) { command("unwield",USER);
         write("You unwield the chainsaw, it is doing no good.\n");
         set_class(3); return; } }
   if(tank) {
      x*=2; x++; msg1 = message_hit[x-1]; msg2 = message_hit[x];
      write("You "+msg1+" "+attacker->QN+msg2+".\n");
      say(TPN+" "+msg1+" "+attacker->QN+msg2+".\n");
      tank -= 1;
      set_class(18);
      return 4+random(2); }
   return; 
}

query_save_flag() { return 1; }

offwield() {
   write("You can't offwield this weapon.\nMail Vertebraker if you want to know why.\n");
   return 1; }

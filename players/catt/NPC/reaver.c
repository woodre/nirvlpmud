inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
#include "/players/beck/MortalKombat/MKQuestNPC.h"
reset(arg) {
  object weapon;
  object armor;
object armor2;
::reset(arg);
if(arg) return;
set_name("reaver");
set_alias("mercenary");
set_short("Reaver, mercenary from malac's crossing");
set_long("Reaver is a merc captain and a very powerful one.  He is\n"+
"here on a mission, but at the moment is healing up after being\n" +
"way laid by goblins\n");
set_al(10000);
set_wc(10);
set_hp(2000);
/* Level changed from 35 to 18 to reflect stats -Snow */
set_level(18);
set_ac(17);
set_chat_chance(5);
load_chat("Reaver whispers: The Great Helm must be recovered. \n"
         +"Reaver sighs saying: The Demon Lords have ordered it.\n");
load_chat("The sword in reavers hand hums with power.\n");
weapon = clone_object(WPN+"balig");
if(weapon) {
  move_object(weapon, this_object());
  command("wield "+weapon->query_name());
    }
armor = clone_object(ARM+"reaverchain");
if(armor) {
  move_object(armor, this_object());
}
armor2 = clone_object(ARM+"reaverboots");
  if(armor2) {
    move_object(armor2, this_object());
             }
  move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
}

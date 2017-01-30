/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/P90.c        *
 *    Function:         Club version of the P90 - no bullets          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           01/15/07                                      *
 *    Notes:            Mizan, Rumplemintz, and Sparrow               *
 *                      Thanks for the help on this code              *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

inherit "/obj/weapon.c";
 
#define FULL_P90 "/players/angel/area/stargate/obj/P90.c"

#define AMMOTYPE "bullets"

#include <ansi.h>

void reset(int arg){
   if(arg) return;
   ::reset(arg);
   set_name("P90");
   set_alias("P90");
   set_alt_name("gun");
   set_short(CYN+"P90 machine gun"+NORM);
   set_long("This P90 is SG-1 staple machine gun.  The gun packs a punch and\n"+
   "is deadly accurate. It is out of ammo but, can be used as a club.\n");
   set_class(15);
   set_type("club");
   set_weight(2);
   set_value(1000);
}

void init(){
  ::init();
   /* action to load the weapon */
   add_action("load","load");
   add_action("study","study");
   add_action("push","push");
}

/* Function name: load ()
 * Description: loading the weapon which will switch the P90_no_ammo.c
 *              to the loaded P90.c
 * Arguments: 
 * Returns: 
 */
load(str){
   object ammo, new_weap;
   int rounds2;
   if(!str || str != "P90") return 0;
   ammo = present(AMMOTYPE, this_player());
   if(!ammo){
      notify_fail("You don't have any P90 clips.\n");
      return 0;
   }
   rounds2 = ammo->query_ammo();
   if(!rounds2 || rounds2 > 99990){
      notify_fail("Your P90 chucks out the ammo you tried to shove into it.\n");
      return 0;
   }
   /* function to switch to the P90.c when ammo is loaded */
   command("locknload", this_player());
   new_weap = clone_object(FULL_P90);
   move_object(ammo, new_weap);
   move_object(new_weap, this_player());
   command("wield P90", this_player());
   this_player()->add_weight(-1);
   write("The P90 clip slides into the grip of the machine gun swiftly.\n");
   write("There are [" + new_weap->rounds() + "] rounds remaining.\n");
   say(capitalize(this_player()->query_name())+" loads the P90 machine gun.\n");
   destruct(this_object());
   return 1;
}

/* Function name: study ()
 * Description: allows players to view P90's abilities
 *            
 * Arguments: 
 * Returns: 
 */
study(str) {
  if(str == "manual") {
    write("                    P90 MANUAL\n"+
"\n"+
"        This machine gun combines the automatic fire of\n"+
"    a large machine gun with the cartridge of a pistol\n"+
"    It is slightly larger in weight and size of a rifle.\n"+
"    The following is a list of attachments that can be\n"+
"    obtained to use with the P90.\n"+
"\n"+
"\n"+
"  item                   function                       command\n"+
"\n"+
"Clip of Bullets     50 rounds in a clip               load P90\n"+
"\n"+
"Additions coming soon\n"+
"\n"+
"Laser Sight         accurate hit adds dmg to mobs     attach sight\n"+
"                                                        sight on/off\n"+
"Flash Light         gives off light in dark           attach light\n"+
"                                                        light on/off\n"+
"Bayonet             makes an empty gun a dagger       attach bayonet\n"+
"\n"+
"Tracer Rounds       has fire damage                   load rounds\n"+
"\n"+
"Silver Bullets      hit vampires hard                 load bullets\n"+
"\n"+
"Grenade             stuns mobs                        load grenade\n"+
"\n"+
"Grenade Launcher    launches grenade's                attach launcher\n"+
"\n"+
"\n"+
"\n");
  return 1;
}
  notify_fail("study what?\n");
}

/* Function name: push ()
 * Description: a computer pop out screen on the high tech
 *  military gun for let players know it different options          
 * Arguments: 
 * Returns: 
 */
push(str){
  if(str != "button"){
    notify_fail("What would are you trying push?\n");
    return 0;
  }
  write("A screen pops up out from side of the firearm.\n\
\n\
"+CYN+"     ------------------------------\n\
     |                            |\n\
     |   You must first 'study'   |\n\
     |  the 'manual' to correctly |\n\
     |     use this firearm!      |\n\
     |                            |\n\
     ------------------------------"+NORM+" \n");
  say(this_player()->query_name()+" read the text screen.\n");
  return 1;
}

/* so you can put things inside of it. */
can_put_and_get() { return 1; }

/* stops weapon from breaking */
weapon_breaks()
{
  return 1;
}
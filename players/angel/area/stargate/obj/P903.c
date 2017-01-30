/*                                                                    *
 *    File:             /players/angel/area/stargate/obj/P90.c        *
 *    Function:         obj machine gun /w options                    *
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

#include <ansi.h>

inherit "obj/weapon.c";

#define AMMOTYPE "bullets"

#define EMPTY_P90 "/players/angel/area/stargate/obj/P90_no_ammo.c"

int total_damage;

int ob;

int laser;

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("machine gun");
  set_alias("p90");
  set_alt_name("gun");
  set_alt_name("P90");
  set_long(
      "This P90 is SG-1 staple machine gun.\n"+
  "The gun packs a punch and it is deadly accurate.\n"+
  "There appears to be a button on the side to 'push'.\n");
  set_class(15);
  set_weight(2);
  set_value(1000);
  /* tells the player and living objects to set ourselves with an extra
   * hit function.*/
  set_hit_func(this_object());
  message_hit=({
    "pounded"," with the sheer force of the P90",
    "nicked"," by the P90",
    "hit"," with deadly accuracy",
    "knocked"," down with the butt of the gun",
    "whacked"," upside the head",
    "shattered","'s arm into pieces",
    "struck"," in between the eyes",
  });
}

init() 
{
  ::init();
  add_action("cmd_barter","strip");
  add_action("study","study");
  add_action("push","push");
  add_action("attach","attach");
}

/* Function name:  cmd_barter ()
 * Description:  This section was added so the player can exchange
 * the weapon for 1000 coins and the ammo ( 500 coin value )in the
 * gun. Players cannot take ammo out of a gun.
 * Arguments:
 * Returns:
 */
cmd_barter(str) {
  if(id(str)) {
    if(present("private",environment(this_player()))) {
	  if (!member(users(), this_player()) == -1) {}
      write("Private says, nice doing business with you! Tell your friends I can hook them up too!\n");
        ob = clone_object("/obj/money.c");
        ob->set_money(1000);
        move_object(ob, environment(this_object()));
        destruct(this_object());
        this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("strip what?\n");
}

/* Function name:    study()
 * Description:      allows players to view the P90 mauual
 *            
 * Arguments:         
 * Returns: 
 */
study(str) {
  if(str == "manual") {
    write("                    P90 MANUAL\n"+
"\n"+
"        This machine gun combines the automatic fire of\n"+
"    a large machine gun with the cartridge of a pistol.\n"+
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
"\n"+
"Flash Light         gives off light in dark           attach light\n"+
"\n"+
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
"Sniper Scope        add dmg for accuracy              attach scope\n"+
"\n"+
"\n"+
"\n");
  return 1;
}
  notify_fail("study what?\n");
}

/* Function name:  push()
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

short()
{
  string dis;
  int ammo;
  object ob;
  /* the clip is inside the weapon. just like a real weapon. */
  ob = present(AMMOTYPE, this_object());
  if(ob)
  {
  /* checks the clip for ammo and how much */  
    ammo=ob->query_ammo();
  }
  /* the description of the gun and displays the number of bullets left */
  dis = " "+CYN+"P90 Machine Gun"+NORM+" [" + ammo + "]";
  if(wielded) dis = dis + " (wielded)";
  /* for higher level wizzes to view data */
  if(this_player() && this_player()->query_level() > 39) dis = dis + " <Total damage inflicted: [" + total_damage + "]>";
  return dis;
}

attach(str){
  object laser;
  laser = present("lasersight", this_player());
  if(!laser){
      notify_fail("You don't have a laser sight.\n");
      return 0;
  write("The Laser Sight slides on to the machine gun swiftly.\n");
  say(capitalize(this_player()->query_name())+" the Laser Sight.\n");
  return 1;
}}

/* Function name: weapon_hit ()
 * Description:  
 *            
 * Arguments: 
 * Returns: 
 */
weapon_hit(attacker)
{
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());

  if(clip)
  { 
    write("You point the P90 and shoot at "+capitalize(attacker->query_name())+".\n");
    say(capitalize(this_player()->query_name())+" shoots "+capitalize(attacker->query_name())+" with a P90 machine gun.\n");
    clip->lose_ammo();
    checked_hit(3);
    /* the weapon return is being calculated here, if there
    * are no more rounds, the weapon will switch to the club */
    if(!rounds()){
      destruct(clip);
      write("You've shot your last bullet!\n");
      /* function to switch to the unloaded gun when the ammo is out */
      move_object(clone_object(EMPTY_P90), this_player());
      command("wield P90", this_player());
      destruct(this_object());
      return 1;
    }
    return 1;         
  }
  /* the clip is empty and lets the player know. */
  write("Your P90 is out of bullets!\n");
  return -10;

  if(laser)
  {
	if (random(13)>8)
    write("You align the P90's laser sight in between your foe's eyes and soot at "+capitalize(attacker->query_name())+".\n");
    say(capitalize(this_player()->query_name())+" shoots "+capitalize(attacker->query_name())+" with awsome precision!\n");
    return 6;
  }
}
/* calculates how much ammo is in the clip */
rounds() 
{
  object rc;
  int i;
  rc=present(AMMOTYPE, this_object());
  i=rc->query_ammo();
  return i;
}

/* Function name: checked_hit ()
 * Description: this function directly hits the monster but goes out of
 *              its way not to kill it. On top of that it caps the damage 
 * Arguments: 
 * Returns: 
 */
checked_hit(arg)
{
  int a_hp,a_dam;
  object a_attack;
  a_attack = this_player()->query_attack();
  if(a_attack){
    a_hp = a_attack->query_hp();
    a_dam = random(arg);
    if(!a_attack->query_npc() && a_dam > 9)
      a_dam = 10;
    if(a_hp < a_dam || a_hp == a_dam)
      a_dam = a_hp - 1;
    a_attack->hit_player(a_dam);
    total_damage = total_damage + a_dam;
  }
}

/* allows you to put things inside of it. */
can_put_and_get() { return 1; }

/* stops weapon from breaking */
weapon_breaks()
{
  return 1;
}

query_wield() {
  int wield;
  wield = 3*hits/25;
  return wield;
}
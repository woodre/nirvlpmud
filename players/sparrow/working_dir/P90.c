/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/P90.c        *
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

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("machine gun");
  set_alias("P90");
  set_alt_name("gun");
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
    "wacked"," upside the head",
  });
}

init() 
{
  ::init();
  add_action("cmd_barter","strip");
  add_action("read","study");
  add_action("push","push");
}
/* This section was added so the player can exchange the weapon for 1000 coins\n\
 * and the ammo in the gun. Players can not take ammo out of a gun.*/
cmd_barter(str) {
  if(id(str)) {
    if(present("private",environment(this_player()))) {
	  if (!member(users(), this_player()) == -1) {}
      write("Private says, nice doing bussiness with you! Tell your friends I can hook them up too!\n");
        ob = clone_object("/obj/money.c");
        ob->set_money(1000);
        move_object(ob, environment(this_object()));
        move_object(clone_object("/players/angel/area/stargate/obj/bullets.c"),environment(this_object()));
        destruct(this_object());
        this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("strip what?\n");
}

study(arg) {
  if(arg == "1") {
    write("this is the info for page 1");
}
  else if(arg == "2") {
    write("this is the info for page 2");
}
  if(!arg) {write("study what?")};
}


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

/* this function directly hits the monster but goes out of
 * its way not to kill it. On top of that it caps the damage */
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

/* so you can put things inside of it. */
can_put_and_get() { return 1; }

/* stops weapon from breaking */
weapon_breaks()
{
  return 1;
}
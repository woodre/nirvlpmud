/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/P90.c        *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"
 
#include <ansi.h>

inherit "obj/weapon.c";

#define AMMOTYPE "bullets"

int total_damage;

int ob;

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("machine gun");
  set_alias("P90");
  set_alt_name("gun");
  set_long(
        "This P90 is SG-1 staple machine gun.  The gun packs a punch\n\
and is deadly accurate.\n");
  set_class(15);
  set_weight(2);
  set_value(2000);
  set_hit_func(this_object());
}

init() 
{
  ::init();
  add_action("load","load");
  add_action("cmd_barter","strip");
}

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

short()
{
  string dis;
  int ammo;
  object ob;
  ob = present(AMMOTYPE, this_object());
  if(ob)
  {
    ammo=ob->query_ammo();
  }
  dis = "P90 Machine Gun [" + ammo + "]";
  if(wielded) dis = dis + " (wielded)";
  if(this_player() && this_player()->query_level() > 39) dis = dis + " <Total damage inflicted: [" + total_damage + "]>";
  return dis;
}

load(str)
{
  object ammo;
  int rounds2;
  if(!str || str != "P90") return 0;
  if(present(AMMOTYPE,this_object())) 
  {
    write("The gun already has a clip in it.\n");
    return 1;
  }
  ammo=present(AMMOTYPE, this_player());
  if(!ammo) 
  {
    write("You don't have any P90 clips.\n");
    return 1;
  }
  move_object(ammo, this_object()); 
  this_player()->add_weight(-1);

  rounds2 = ammo->query_ammo();

  if(!rounds2 || rounds2 > 99990)
  {
    destruct(ammo);
    write("Your P90 chucks out the ammo you tried to shove into it.\n");
  }
  write("The P90 clip slides into the grip of the machine gun swiftly.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " loads the P90 machine gun.\n");
  return 1;
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

    if(!rounds())
    {
      destruct(clip);
      write("You've shot your last bullet!\n");
      return 1;
    }
    return 1;         
  }

  write("Your P90 is out of bullets!\n");
  return -10;
}

rounds() 
{
  object rc;
  int i;
  rc=present(AMMOTYPE, this_object());
  i=rc->query_ammo();
  return i;
}

checked_hit(arg)
{
  int a_hp,a_dam;
  object a_attack;
  a_attack = this_player()->query_attack();

  if(a_attack)
  {
    a_hp = a_attack->query_hp();
    a_dam = random(arg);

  if(!a_attack->query_npc() && a_dam > 4) a_dam = 5;
    if(a_hp < a_dam || a_hp == a_dam) a_dam = a_hp - 1;
    a_attack->hit_player(a_dam);
    total_damage = total_damage + a_dam;

  }
}

can_put_and_get() { return 1; }
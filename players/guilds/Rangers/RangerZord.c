#pragma strict_types

#include <ansi.h>
#include "RangerDefs.h"

inherit "/obj/monster.c";

object Owner;
string OwnerName;
int OwnerNumber;
string message;
object ownerattack;

status ZordRage(object a, int modifier);


void
set_OwnerName(string str){ OwnerName = str; }

void
set_Owner(object arg){ Owner = arg; }

void
set_OwnerNumber(int arg){ OwnerNumber = arg; }

void
reset()
{
  ::reset();
  set_name("zord");
  set_alt_name("RangerZord");
  set_race("machine");
  set_can_kill(1);
  set_hbflag("hbstayon");
  set_dead_ob(this_object());
  set_long("This is the personal Zord of a Power Ranger.\n");
}

void
init()
{
  ::init();
  add_action("release","release");
}

void
long()
{
  ::long();
  if(COMM)
  {
    write("Type 'release' to send your Zord back to the command center.\n");
  }
}

status
release()
{
  if(this_player() == Owner)
  {
    if("/players/guilds/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber))
    {
      tell_room(environment(this_object()), "The Zord flies back to the Command Center.\n");
      destruct(this_object());
      return 1;
    }
  }
  return 0;
}

void
set_message(string str) { message = str; }

void
heart_beat()
{
  if(!environment())          /* added by verte 6.6.01 */
  {
    set_heart_beat(0); return;
  }
  if(!Owner || !find_living(OwnerName) || Owner->query_ghost())
  {
    tell_room(environment(this_object()),"A Zord flies away for repairs.\n");
    "/players/guilds/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber);
    destruct(this_object());
    return;
  }
  if(!present(Owner, environment(this_object())))
  {
    tell_room(environment(this_object()),"A "+message+" leaves.\n");
    move_object(this_object(), environment(Owner));
    tell_room(environment(this_object()),"A "+message+" arrives.\n");
  }
  if(!Owner->query_interactive() && !this_object()->query_attack())
    return;
  ::heart_beat();
  if(!attacker_ob && Owner && present(Owner, environment(this_object())) && present(Owner,environment(this_object()))->query_attack())
  {                           /* additional present() check by verte 6.6.01 */
    ownerattack = (object) present(Owner,
      environment(this_object()))->query_attack();
    if(!ownerattack->is_player() || present(Owner,environment(this_object()))->RangerNPC())
    {
      this_object()->attack_object(present(Owner,
        environment(this_object()))->query_attack());
      if(weapon_class > random(30)) ZordRage(attacker_ob, 1);
      if(weapon_class > random(60)) ZordRage(attacker_ob, 5);
      if(weapon_class > random(90)) ZordRage(attacker_ob, 7);
    }
  }
  if(this_object()->query_attack() && !present(Owner, environment(this_object()))->query_attack())
  {
    if((this_object()->query_attack())->is_player())
      (this_object()->query_attack())->hit_player(50,"other|zord");
    tell_room(environment(this_object()),"The Zord becomes ferocious and crushes "+
      (this_object()->query_attack())->query_name()+" with immense force.\n");
  }
}

void
monster_died(object monster)
{
  tell_room(environment(this_object()),"The Zord flies back to the Command \
Center for serious repairs.\n");
  destruct(present("corpse",environment(this_object())));
  "/players/guilds/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber);
  return;
}

status
query_player_shell(){ return 1;}

string
RageMessage()
{
  string RageMessage, AttackerName;
  switch( random(4))
  {
    case  0: RageMessage =
      "A " + message + " inflicts great damage on the enemy\n";
    break;
    case  1: RageMessage =
      "A " + message + " surges into the heat of battle.\n";
    break;
    case  2: RageMessage =
      "A " + message + " leaps in to attack!\n";
    break;
    case  3: RageMessage =
      capitalize(OwnerName) + "'s " + message + " ferociously attacks the enemy.\n";
    break;
    default: RageMessage =
        "A " + message + " lashes out in a vicious attack.\n";
  }
  return RageMessage;
}

status
ZordRage(object a, int modifier)
{
  if(!a) return 0;
  a->hit_player( ((weapon_class*modifier)/2),"other|laser");
  tell_room(environment(this_object()), RageMessage());
  return 1;
}

/* Test to reset ownership if dested --Vital 2007-10-27 */
void
remove_object(object punk)
{
  "/players/guilds/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber);
  destruct(this_object());
}
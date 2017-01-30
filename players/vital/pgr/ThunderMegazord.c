#pragma strict_types

#include <ansi.h>
#include "RangerDefs.h"

inherit "obj/monster";

static int old_hp;
static int old_exp;
static int total_damage;
static string attacker_name;
object only_attack;
int in_battle;

string
realm(){ return "NT"; }

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("thunder megazord");
  set_level(20);
  set_alias("megazord");
  set_race("RangerMegazord");
  set_hp(MASTER->QPowerPoints("Power Ranger"));
  set_ep(1000);
  set_al(1000);
  set_short("The Thunder "+BOLD+GREEN+"MEGA"+OFF+"zord");
  set_wc(45);
  set_ac(20);
  set_can_kill(1);
  set_chance(10);
  set_spell_dam(10);
  set_spell_mess1("The Megzord's Saber rips through the enemy with speed and \
precision.\n");
  set_dead_ob(this_object());
  set_hbflag("hbstayon");
  old_hp = hit_point;
  old_exp = 1000;
}

void
init()
{
  ::init();
  if(present(this_player(), this_object()))
  {
    add_action("move_zord","move");
    add_action("attack_other","demolish");
  }
  if(this_player()->query_level() > 19)
  {
    add_action("zordin","zordin");
  }
}

varargs status
look(string str)
{
  object ol;
  string sh;
  if(!str)
  {
    environment()->long();
    for(ol = first_inventory(environment()); ol; ol = next_inventory(ol))
      if(ol !=this_object() && (sh = (string) ol->short()))
    {
      tell_room(this_object(), sh); tell_room(this_object(), "\n");
    }
    return 0;
  }
  return 1;
}

status
move_zord(string str)
{
  if(str != "north" && str != "south" && str != "east" && str != "west" &&
    str != "northeast" && str != "northwest" && str != "southeast" && str != "southwest" &&
    str != "up" && str != "down" && str != "in" && str != "out" && str != "exit" &&
    str != "enter" )
  {
    write("The Thunder Megazord cannot move that direction.\n");
    return 1;
  }
  command(str, this_object());
  look();
  return 1;
}

status
long()
{
  if(present(this_player(), this_object()))
  {
    write(format("You are inside the Thunder Megazord. You see a large \
control panel with various buttons and 2 joysticks. You can 'move' the \
zord in any standard direction.\nYou can attempt to 'demolish' opponents, \
but beware...\nWhen the Zord loses Power (hps)...so do you!\nMake sure \
the guild power levels are high to power the Megazord through battle.\n"));
    return 1;
  }
  write(format("This is the awesome Thunder Megazord of the Power Rangers! \
It is a 50 foot tall Robot comprised of 5 smaller Thunderzords. The Thunder \
Megazord has tremendous power and strength.\n"));
  return 1;
}

status
zordin()
{
  move_object(this_player(), this_object());
  return 1;
}

status
catch_tell(string str)
{
  if(this_player() != this_object())
  {
    if(!this_player() || !present(this_player(), this_object()))
      tell_room(this_object(), str);
    return 1;
  }
  return 1;
}

status
monster_died(object monster)
{
  object corpse;
  object ob;
  object oc;
  set_short(0);
  log_file(LOGDIR + "Megazord","Megazord killed by "+
    attacker_name+" Damage: "+total_damage+" "+ctime(time())+"\n");
  MASTER->APowerPoints( -( (int) MASTER->QPowerPoints("Power Ranger")),
    "Power Ranger");
  corpse = present("corpse", environment(this_object()));
  tell_room(corpse,"\n\nYou are thrown out of the Thunder Megazord.\n\nThe \
Thunderzords separate and fly away.\n\n");
  oc = first_inventory(corpse);
  for(ob = first_inventory(corpse); ob; ob = next_inventory(ob))
  {
    if(ob->is_player() && ob != oc)
    {
      move_object(ob, environment(corpse));
      command("look", ob);
      ob->attack_object(only_attack);
      ob = first_inventory(corpse);
    }
  }
  move_object(oc, environment(corpse));
  command("look", oc);
  oc->attack_object(only_attack);
  destruct(corpse);
  return 0;
}

status
attack_other(string str)
{
  object ta;
  if(!str)
  {
    write("Who do you want to attack?\n");
    return 1;
  }
  ta = present(str, environment());
  if (!ta || !living(ta))
  {
    write("That target is not here.\n");
    return 1;
  }
  if(ta->is_player())
  {
    write("You can't attack players!!!\n");
    return 1;
  }
  if(only_attack)
  {
    write("You can only attack one monster at a time!!!\n");
    return 1;
  }
  attacker_name = (string) ta->query_name();
  this_object()->attack_object(ta);
                              /* previous by wiz */
  ta->attack_object(this_object());
  log_file(LOGDIR + "Megazord","Megazord attacked "+
    attacker_name+" "+ctime(time())+"\n");

  alt_attacker_ob = 0;
  return 1;
}

int
hit_player(status arg)
{
  int n;
  int new_hp;
  int damage;
  int damage2;
  int new_exp;
  int exp;
  object first;
  object ob;
  hit_point = (int) MASTER->QPowerPoints("Power Ranger");
  old_hp = hit_point;
  ::hit_player(arg);
  if(!this_object()) return 0;
  if(this_object()->query_ghost()) return 0;
  if(this_object()->query_attack())
  {
    n = 0;
    new_hp = hit_point;
    damage = (old_hp - new_hp);
    damage2 = damage;
    total_damage += damage;
    MASTER->APowerPoints(-(damage),"Power Ranger");
    damage = damage/5;
    for(ob = first_inventory(this_object()); ob; ob = next_inventory(ob))
    {
      if(ob->is_player() && !ob->query_ghost())
      {
        n = n + 1;
        ob->add_hit_point(-damage);
        tell_object(ob,"You take " + BOLD + RED + damage + OFF +
          " damage from the hit.\n");
        ob->monitor();
        if(ob->query_hp() <= 0) ob->hit_player(300);
      }
    }
    if( n == 0)
    {
      say("Without someone to control them, the Thunderzords separate and fly \
away.\n");
      destruct(this_object());
      return 0;
    }
  }
  if(damage2 <= 0) return 0;
  return damage2;
}

void
ZordLeave()
{
  object ob;
  object oc;
  set_short(0);
  log_file(LOGDIR + "Megazord","Megazord victorious over "+
    attacker_name+" Damage: "+total_damage+" "+ctime(time())+"\n");
  tell_room(this_object(),"The Battle is over and you are Victorious.\n\n\nThe \
Thunderzords separate and fly away.\n\n\n");
  oc = first_inventory(this_object());
  for(ob = first_inventory(this_object()); ob; ob = next_inventory(ob))
  {
    if(ob->is_player() && ob != oc)
    {
      move_object(ob, environment(this_object()));
      command("look", ob);
      ob = first_inventory(this_object());
    }
  }
  move_object(oc, environment(this_object()));
  command("look", oc);
  destruct(this_object());
  return;
}

void
heart_beat()
{
  string msg;
  ::heart_beat();
  if(in_battle && !only_attack)
  {
    ZordLeave();
    return;
  }
  if(query_attack())
  {
    in_battle = 1;
    if(hit_point < 100) msg = "critical";
    else if(hit_point < 1000) msg = "low";
    else if(hit_point < 2000) msg = "good";
    else msg = "very good";
    tell_room(this_object(),
      "Guild Power levels are " + BOLD + GREEN + msg + OFF + ".\n");
    tell_room(this_object(),query_attack()->query_name()+" hps: " + 
      ( ( 10 * ( (int) query_attack()->query_hp() ) /
      ( (int) (query_attack()->query_mhp()) ) ) + "/10\n") );
    if(!only_attack)
    {
      only_attack = (object) this_object()->query_attack();
    }
  }
}

status
query_player_shell(){return 1;}

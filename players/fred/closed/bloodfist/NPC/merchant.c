inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Loren"
object armor,cap,boots,pack,gob;

reset(arg){
  if(arg) return;
  ::reset(arg);

  pack = clone_object("/obj/treasure.c");
  pack->set_name("backpack");
  pack->set_short("A leather backpack");
  pack->set_long("This is a durable leather backpack.\n"+
    "There is no way to open it.\n");
  pack->set_weight(1);
  pack->set_value(300);
  move_object(pack, this_object());

  cap = clone_object("/obj/armor.c");
  cap->set_type("helmet");
  cap->set_name("cap");
  cap->set_short("Leatherhide cap");
  cap->set_long(
    "This is a simple looking leather cap with flaps on the side that\n"+
    "hang down over the wearers ears to keep them warm.  It has been\n"+
    "taken well care of since it was made.\n");
  cap->set_weight(1);
  cap->set_ac(1);
  cap->set_value(200);
  move_object(cap, this_object());
  init_command("wear cap");

  boots = clone_object("/obj/armor.c");
  boots->set_type("boots");
  boots->set_name("boots");
  boots->set_short("Leatherhide boots");
  boots->set_long(
    "This pair of boots are old and worn, yet look incredibly comfortable\n"+
    "inside.  They are made from a very tough leather that is quite thick.\n"+
    "They may not be stylish, but they are still quite nice boots.\n");
  boots->set_weight(2);
  boots->set_ac(1);
  boots->set_value(1400);
  move_object(boots, this_object());
  init_command("wear boots");

  armor = clone_object("/obj/armor.c");
  armor->set_name("robe");
  armor->set_type("armor");
  armor->set_short("Leatherhide armor");
  armor->set_long(
    "A tough suit of leatherhide armor.\n");
  armor->set_weight(1);
  armor->set_ac(0);
  move_object(armor, this_object());
  init_command("wear robe");

  set_name("loren");
  set_alt_name("nomad");
  set_alias("merchant");
  set_short("A Nomadic Merchant");
  set_long(
ME+" is a nomadic merchant who has taken up residence within the\n"+
"Bloodfist encampment.  He is a man of medium build, clad in matching\n"+
"leather garments.  He appears to be unarmed although ready to defend\n"+
"himself if necessary.  He is carrying a backpack that seems to have a\n"+
"lot of things inside it.  You can 'buy' 'sell' 'list' or 'value' here.\n");
  set_race("human");
  set_level(23);
  set_ac(17);
  set_ac_bonus(10);
  set_wc(40);
  set_wc_bonus(10);
  set_hp(4000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" shuffles slightly beneath his armor.\n");
  load_chat(ME+" looks up at the darkness.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_chat(ME+" glances at you.\n");
  load_chat(ME+" looks you up and down.\n");
  load_chat(ME+" asks, \"Care to see what I have for sale?\"\n");
  load_chat(ME+" says, \"I have both regular and filtered water.\"\n");
  load_chat(ME+" says, \"Hello there.\"\n");
  load_chat(ME+" asks, \"Need to buy some water?\"\n");
  load_chat(ME+" asks, \"Want to buy some water?\"\n");
  load_chat(ME+" asks, \"Hey, you need any water?\"\n");
  load_chat(ME+" asks, \"Hey, want some water?\"\n");
  load_chat(ME+" says, \"I have lots for sale.\"\n");
  load_chat(ME+" asks, \"Do you need anything?\"\n");
  load_a_chat(ME+" says, \"You will gain nothing from my death.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
}

void monster_died(){
  write_file("/players/fred/closed/bloodfist/log/NPC",
  ctime(time())+" - "+attacker_ob->query_name()+" [L "+
  attacker_ob->query_level()+
  "+"+attacker_ob->query_extra_level()+"] killed "+ME+".\n");
}

void init(){
  ::init();
  add_action("buy_cmd", "buy");
  add_action("list_cmd", "list");
  add_action("sell_cmd", "sell");
  add_action("value_cmd", "value");
}

status do_sell(object ob)
{
  int value, do_destroy, a;
  value = (int)ob->query_value();
  if(!value)
  {
    write(ob->short() + " has no value.\n");
    return 1;
  }
  if(environment(ob) == this_player())
  {
    int weight;
    if (call_other(ob, "drop", 0))
    {
      write(ME+" says, \"I can't take it from you!\"\n");
      return 1;
    }
    weight = (int)call_other(ob, "query_weight", 0);
    call_other(this_player(), "add_weight", - weight);
  }
  /*
  if(value > 6000)
    do_destroy = 1;
  if(ob->query_dest_flag()) do_destroy = 1;
  */
  if(value > (a = 1000+random(400)))
  {
    write("The shop is low on money...\n");
    value = a;
  }
  write("You get "); write(value); write(" gold coins.\n");
  say(call_other(this_player(), "query_name", 0) + " sells " +
    call_other(ob, "short", 0) + ".\n");
  call_other(this_player(), "add_money", value);
  if(do_destroy)
  {
    write("The valuable item is hidden away.\n");
    destruct(ob);
    return 1;
  }
  call_other("room/store", "store", ob);
  return 1;
}

status sell_cmd(string str)
{
  object ob;

  if(!str) return 0;
  if(str == "all")
  {
    object next;
    ob = first_inventory(this_player());
    while(ob)
    {
      next = next_inventory(ob);
      if(!ob->drop() && ob->query_value())
      {
        write(ob->short() + ":\t");
        do_sell(ob);
      }
      ob = next;
    }
    write("Ok.\n");
    return 1;
  }
  ob = present(str, this_player());
  if(!ob)
    ob = present(str, this_object());
  if(!ob)
  {
    write("No such item ("); write(str); write(") here.\n");
    return 1;
  }
  do_sell(ob);
  return 1;
}

mixed find_item_in_player(string str)
{
  object ob;
  ob = first_inventory(this_player());
  while(ob)
  {
    if(call_other(ob, "id", str))
      return ob;
    ob = next_inventory(ob);
  }
  return 0;
}

status value_cmd(string str)
{
  int value;
  object name_of_item;
  if(!str) return 0;
  name_of_item = present(str);
  if(!name_of_item)
    name_of_item = (object)find_item_in_player(str);
  if(!name_of_item)
  {
    if(call_other("room/store", "value", str))
      return 1;
  write("No such item ("); write(str); write(") here\n");
  write("or in the store.\n");
    return 1;
  }
  value = (int)call_other(name_of_item, "query_value", 0);
  if(!value)
  {
    write(str); write(" has no value.\n");
    return 1;
  }
  write("You would get "); write(value); write(" gold coins.\n");
  return 1;
}

status buy_cmd(string str)
{
  object wa;
  if(!str)
    return 0;
  if((string)this_player()->query_guild_name() != "bloodfist")
    return (notify_fail(ME+" says, \"Sorry, I can't sell to you.\"\n"), 0);
  if(str == "water" || str == "canteen of water")
  {
    if(this_player()->query_money() < 1800)
      return (notify_fail(
      ME+" says, \"You can't afford another canteen of water.\"\n"), 0);
    if(!this_player()->add_weight(1))
      return (notify_fail(
      ME+" says, \"You can't carry another canteen of water.\"\n"), 0);
    write(ME+" hands you a canteen of water.\n");
    tell_room(environment(this_player()),
      ME+" hands a canteen of water to "+this_player()->query_name()+".\n",
      ({ this_player() }));
    wa = clone_object("/players/fred/closed/bloodfist/obj/water.c");
    move_object(wa, this_player());
    this_player()->add_money(-1800);
    return 1;
  }
  if(str == "filtered water" || str == "filtered")
  {
    if(this_player()->query_money() < 3300)
      return (notify_fail(
      ME+" says, \"You can't afford another canteen of filtered water.\"\n"), 0);
    if(!this_player()->add_weight(1))
      return (notify_fail(
      ME+" says, \"You can't carry another canteen of filtered water.\"\n"), 0);
    write(ME+" hands you a canteen of filtered water.\n");
    tell_room(environment(this_player()),
      ME+" hands a canteen of filtered water to "+this_player()->query_name()+".\n",
      ({ this_player() }));
    wa = clone_object("/players/fred/closed/bloodfist/obj/fwater.c");
    move_object(wa, this_player());
    this_player()->add_money(-3300);
    return 1;
  }
  call_other("room/store", "buy", str);
  return 1;
}

void water()
{
  int x;
  x = random(2);
  if(x < 1)
  {
  tell_room(environment(), "\n\n"+
    ME+" says, \"I also have canteens of water for sale for 1800g.\"\n\n");
  }
  else
  {
  tell_room(environment(), "\n\n"+
    ME+" says, \"I also have canteens of filtered water for sale for 3300g.\"\n\n");
  }
}

status list_cmd(string str)
{
  write(ME+" says, \"Here is what I have right now.\"\n");
  call_other("room/store", "inventory", str);
  call_out("water", 3);
  return 1;
}


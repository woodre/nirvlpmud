#include <ansi.h>

inherit "obj/monster";

static object Remembered;

object gold;
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name(""+HIC+"J"+NORM+""+HIW+"a"+NORM+""+HIC+"s"+NORM+""+HIW+"o"+NORM+""+HIC+"n"+NORM+" "+HIW+"V"+NORM+""+HIC+"o"+NORM+""+HIW+"o"+NORM+""+HIC+"r"+NORM+""+HIW+"h"+NORM+""+HIC+"i"+NORM+""+HIW+"e"+NORM+""+HIC+"s"+NORM+"");
      set_alias("jason");
      set_short(""+HIC+"J"+NORM+""+HIW+"a"+NORM+""+HIC+"s"+NORM+""+HIW+"o"+NORM+""+HIC+"n"+NORM+" "+HIW+"V"+NORM+""+HIC+"o"+NORM+""+HIW+"o"+NORM+""+HIC+"r"+NORM+""+HIW+"h"+NORM+""+HIC+"i"+NORM+""+HIW+"e"+NORM+""+HIC+"s"+NORM+"");
      set_race("psychopath");
      set_long(
         "Jason Voorhies, a man of massive size, stands before you. He's wearing\n"+
         "a white, rough looking goalie mask and a blue, bloody jumpsuit. In his\n"+
         "right hand he tightly grips a bloodstained machete, and looks prepared\n"+
         "to use it. Beyond the mask, you can clearly see that the rest of his\n"+
         "head is badly scarred, as are his hands.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (25000) + 25000);
      move_object(gold, this_object());
      set_level(20);
      set_hp(15000);
      set_ac(67);
      set_wc(175);
      set_heal(20,1);
      set_al(-1000);
      set_chance(25);
      set_spell_dam(200);
      set_spell_mess2("Jason "+HIR+"gashes"+NORM+" his opponent with his machete!\n");
      set_spell_mess1("Jason "+HIW+"slices"+NORM+" through his opponent's stomach, spilling their innards!\n");
      set_aggressive(1);
      set_a_chat_chance(10);
      set_chat_chance(10);
      load_chat(""+HIK+"Jason"+NORM+" "+HIW+"whispers"+NORM+": Kill kill kill kill...\n");
      load_chat(""+HIK+"Jason"+NORM+" "+HIW+"whispers"+NORM+": Kill kill kill...\n");
      load_chat(""+HIK+"Jason"+NORM+" "+HIW+"whispers"+NORM+": Kill kill kill kill kill...\n");
      load_chat(""+HIK+"Jason"+NORM+" "+HIW+"whispers"+NORM+": ............KILL...\n");
      load_a_chat("You begin to feel extremely uncomfortable\n");
      if(!root()) call_out("aggro", 2);
      if(!root()) call_out("chase", 2);
    }
}

grab_exit()
{
  string *exits, *rand;
  int    x, y;
  exits = environment()->query_dest_dir();
  y     = sizeof(exits);
  rand = ({ });
  for(x = 1; x < y; x += 2)
  {
    rand += exits[x];
  }
  return rand[random(sizeof(rand))];
}

throw_special()
{
  string exit;
  
  tell_object(attacker_ob,
    "\n\tJason slams his machete against you, knocking you off your feet!\n\n");
  tell_room(environment(),
    "Jason slams his machete against "+attacker_ob->query_name()
    +", knocking "+objective(attacker_ob)+" off "+possessive(attacker_ob)
    +" feet!\n", ({ attacker_ob }));
  attacker_ob->hit_player(100+random(50));
  command((exit=grab_exit()) ? exit : "", attacker_ob);
}

heart_beat()
{
  ::heart_beat();
  if(attacker_ob)
  {
    Remembered = attacker_ob;
  }
  if(random(100) > 90) /* 10 % chance */
  {
    throw_special();
  }
  if(random(100) > 90)
  {
    wound();
  }
}

aggro()
{
  object *inv;
  int    x;
  int found;
/* This if is needed. otherwise it errors things like shutdown -Bp */
  if(environment())
  inv = all_inventory(environment());
  x = sizeof(inv);
  while(x-- && !found)
  {
    if(inv[x]->is_player())
    {
      attack_object(inv[x]);
      found = 1;
    }
  }
  call_out("aggro", 2);
}

chase()
{
  object ob;
  object env;
  if((!attacker_ob || !present(attacker_ob, environment())) && (ob = Remembered))
  {
    if(!present(ob, environment()))
    {
      env = environment(ob);
      tell_room(env,
        query_name()+" appears, stalking "+ob->query_name()+"!\n");
      move_object(this_object(), env);
      attack_object(ob);
    }
  }
  call_out("chase", 2);
}

wound()
{
  if(!present("jason_wound", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "Jason separates flesh from bone with his machete!\n");
    ob = clone_object("/players/chip/items/movies/jason_wound");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}

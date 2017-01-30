/*  Same numbers as dealer, still holds money, more thematic */
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int *tox, *cost, *heal, moolah;
string *type, *nme, mo;
object robe;

reset(arg) {
   ::reset(arg);
   if (!arg) {

   tox = allocate(6);  /* the amount it toxes */
   tox[0] = 7;    tox[1] = 7;
   tox[2] = 7;    tox[3] = 7;
   tox[4] = -7;   tox[5] = -7;

   cost = allocate(3);  /*  the coin cost */
   cost[0] = 318;
   cost[1] = 318;
   cost[2] = 260;

   type = allocate(6);  /*  what type of heal is toxed */
   type[0] = "eat_food";   type[1] = "drink_soft";
   type[2] = "eat_food";   type[3] = "drink_soft";
   type[4] = "eat_food";   type[5] = "drink_soft";

   heal = allocate(6);
          /* hp              sp  healing factor*/
   heal[0] = 0;     heal[1] = 50;
   heal[2] = 50;    heal[3] = 0;
   heal[4] = 0;     heal[5] = 0;

   nme = allocate(12);      /* the name(s) of each heal */
   nme[0] = "light blue";    nme[1] = "1";
   nme[2] = "dark brown";    nme[3] = "2";
   nme[4] = "soft yellow";   nme[5] = "3";

  moolah = 2000;

  robe = clone_object("/obj/armor.c");
  robe -> set_name("robe");
  robe -> set_short(HIW+"A long white hooded robe"+NORM);
  robe -> set_long(
    "This long white hooded robe looks very soft and comfortable to\n"+
    "wear.  The hood is very long and is meant to drape over the\n"+
    "wearer's head.  This robe once belonged to an ancient druid\n"+
    "who lived only to help others.\n");
  robe -> set_weight(1);
  robe -> set_ac(4);
  move_object(robe, this_object());
  init_command("wear robe");

  set_name("druid");
  set_alias("man");
  set_short("An old druid");
  set_long(
"Before you stands a man cloaked in a white robe.  He is wearing the hood\n"+
"over his head which hides most of his head.  His face is white and pale,\n"+
"and seems to exude caring and warmth.  He has a long white beard that\n"+
"reminds you of the purest snow.  The druid has a number of elixers for\n"+
"sale, 'ask' him for more info.\n");
  set_level(19);
  set_race("human");
  set_ac(14);
  set_hp(1010);
  set_wc(28);
  add_money(2000);
  set_gender("male");
  set_heal(15,1);
  set_chat_chance(3);
  set_a_chat_chance(5);
  load_chat("The old druid smiles softly.\n");
  load_chat("The old druid says, \"Hello traveler.\"\n");
  load_chat("The old druid asks, \"Hello there, how are you?\"\n");
  load_chat("The old druid looks off to the north.\n");
  load_chat("The old druid smiles as he looks around.\n");
  load_chat("The old druid says, \"I have some elixers for sale.\"\n");
  load_chat("The old druid asks, \"Are you hurt?\"\n");
  load_a_chat("The old druid says, \"This is not right.\"\n");
  load_a_chat("The old druid asks, \"Why must you cause pain?\"\n");
  load_a_chat("The old druid asks, \"Do you believe in Fate?\"\n");
  set_dead_ob(this_object());
   }
}


void init(){
  ::init();
  add_action("ask_cmd", "ask");
  add_action("buy_cmd", "buy");
}

monster_died(){
  write_file("/players/zeus/log/dealer",
  ctime(time())+" - "+capitalize((string)attacker_ob->query_real_name())+
  " [L "+attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed the dealer with "+moolah+" coins.\n");
}

status ask_cmd(string str)
{
  if(str != "man" && str != "druid") return 0;
  write("The druid smiles softly and says....\n"+
    "   \"I have some splendid elixers for sale if you are feeling ill.\"\n"+
    "   \"Here is what I have for sale...\"\n\n"+
    "\t"+nme[1]+"\t"+capitalize(nme[0])+" elixer\t"+cost[0]+" coins\n"+
    "\t"+nme[3]+"\t"+capitalize(nme[2])+" elixer\t"+cost[1]+" coins\n"+
    "\t"+nme[5]+"\t"+capitalize(nme[4])+" elixer\t"+cost[2]+" coins\n"+
    "\n   \"You may 'buy' any of the above.\"\n\n");
  return 1;
}

void catch_tell(string str){
  string x;
  if(sscanf(str, "%s arrives%s", x))
  {
    if(present("corpse", environment()))
    {
      tell_room(environment(),
        "The druid disposes of the corpse.\n");
      destruct(present("corpse", environment()));
    }
    if(present("coins", environment()))
    {
      move_object(present("coins", environment()), this_object());
      tell_room(environment(),
        "The druid bends down and takes the coins.\n");
    }
  }
}

seizure(){    /*  bad reaction, chance of death */
  int flaw;
  flaw = (int)this_player()->query_attrib("luc");
  if(19 <= random(flaw))
  {
    tell_object(this_player(), "You suddenly feel very lucky.\n");
    this_player()->heal_self(100);
    write_file("/players/zeus/log/dealer",
      ctime(time())+" - "+TP->QN+" [L "+TP->query_level()+
      "+"+TP->query_extra_level()+"] got lucky.\n");
    return 1;
  }
  tell_room(environment(),
    "\nSuddenly "+TP->QN+"'s body is wracked by a seizure...\n"+
    TP->QN+" shakes violently as "+TP->PRO+" lays on the floor...\n"+
    "As "+TP->QN+" slams about, pain visible on "+TP->POS+" face.\n\n",
    ({ this_player() }));
  tell_object(this_player(),
    "\n\n\nSuddenly your body is wracked by a seizure...\n"+
    "You shake violently as you lay on the floor...\n"+
    "As you slam about, pain consumes your body.\n\n");
  this_player()->hit_player(100+random(120));
  this_player()->add_spell_point(-50-random(25));
  if((int)this_player()->query_sp() < 0)
    this_player()->add_spell_point(this_player()->query_sp());
  if(!this_player()->query_ghost())
    move_object(clone_object("/players/zeus/dealer/heart_attack.c"),
    this_player());
  write_file("/players/zeus/log/dealer",
    ctime(time())+" - "+TP->QN+" [L "+TP->query_level()+
    "+"+TP->query_extra_level()+"] had a seizure ");
  if(this_player()->query_ghost())
    write_file("/players/zeus/log/dealer", "and died.\n");
  else 
    write_file("/players/zeus/log/dealer", "but didn't die.\n");
}

status go(string w, int cash, string t1, string t2, int tox1, int tox2,
          int hp, int sp)
{
  int h, mh, s, ms;
  if(this_player()->query_attack())
  {
    tell_object(this_player(),
      "The druid says, \"You look a little busy, come back later.\"\n");
    return 1;
  }
  if((int)this_player()->query_money() < cash)
  {
    tell_object(this_player(), 
      "The druid says, \"I'm afraid you don't have enough money.\"\n");
    return 1;
  }
  if(call_other(this_player(), t1, tox1) &&
     call_other(this_player(), t2, tox2))
  {
    h = (int)this_player()->query_hp();
    mh = (int)this_player()->query_mhp();
    s = (int)this_player()->query_sp();
    ms = (int)this_player()->query_msp();
    this_player()->add_money(-cash);
    this_object()->add_money(cash);
    moolah += cash;
    this_player()->add_hit_point(hp);
    this_player()->add_spell_point(sp);
    tell_room(environment(), 
      this_player()->query_name()+" pays the druid some money.\n"+
      "The druid fixes a "+w+" drink for "+this_player()->query_name()+
      " which "+this_player()->query_pronoun()+" guzzles down.\n",
      ({ this_player() }));
    tell_object(this_player(),
      "The druid fixes a "+w+" drink for you.\n"+
      "You guzzle it down and feel better.\n"+HIW);
    command("mon", this_player());
    tell_object(this_player(), NORM);
    if(0 == random(1500))  /*  chance of death */
      seizure();
  }
  else {
    tell_object(this_player(),
      "The druid says, \"I think you've had enough already.\"\n");
  }
  return 1;
}

buy_cmd(str){
  if(str == nme[0] || str == nme[1]){
    if(!go(nme[0], cost[0], type[0], type[1], tox[0], tox[1],
      heal[0], heal[1]))
      return 1;
    return 1;
  }
  else if(str == nme[2] || str == nme[3]){
    if(!go(nme[2], cost[1], type[2], type[3], tox[2], tox[3],
      heal[2], heal[3]))
      return 1;
    return 1;
  }
  else if(str == nme[4] || str == nme[5]){
    if(!go(nme[4], cost[2], type[4], type[5], tox[4], tox[5],
      heal[4], heal[5]))
      return 1;
    return 1;
  }
  else return 0;
  return 1;
}

void heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(attacker_ob == this_object())
  {
    stop_fight();
    stop_fight();
    weapon_class = 100;
  }
  if(0 == random(12))
  {
    tell_object(attacker_ob,
      "\nThe druid whispers softly...\n\n\n\t\t"+HIR+
      "YOU ARE TORN FROM WITHIN!\n\n\n"+NORM);
    tell_room(environment(attacker_ob),
      "The druid whispers softly...\n", ({ attacker_ob }));
    attacker_ob->hit_player(200);
  }
  if(!random(4))
  {
    tell_object(environment(),
      "The druid takes a drink from an elixer.\n");
    weapon_class += 4;
    armor_class += 1;
  }
}

heal_self(arg){
  if(arg < -10) arg = -10;
  ::heal_self(arg);
  return 1; 
}

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int *tox, *cost, *heal, x, moolah;
string *type, *nme, mo;

reset(arg) {
  if(money)
   add_money(-query_money());
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

   x = random(6);  switch(x){
   case 0: mo = "orange"; break;
   case 1: mo = "yellow"; break;
   case 2: mo = "red";    break;
   case 3: mo = "pink";   break;
   case 4: mo = "purple"; break;
   case 5: mo = "green";  break; }
   
  moolah = 2000;

  set_name("man");
  set_short("A man wearing a neon "+mo+" jumpsuit");
  set_long(
"The man standing before you, you find is very hard not to look at.  He\n"+
"is wearing what might just be the brightest outfit you have ever seen.\n"+
"He is neon "+mo+" from head to toe, including his shoes and hat.  He\n"+
"has a small table set up with numerous colorful beakers and needles lying\n"+
"across it.  He seems to be selling chemicals, 'ask' him for more info.\n");
  set_level(19);
  set_race("human");
  set_ac(14);
  set_hp(1010);
  set_wc(28);
  add_money(2000);
  set_gender("male");
  set_chat_chance(3);
  set_a_chat_chance(5);
  set_heal(10,1);
  set_chat_chance(4);
  load_chat("The man grins at you.\n");
  load_chat("The man looks off to the north.\n");
  load_chat("The man smiles as he looks around.\n");
  load_chat("The man asks, \"How ya doin, pal?\"\n");
  load_chat("The man asks, \"Wanna buy somethin?\"\n");
  load_chat("The man sways slightly, then grins like a goofball.\n");
  load_chat("The man glances down at the table.\n");
  load_a_chat("The man asks, \"Hey man, wassup with this shit?\"\n");
  load_a_chat("The man ways, \"Dude, what'd I ever do to your ass?\"\n");
  load_a_chat("The man looks very angry and distressed.\n");
  load_a_chat("The man injects some liquid into his arm.\n");
  set_dead_ob(this_object());
} }

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

status ask_cmd(string str){   /*  get info on the heals */
  if(str != "man") return 0;
  write("The man smiles and says....\n"+
    "   \"Got some terrific chemicals here...\"\n"+
    "   \"Will leave ya feelin awesome...\"\n\n"+
    "\t"+nme[1]+"\t"+capitalize(nme[0])+" liquid\t"+cost[0]+" coins\n"+
    "\t"+nme[3]+"\t"+capitalize(nme[2])+" liquid\t"+cost[1]+" coins\n"+
    "\t"+nme[5]+"\t"+capitalize(nme[4])+" liquid\t"+cost[2]+" coins\n"+
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
        "The man disposes of the corpse.\n");
      destruct(present("corpse", environment()));
    }
	if(present("coins", environment()))
    {
      move_object(present("coins", environment()), this_object());
      tell_room(environment(),
        "The man bends over and takes the coins.\n");
    }
  }
}

seizure(){    /*  bad reaction, chance of death */
  int flaw;
  object vrv;
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
  {
    vrv = clone_object("/players/zeus/dealer/heart_attack.c");
    vrv->setv(this_player());
    move_object(vrv, this_player());
  }
  write_file("/players/zeus/log/dealer",
    ctime(time())+" - "+TP->query_real_name()+" [L "+TP->query_level()+
    "+"+TP->query_extra_level()+"] had a seizure ");
  if(this_player()->query_ghost())
    write_file("/players/zeus/log/dealer", "and died.\n");
  else 
    write_file("/players/zeus/log/dealer", "but didn't die.\n");
}

heart_attack(){    /* very bad reaction, death */
  int moo, flaw;
  flaw = (int)this_player()->query_attrib("luc");
  if(19 <= random(flaw))
  {
    tell_object(this_player(), "You suddenly feel very, very lucky.\n");
    this_player()->heal_self(100);
    write_file("/players/zeus/log/dealer",
      ctime(time())+" - "+TP->QN+" [L "+TP->query_level()+
      "+"+TP->query_extra_level()+"] got very, very lucky.\n");
    return 1;
  }
  tell_room(environment(),
    "\nSuddenly "+TP->QN+" clutches "+TP->POS+" chest...\n"+
    TP->QN+" falls to the ground as pain engulfs "+TP->POS+" body.\n\n",
    ({ this_player() }));
  tell_object(this_player(),
    "\n\n\nSuddenly you find breathing impossible...\n"+
    "You clutch your chest as your collapse to the ground...\n"+
    "All goes black as pain engulfs you.\n\n");
  this_player()->add_hit_point(-666);
  this_player()->hit_player(666);
  moo = (int)this_player()->query_sp();
  this_player()->add_spell_point(-moo);
  write_file("/players/zeus/log/dealer",
    ctime(time())+" - "+TP->QN+" [L "+TP->query_level()+
    "+"+TP->query_extra_level()+"] had a heart attack and died.\n");
}

status go(string w, int cash, string t1, string t2, int tox1, int tox2,
          int hp, int sp)
{
  int h, mh, s, ms;
  if(this_player()->query_attack())
  {
    tell_object(this_player(),
      "The man says, \"You look a little busy, come back later.\"\n");
    return 0;
  }
  if((int)this_player()->query_money() < cash)
  {
    tell_object(this_player(), 
      "The man says, \"You can't afford it, pal...  get lost.\"\n");
    return 0;
  }
  if(call_other(this_player(), t1, tox1) &&
     call_other(this_player(), t2, tox2))
  {
    h = (int)this_player()->query_hp();
    mh = (int)this_player()->query_mhp();
    s = (int)this_player()->query_sp();
    ms = (int)this_player()->query_msp();
    this_player()->add_money(-cash);
/*    this_object()->add_money(cash);   rmd 4/10 */
    moolah += cash;
    this_player()->add_hit_point(hp);
    this_player()->add_spell_point(sp);
    tell_room(environment(), 
      this_player()->query_name()+" pays the man some money.\n"+
      "The man swiftly injects a "+w+" liquid into "+
      this_player()->query_name()+"'s arm.\n", ({ this_player() }));
    tell_object(this_player(),
      "The man fills a syringe with a "+w+" liquid.\n"+
      "The man swiftly injects the liquid into your arm.\n"+
      "The liquid races through your body.\n\n");
    command("mon", this_player());
    if(0 == random(1500))  /*  chance of death */
      seizure();
/*    else if(0 == random(10000)) *//* death */
/*      heart_attack(); */
  }
  else {
    tell_object(this_player(),
      "The man says, \"Sorry pal, but you've had way too much already.\"\n");
    return 0;
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
  if( !random(14) && present(attacker_ob, environment()) )
  {
    tell_object(attacker_ob,
      "\nThe man stabs you over and over with a needle!\n\n");
    tell_room(environment(attacker_ob),
      "The man explodes in rage!\n", ({ attacker_ob }));
    attacker_ob->hit_player(200);
  }
  if(!random(4))
  {
    tell_object(environment(),
      "The man injects himself with drugs.\n");
    weapon_class += 4;
    armor_class += 1;
  }
}

heal_self(arg){
  if(arg < -10) arg = -10;
  ::heal_self(arg);
  return 1; 
}


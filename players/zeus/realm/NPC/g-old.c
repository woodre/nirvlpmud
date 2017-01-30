/*  Barter item values:

    item                   npc                value

  lions mane        ~/NPC/lion1.c           3000 - 5000
  gorilla hand      ~/NPC/gorilla1.c        3000 - 5000
  bear tuft         ~/NPC/bear1.c           3000 - 5000
  snake skin        ~/NPC/snake1.c          800  - 1000
  wolf hair         ~/NPC/wolf1.c           2700 - 4200
  demons heart      ~/NPC/demon_large.c
                    ~/NPC/demon_planar.c    5000 - 7000
  demons tooth      ~/NPC/demon_planar.c    3000 - 7000
  demon gore        ~/NPC/demon_medium.c    500  - 2500
  ruby              ~/NPC/hunter.c          2500 - 3000
  beast claws       ~/x/NPC/beast.c         3500 - 5700
  dagger            ~/x/NPC/bandit.c        2000

  gator tooth       verte/swamp/OBJ/gator_tooth.c  800  - 999
  young g tooth     verte/swamp/OBJ/young_tooth.c  4000 - 5999

  pouch items get 75% of original value (must barter whole pouch).

*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define YOU capitalize((string)this_player()->query_real_name())
object pouch;
int guard_help, laa, mem;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  guard_help = 1;  /*  has one guard */

  set_name("gurther");
  set_short("A very old gurther");
  set_race("gurther");
  set_gender("male");
  set_long(
"This gurther is the oldest one that you have seen.  His black skin is\n"+
"very shiny, although it hangs much looser on his body than the other\n"+
"gurthers.  One of the two horns on the top of his head is broken in half.\n"+
"He is sitting down, and almost looks like he is asleep, he is so very\n"+
"peaceful.  He probably has many stories to tell, and he looks like he\n"+
"might be willing to 'barter' for certain collectable items, or sell\n"+
"others.  Ask him for a 'list' of what you can buy.\n");
  set_level(21);
  set_ac(30);
  set_wc(40);
  set_hp(1300);
  set_al(100);
  set_heal(4,1);
  set_chat_chance(5);
  set_a_chat_chance(1);
  load_chat("The gurther smiles softly at you.\n");
  load_chat("The gurther looks at you tenderly.\n");
  load_chat("The gurther asks: Do you have anything to barter?\n");
  load_chat("The gurther says: I am the eldest of the gurthers.\n");
  load_chat("The gurther sits peacefully in the grass.\n");
  load_chat("The gurther watches you closely.\n");
  load_chat("The gurther says: Would you like to hear a story?\n");
  load_chat("The gurther says: You can ask me to hear a story.\n");
  load_chat("The gurther says: You can 'ask' me about the Fallen Lands.\n");
  load_a_chat("The gurther says: One of us shall meet their fate now.\n");
  set_dead_ob(this_object());
   }
}


void init(){
	::init();
    add_action("barter_cmd", "barter");
    add_action("ask_cmd", "ask");
    add_action("list_cmd", "list");
    add_action("add_comp", "purchase");
    add_action("add_comp", "buy");
}

status list_cmd(string str){
  write("The old gurther smiles at you and says...\n"+
    "Here is what I have for sale:\n\n"+
"\tcomponent pouch\t\t500\n"+
"\tblack pearl\t\t1000\n"+
"\tcrow feather\t\t100\n"+
"\tdark orb\t\t400\n"+
"\tbone powder\t\t600\n"+
"\tspider web\t\t400\n"+
"\tdark root\t\t800\n"+
"\tash blossom\t\t1000\n"+
"\tgeode\t\t\t200\n"+
"\truby red gem\t\t2000\n"+
"\tblack liquid\t\t400\n"+
"\tshadow gem\t\t6000\n"+
"\tblack leaf\t\t1000\n"+
"\tscroll of restoration\t10000\n"+
"\n"+
"To purchase most items, you will need a component pouch...\n"+
"Just type 'purchase <amount> <what>' [eg: purchase 6 orbs]\n"+
"Also, you can 'barter pouch' if you have items leftover.\n");
	return 1;
}

no_have(string str){
    write("The gurther says: You don't have a "+str+"...\n");
	return 1;
}

status barter_cmd(string str){
int num, pouchvalue;
object ob;
string str1,str2,str3;

if(!str) {  write("The gurther asks: What?\n");  return 1; }

if(str == "mane") {					/*  lions mane  */
  ob = present("lions mane",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/lionmane") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 3000 + random(2000);
  TR(environment(),"The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the lion's mane from you.  He stares\n"+
"at it intently for a few moments, then puts it aside.  The gurther\n"+
"reaches out and hands you "+num+" coins in exchange for the lion's mane.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "hand"){				/*  gorilla hand  */
  ob = present("gorilla hand",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/gorhand") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 3000 + random(2000);
  TR(environment(),"The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the gorilla hand from you.  He looks\n"+
"it over before putting it aside.  He then hands you "+num+" coins.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "fur" || str == "tuft"){				/*  bear tuft of fur  */
  ob = present("fur",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/beartuft") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 3000 + random(2000);
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the tuft of brown bear fur from you.  He\n"+
"stares at intently, turning it over in his hands.  He then sets it down\n"+
"and smiles, handing you "+num+" coins in exchange for it.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "skin" || str == "snake skin"){			/*  snake skin  */
  ob = present("snake skin",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/snakeskin") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 800 + random(200);
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the snake skin from you.  He handles it\n"+
"as though it was as delicate as a newborn baby.  He gently sets it aside\n"+
"and smiles at you, handing you "+num+" coins in exchange for it.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "hair" || str == "wolf hair"){			/*  wolf hair  */
  ob = present("wolf hair",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/wolfhair") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 2700 + random(1500);
  TR(environment(), "The gurther buys a "+str+" from "+TP->QN+".\n",
	  ({ TP }));
  write(
"The gurther takes the wolf hair from you, examining it closely.  He\n"+
"looks up and with a smile, offers you "+num+" coins for it.  You gladly\n"+
"take it, as he sets the wolf hair behind him.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "heart" || str == "demons heart"){		/*  demons heart  */
  ob = present("demons heart",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/heals/demon_heart") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  if(ob->query_bites() < 3){
	  tell_object(TP,
		  "The gurther says:  It's half eaten!\n");
	  return 1;  }
  num = 5000 + random(2000);
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the demons heart from you.  Holding it\n"+
"in his hands, he gets a sickeningly evil grin upon his face.  He sets\n"+
"it behind him and reaches out, handing you "+num+" coins for it.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "ruby" || str == "red ruby"){		/*  ruby  */
  ob = present("zeus_red_ruby",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/ruby") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 2500 + random(500);
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the demons heart from you.  Holding it\n"+
"in his hands, he gets a sickeningly evil grin upon his face.  He sets\n"+
"it behind him and reaches out, handing you "+num+" coins for it.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "claws" || str == "beast claws"){		/*  beast claws  */
  ob = present("beast claws",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/x/OBJ/claws") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 3500 + random(2200);
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
    ({ TP }));
  write(
"The gurther takes the claws of the beast from you.  A sly grin sneaks\n"+
"across his face as he examines the claws.  The gurther offers you "+num+
"\ncoins in exchange for the claws, which you accept.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "gore" || str == "pile" || str == "demon gore"){ /*  demon gore  */
  ob = present("hot and yummy gore",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/demon_gore") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 500 + random(2000);
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
    ({ TP }));
  write(
"The gurther grimaces as he takes the pile of gore from you.  He\n"+
"glances quickly at it as he puts it aside.  Then with a barely\n"+
"visible smile he pays you "+num+" coins for the rare item.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "dagger" || str == "cursed dagger"){		/*  dagger  */
  ob = present("guild_dagger",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/circle/OBJ/dagger") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  num = 2000;
  if(ob->query_cursed())
	  num = 500;
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther takes the dagger from you.  He looks at it briefly before\n"+
"giving you "+num+" coins for it.\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }
                                           /*  verte's tooth, demon tooth  */
if(str == "tooth" || str == "gator tooth" || str == "demon tooth"){
  int tog;
  tog = 0;
  ob = present("tooth",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 == "players/vertebraker/swamp/OBJ/gator_tooth")
    num = 4000 + random(2000);  /* expensive */
  else if(str2 == "players/vertebraker/swamp/OBJ/young_tooth")
    num = 800 + random(200);    /* cheap */
  else if(str2 == "players/zeus/realm/OBJ/demon_tooth")
  {
    tog = 1;  /* is a demon tooth */
    num = 3000 + random(4000);
  }
  else {
    write("The gurther says: You don't have that...\n");
    return 1; }
  TR(environment(), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  if(tog == 0)
  {
    write(
    "The gurther takes the sharp gator's tooth from you, examining it\n"+
    "closely.  He seems fascinated by it.  When he is done, the old\n"+
    "gurther gives you "+num+" coins for it.\n");
  }
  else
  {
    write(
    "The gurther takes the demons tooth from your hand and stares intently\n"+
    "at it.  He seems to pay extra attention to the bloody stub.  He places\n"+
    "the tooth in a small pouch.  Reaching out, he hands you "+num+" coins\n"+
    "in exchange for the demons tooth.\n");
  }
  TP->add_money(num);
  destruct(ob);
  return 1; }
if(str == "horn"){			/*   can't barter horns, he gets mad  */
	object guard;
	guard = CO("/players/zeus/realm/NPC/gguard2.c");
  ob = present("horn",TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/realm/OBJ/ghorn.c") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  TR(environment(),
"The gurther says:  You dare kill my fellow gurthers?\n"+
"					For that you shall pay...\n\n"+
"A guard enters the room in a hurry.\n");
  MO(guard, environment(TO));
  destruct(ob);
  guard->set_ac(20);
  guard->set_wc(40+random(5));
  guard->attack_object(TP);
  return 1;
}
if(str == "pouch"){    /* barter all in pouch */
  ob = present("guild_comp_pouch", TP);
  if(!ob){ no_have(str); return 1; }
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/zeus/circle/OBJ/pouch") {
    write("The gurther says: You don't have that...\n");
    return 1; }
  pouchvalue = 0;
  pouchvalue += 375;
  pouchvalue += ((int)ob->query_feather() * 75);
  pouchvalue += ((int)ob->query_pearl() * 750);
  pouchvalue += ((int)ob->query_bpowder() * 500);
  pouchvalue += ((int)ob->query_leaf() * 750);
  pouchvalue += ((int)ob->query_root() * 600);
  pouchvalue += ((int)ob->query_orb() * 300);
  pouchvalue += ((int)ob->query_liquid() * 300);
  pouchvalue += ((int)ob->query_gem() * 750);
  pouchvalue += ((int)ob->query_web() * 300);
  pouchvalue += ((int)ob->query_sgem() * 4500);
  pouchvalue += ((int)ob->query_blossom() * 750);
  pouchvalue += ((int)ob->query_geode() * 150);
  /* zeus 7-11-05 */
  pouchvalue = (pouchvalue / 10);
  TR(environment(TP), "The gurther buys a "+str+" from "+YOU+".\n",
	  ({ TP }));
  write(
"The gurther smiles as he takes the pouch from you.  He opens it up\n"+
"and counts up all the items in it.  He sets it behind him, and with a\n"+
"smile, reaches out and hands you "+pouchvalue+" coins for it.\n");
  TP->add_money(pouchvalue);
  destruct(ob);
  return 1; }
}

guard_help(){
  object guard;
  guard = CO("/players/zeus/realm/NPC/gguard.c");
  if(!guard_help) return 0;
  say("A guard walks into the room...\n");
  MO(guard, environment());
  guard->attack_object(AO);
  guard_help = 0;
  return 1;
}

monster_died()
{
  object horn;
  horn = CO("/players/zeus/realm/OBJ/ghorn.c");
  write("With your final blow you break off the gurther's other horn.\n");
  horn->set_value(6000+random(1500));
  MO(horn, environment());  
return 1; 
}


status ask_cmd(string str){
  if(!str) return 0;
  if(str=="gurther" || str=="old gurther")
    call_out("tell_story", 1, this_player());
  return 1; 
}


tell_story(object cow){
  tell_object(cow,
"\nThe old gurther tells you:\n\n"+
"  This has always been the home of the Gurthers.  Many years ago though,\n"+
"  the Humans came.  We fought a long and hard war with them to keep our\n"+
"  home, but in the end they won and drove us out.  So for many years we\n"+
"  lived far away, beyond the water.  They were hard times.  When things\n"+ 
"  were looking their worst, the wizard Auseth came to us with a plan to\n"+
"  reclaim this area.  We let him lead us against the Humans, and he helped\n"+
"  to make all our dreams come true.  We are once again in the home that\n"+
"  has been ours for so long, and we owe it all to Auseth. So we know that\n"+
"  not all Humans are bad.\n\n");
TR(environment(), "The old gurther says something to "+cow->query_name()+
   ".\n", ({cow}));
  return 1; 
}


heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!attacker_ob) 
    return ;
  if(AO == TO){
    TR(environment(), 
      "The gurther shakes it off and keeps fighting...\n");
    TO->stop_fight();
    TO->stop_fight();
    return ;
  }
  hit_point += 20;
  if(!random(10)){  guard_help();   return;  }
}

buy_func(int value, int amount, string item){
  laa = 1;
  if(!pouch)
  {
    write("The gurther says:  You must have a pouch!\n");
    laa = 0;
    return 0;
  }
/* added 2/22/01 - punishment for exploiting a bug w/o reporting it */
  if((string)this_player()->query_real_name() == "cobain" &&
    (time() < 988261198)) /* lasts 62 days */
  {
	  write("The gurther says:  For you Cobain, it's going to cost a bit more.\n");
	  value = (value * 3);
  }
  if(TP->query_money() < (value * amount))
  {
    write("The gurther says:  Sorry, you can't afford it.\n");
    laa = 0;
    return 0;
  }
  if(laa)
  {
    write_file("/players/zeus/circle/log/COMP", ctime(time())+" - "+
      pad(this_player()->query_name(), 12)+
      pad(amount, 3)+" "+pad(item, 15)+
      pad(this_player()->query_money(), 6)+
      pad((value * amount), 6));
    if(present("circle_object", this_player()))
    {
      write_file("/players/zeus/circle/log/COMP",
      pad(present("circle_object", this_player())->query_guild_exp(), 8)+
      "\n");
    }
    else
      write_file("/players/zeus/circle/log/COMP", "\n");
    write("The gurther hands you "+amount+" "+item+".\n");
    TR(environment(),
      "The gurther hands "+TP->QN+" "+amount+" "+item+".\n", ({ TP }));
    /* next line added to prevent a fee component problem if gurther gets max coins */
    if(TO->query_money() > 20000) TO->add_money(-6666-random(6666));      
    TP->add_money(-(value * amount));
    TO->add_money((value * amount) / 3); /* changed to prevent free component bug */
  }
  return 1;
}

status add_comp(string str){
  string what;
  int amount, i;
  if(!str) return 0;
  if(sscanf(str, "%d %s", amount, what) || sscanf(str, "%s", what))
  {
    pouch = present("guild_comp_pouch", TP);
    if(!what)
    {
      TR(environment(), "The old gurther looks confused.\n");
      return 1;
    }
    if(!amount || amount <= 0)
      amount = 1;
    if(what == "pouch" || what == "component pouch" ||
      what == "pouches" || what == "component pouches")
    {
      if(TP->query_money() < (500 * amount))
      {
        write("The gurther says:  Sorry, you can't afford it.\n");
        return 1;
      }
      if(amount > 1)
      {
        write("The gurther hands you "+amount+" pouches.\n");
        TR(environment(), 
          "The gurther hands "+TP->QN+" "+amount+" pouches.\n", ({TP}));
      }
      else 
      {
        write("The gurther hands you "+amount+" pouch.\n");
        TR(environment(), 
          "The gurther hands "+TP->QN+" "+amount+" pouch.\n", ({TP}));
      }
      TP->add_money(-500 * amount);
      TO->add_money(500 * amount);
      for(i = 0; i < amount; i++)
        MO(CO("/players/zeus/circle/OBJ/pouch.c"), TP);
    }
    else if(what == "scroll" || what == "scroll of restoration" ||
      what == "scrolls" || what == "scrolls of restoration")
    {
      if(TP->query_money() < (10000 * amount))
      {
        write("The gurther says:  Sorry, you can't afford it.\n");
        return 1;
      }
      if(amount > 1)
      {
        write("The gurther hands you "+amount+" scrolls.\n");
        TR(environment(), 
          "The gurther hands "+TP->QN+" "+amount+" scrolls.\n", ({TP}));
      }
      else 
      {
        write("The gurther hands you "+amount+" scroll.\n");
        TR(environment(), "The gurther hands "+TP->QN+" "+amount+" scroll.\n", 
          ({TP}));
      }
      TP->add_money(-10000 * amount);
      TO->add_money(10000 * amount);
      for(i = 0; i < amount; i++)
        MO(CO("/players/zeus/circle/OBJ/scroll.c"), TP);
    }
    else if(what == "crow feather" || what == "feather" ||
      what == "crow feathers" || what == "feathers")
    {
      if(buy_func(100, amount, what))
        pouch->buy_feather(amount);
    }
    else if(what == "black pearl" || what == "pearl" ||
      what == "black pearls" || what == "pearls")
    {
      if(buy_func(1000, amount, what))
        pouch->buy_pearl(amount);
    }
    else if(what == "bone powder" || what == "powder" ||
      what == "bone powders" || what == "powders")
    {
      if(buy_func(600, amount, what))
        pouch->buy_bpowder(amount);
    }
    else if(what == "black leaf" || what == "leaf" ||
      what == "black leaves" || what == "leaves")
    {
      if(buy_func(1000, amount, what))
        pouch->buy_leaf(amount);
    }
    else if(what == "dark root" || what == "root" ||
      what == "dark roots" || what == "roots")
    {
      if(buy_func(800, amount, what))
        pouch->buy_root(amount);
    }
    else if(what == "dark orb" || what == "orb" ||
      what == "dark orbs" || what == "orbs")
    {
      if(buy_func(400, amount, what))
        pouch->buy_orb(amount);
    }
    else if(what == "black liquid" || what == "liquid" ||
      what == "black liquids" || what == "liquids")
    {
      if(buy_func(400, amount, what))
        pouch->buy_liquid(amount);
    }
    else if(what == "ruby red gem" || what == "red gem" || 
      what == "ruby red gems" || what == "red gems")
    {
      if(buy_func(2000, amount, what))
        pouch->buy_gem(amount);
    }
    else if(what == "spider web" || what == "web" ||
      what == "spider webs" || what == "webs")
    {
      if(buy_func(400, amount, what))
        pouch->buy_web(amount);
    }
    else if(what == "shadow gem" || what == "shadow gems")
    {
      if(buy_func(6000, amount, what))
        pouch->buy_sgem(amount);
    }
    else if(what == "ash blossom" || what == "blossom" ||
      what == "ash blossoms" || what == "blossoms")
    {
      if(buy_func(1000, amount, what))
        pouch->buy_blossom(amount);
    }
    else if(what == "geode" || what == "geodes")
    {
      if(buy_func(200, amount, what))
        pouch->buy_geode(amount);
    }
    else return 0;
  }
  return 1;
}


void catch_tell(string str)
{
  string tmp1, tmp2, tmp3;
  object pd, ta, him, pc, *tinv, me2;
  int c, cnt;
  him = 0; cnt = 0;
  if(sscanf(str, "%sstory%s\n", tmp1, tmp2, tmp3))
  {
    me = TP;
    if(me->is_player() && !me->query_attack())
      call_out("tell_story", 1, me);
  }
}

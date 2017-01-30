inherit "obj/monster";
  int LV,NA;

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
LV=(11+random(5));
NA=(random(8));
  if(NA==0) { set_name("fighter");
            set_short("A large fighter"); }
  if(NA==1) { set_name("halfling");
            set_short("A large halfling"); }
  if(NA==2) { set_name("tribesman");
            set_short("A large tribesman"); }
  if(NA==3) { set_name("santulli");
            set_short("A large santulli"); }
  if(NA==4) { set_name("brawler");
            set_short("A large brawler"); }
  if(NA==5) { set_name("warrior");
            set_short("A large warrior"); }
  if(NA==6) { set_name("minion");
            set_short("A large minion of evil"); }
  if(NA==7) { set_name("wildman");
            set_short("A large wildman"); }
    set_race("human");
    set_alias("gladiator");
    set_long("Arena gladiators aren't much to look at!\n");
    set_level(LV);
    set_hp(LV*15);
    set_al(750-random(1500));
    set_wc(4+LV);
    set_ac(15+random(4));
    set_chat_chance(20);
    set_a_chat_chance(10);
load_chat("Gladiator says: Let's get on with it!\n");
load_a_chat("Gladiator asks: Is that the best you can do?\n");
  coins=clone_object("obj/money");
  coins->set_money(random(500)+250);
  move_object(coins,this_object());
}

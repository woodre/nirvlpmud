/*  GLAD4.C - Loads into ARENA.C  Uses random numbers to set level,
    alignment, and short description.  The int LV is used to set
    WC and AC to correct number for level.
*/
inherit "obj/monster";
int LV,NA;

reset(arg) {
  object coins;
  ::reset(arg);
  if(arg) return;
  LV=(16+random(5));
  NA=(random(8));
  write_file("/players/traff/work/log/GONG","  Cloned level "+LV+" monster.\n");
  if(NA==0) { set_name("fighter");
            set_short("A HUGE fighter"); }
  if(NA==1) { set_name("halfling");
            set_short("A HUGE halfling"); }
  if(NA==2) { set_name("tribesman");
            set_short("A HUGE tribesman"); }
  if(NA==3) { set_name("santulli");
            set_short("A HUGE santulli"); }
  if(NA==4) { set_name("brawler");
            set_short("A HUGE brawler"); }
  if(NA==5) { set_name("warrior");
            set_short("A HUGE warrior"); }
  if(NA==6) { set_name("minion");
            set_short("A HUGE minion of evil"); }
  if(NA==7) { set_name("wildman");
            set_short("A HUGE wildman"); }
  set_race("human");
  set_alias("gladiator");
  set_long("Arena gladiators aren't much to look at!\n");
  set_level(LV);
  set_hp(LV*25);
  set_al(1000-random(2000));
  set_wc(8+LV);
  set_ac(15+random(3));
  set_chat_chance(5);
  set_a_chat_chance(10);
  load_chat("Gladiator says: Let's get on with it!\n");
  load_chat(cap_name+" dances around!\n");
  load_chat(cap_name+" glares at you!\n");
  load_chat(cap_name+" winks at you!\n");
  load_chat(cap_name+" slaps you silly!\n");
  load_chat(cap_name+" looks bored.\n");
  load_chat(cap_name+" eats a hunk of honeycomb.\n");
  load_chat(cap_name+" says:  Go away!\n");
  load_chat(cap_name+" says:  Who rang the gong?\n");
  load_chat(cap_name+" says:  Well, now what?\n");
  load_chat("The crowd cheers.\n");
  load_chat("The crowd boos.\n");
  load_chat(cap_name+" tries to sneak around behind you.\n");
  load_chat("A bird swoops down and perches on the gong.\n");
  load_chat("A bird flies off towards the forest.\n");
  load_a_chat("Gladiator asks: Is that the best you can do?\n");
  coins=clone_object("obj/money");
  coins->set_money(random(1500)+1500);
  move_object(coins,this_object());
}

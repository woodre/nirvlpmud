/*Monster created to show damage done.*/
 
inherit "/obj/monster";
 
int thp, totac, rcount;
int testing, highdam, showac;
int hcount, odam, ocount, todam, oave;
int show_hp, show_dam, show_ave, show_hits, show_tot,
    show_high, show_odam, show_ocount, show_todam, show_oave;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("testmonster");
     set_short("A test monster");
     set_race("monster");
     set_alias("test");
     set_long(
"A monster that shows damage done.\n");
     set_level(1);
     set_ac(0);
     set_wc(0);
     set_hp(5000);
     set_heal(0,100);
     set_al(0);
     set_aggressive(0);
thp = 5000;
   }
}
 
init() {
  ::init();
  add_action("reset_me","testreset");
  add_action("testall","testall");
  add_action("test","test");
}
 
hit_player(num) {
  int to_ret, will_ocount;
  if(!this_player()) {
    will_ocount = hit_point;
    to_ret = ::hit_player(num);
    odam = will_ocount - hit_point;
    todam += will_ocount - hit_point;
    ocount ++;
    oave = todam/rcount;
    will_ocount = 0;
    return to_ret; }
  return ::hit_player(num); }
 
test_show() {
  int chp,diff,average;
  chp = this_object()->query_hp();
  diff = ( thp - chp );
  average = ( (5000 - chp) / rcount );
  if(highdam < diff) highdam = diff;
  if(show_hp) say("THP <"+chp+"> ");
  if(show_dam) say("DAM <"+diff+"> ");
  if(show_ave) say("AVE DAM <"+average+"> ");
  if(show_hits) say("HITS <"+rcount+"> ");
  if(show_tot) say("TOT DAM <"+(5000-chp)+"> ");
  if(show_high) say("HIGH DAM <"+highdam+"> ");
  say("\n");
  if(show_odam) say("ODAM <"+odam+"> ");
  if(show_todam) say("TODAM <"+todam+"> ");
  if(show_ocount) say("OHITS <"+ocount+"> ");
  if(show_oave) say("OAVE <"+oave+"> ");
  if(showac && attacker_ob) show_ac(attacker_ob);
  say("\n");
  thp = chp;
  odam = 0;
  if(testing && rcount == 51) stop_test();
  return 1; }

show_ac(object ob) {
  int hpold, hpnew, diff, average;
  hpold = ob->query_hp();
  if(ob->query_hp() > 50) ob->hit_player(15);
  hpnew = ob->query_hp();
  diff = hpold - hpnew;
  diff = 15 - diff;
  totac += diff;
  average = totac/rcount;
  say("\t"+ob->query_name()+" AC <"+diff+"> AVE AC <"+average+"> REAL AC <"+(average*2+1)+">\n");
  ob->add_hit_point(20);
  return 1; }

heart_beat() {
  ::heart_beat();
  if(attacker_ob) rcount ++;
  if(attacker_ob) test_show();
  return 1;
}

reset_me() {
  rcount = 0; thp = 5000;
  ocount = 0; todam = 0;
  totac = 0;
  highdam = 0;
  this_object()->heal_self(5000);
  write("TESTMONSTER RESET.\n"); return 1; }

testall() {
  if(this_player()->query_level() > 19) set_show_all(); return 1; }

test(string str) {
  if(str == "ac") showac = 1;
  if(str == "all") set_show_all();
  testing = 1;
  this_player()->attack_object(this_object());
  return 1; }

stop_test() {
  object ob;
  ob = attacker_ob;
  if(!ob) return;
  ob->stop_fight(); ob->stop_fight();
  ob->stop_hunter(); ob->stop_hunter();
  stop_fight(); stop_fight();
  stop_hunter(); stop_hunter();
  tell_room(environment(this_object()), "TEST OVER\n");
  testing = 0;
  showac = 0;
  return 1; }

set_show_hp(num) { show_hp = num; }
set_show_dam(num) { show_dam = num; }
set_show_ave(num) { show_ave = num; }
set_show_hits(num) { show_hits = num; }
set_show_tot(num) { show_tot = num; }
set_show_high(num) { show_high = num; }
set_show_odam(num) { show_odam = num; }
set_show_todam(num) { show_todam = num; }
set_show_ocount(num) { show_ocount = num; }
set_show_oave(num) { show_oave = num; }
set_show_all() { show_hp = 1; show_dam = 1; show_ave = 1;
                 show_hits = 1; show_tot = 1; show_high = 1;
                 show_todam = 1; show_odam = 1; show_ocount = 1; show_oave = 1; }

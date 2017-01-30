/*Monster created to show damage done.*/
 
inherit "/obj/monster";
 
int round_dam, total_dam, beats, too_much, hit_count, 
    hit_3count, hit_2count;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("testmonster");
     set_short("A test monster");
     set_race("monster");
     set_alias("test");
     set_long("'tak <monster>' to start it.\n");
     set_level(1);
     set_ac(0);
     set_wc(0);
     set_hp(2000);
     set_heal(0,100);
     set_al(0);
     set_aggressive(0);
   }
}
 
init() {
  ::init();
  add_action("mon_attack","tak");
}
 
mon_attack(arg) {
  object meat;
  string name, meatname, moname;
  beats = 0;
  meat = present(arg,environment(this_object()));
  name = capitalize(this_player()->query_real_name());
  meatname = capitalize(arg);
  moname = this_object()->query_real_name();
  if(!meat) { say(meatname+" is not here!\n"); return 1; }
  if(living(meat)) {
    call_other(meat,"attack_object",this_object());
  }
  test_show();
  return 1;
}
 
test_show() {
  say(
  "   ROUND_DAM:    <"+round_dam+">\n"+
  "   AVE DAM:      <"+(total_dam/beats)+">\n"+
  "   BEATS:        <"+beats+">\n"+
  "   TOT DAM:      <"+total_dam+">\n"+
  "   2+ HITS:      <"+hit_2count+">\n"+
  " **3+ HITS:      <"+hit_3count+">\n"+
  " **OVER 50:      <"+too_much+">\n");
  if(hit_count > 1) hit_2count++;
  if(hit_count > 2) hit_3count++;
  hit_count = 0;
  round_dam = 0;
  return 1;
}

heart_beat() {
  ::heart_beat();
  if(attacker_ob) { beats++; test_show(); }
  return 1;
}

hit_player(int num) {
  if(num > 50) {
    too_much = too_much + 1;
    say(previous_object()->short()+" DID TOO MUCH DMG: "+num+".\n");
  }
  total_dam += num;
  round_dam += num;
  hit_count++;
}

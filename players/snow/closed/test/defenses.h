heal_self(arg) {
  if(arg < 0) {
    if(arg < -10) arg = -10; }
  ::heal_self(arg); }

check_self() {
  if(attacker_ob && attacker_ob->query_elemtestmon()) {
    attacker_ob->stop_fight(); attacker_ob->stop_fight();
    attacker_ob->stop_hunter();
    attacker_ob = 0; alt_attacker_ob = 0; hunter = 0;
    this_object()->heal_self(1000); }
  if(weapon_class < 20) set_wc(75);
  if(heal_intv > 1) set_heal(5,1);
  if(query_attack() && present("fear_link", query_attack()) )
    destruct(present("fear_link", query_attack()));
  if(query_attack() && present("reverse", query_attack()) )
    destruct(present("reverse", query_attack()));
  return; }

find_victim() {
  if(attacker_ob) return;
  if(testvic && environment(testvic) == environment(this_object())) {
    if(!random(5)) this_object()->attack_object(testvic); }
  return 1; }

set_testvic(object ob) { testvic = ob; }
query_vicname() {
  if(testvic) write(testvic->query_real_name()+"\n");
  else write("None\n");
  return 1; }

extra_xp(ob) {
  if(ob->is_player()) ob->add_exp(10000); }

query_limited_shadow() { return 1; }
query_elemtestmon() { return 1; }

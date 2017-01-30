inherit "/obj/monster";
  string owner, which;
reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_alias("trans");
 set_short("transobj");
 set_long("transobj.\n");
     set_level(1);
     set_ac(50);
     set_wc(0);
     set_hp(1000);
     set_al(0);
     set_aggressive(0);
  owner = "Nobody";
  which = "sixteen";
 set_heart_beat(1);
   }
}

id(str) { return str == owner+"'s tracer "+which; }
short() { return; }
set_owner(str) { owner = str; }
set_which(str) { which = str; }

heart_beat() {
   object attk;
  if(this_object()->query_attack()) {
   attk = this_object()->query_attacker();
   attk->stop_fight();
   this_object()->stop_fight();
   attk->stop_hunter();
   this_object()->stop_hunter();
   }
}

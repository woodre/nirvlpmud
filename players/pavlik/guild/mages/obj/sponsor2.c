inherit "obj/treasure";
  string sponsor1, sponsor2;

reset(arg) {
 if(arg) return;
  set_long("Mage Recruiter.\n");
  set_weight(0);
  set_value(0);
}

id(str){
  return str == "mage_sponsor2" || str == "mage_sponsorer2";
}

query_auto_load(){
  return "/players/pavlik/guild/mages/obj/sponsor2.c:"+
    sponsor1+"#"+sponsor2;
}

drop(){ return 1; }
query_sponsor1(){ return sponsor1; }
query_sponsor2(){ return sponsor2; }

set_sponsor1(str){ sponsor1 = str; }
set_sponsor2(str){ sponsor2 = str; }


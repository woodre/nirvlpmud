#include <ansi.h>
#define EN environment(this_object())

string stat;
int much;

reset(arg){
 if(arg || root())
   return;
 stat = "int";
 call_out("rid_this", 300+random(300));
}

short(){ return; }
long(){ write("a mages absorb_obj.\n"); return; }
id(str){ return str == "absorb_obj"; }
get(){ return 0; }
drop(){ return 1; }

set_stat(str){ stat = str; }
query_stat(){ return stat; }
set_much(i){ much = i; }
query_much(){ return much; }

rid_this() {
  object ob;
  if(!EN) return destruct(this_object());
  ob = present("mageobj", EN);

  if(!ob) {
    destruct(this_object());
    return 1;
  }

  if(stat == "allstats") {
    ob->add_int_bonus(-much);
    ob->add_wis_bonus(-much);
    ob->add_wil_bonus(-much);
    ob->add_pow_bonus(-much);
    ob->add_conj_bonus(-much);
    ob->add_ench_bonus(-much);
    ob->add_evoc_bonus(-much);
    ob->add_illu_bonus(-much);
    ob->add_necr_bonus(-much);
  }
  else {
    call_other(ob, "add_"+stat+"_bonus", -much);
  }
  tell_object(EN, "Your "+HIC+"Absorb"+NORM+" spell wears off.\n");
  ob->set_next_alter(time() + 300);
  destruct(this_object());
  return 1;
}


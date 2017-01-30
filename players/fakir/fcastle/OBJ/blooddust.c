#include "/players/fakir/color.h"
query_save_flag() { return 1; }
id(str) { return str == "blood dust" || str == "dust"; }
short() { return RED+"Blood Dust"+OFF; }
long() {
  write(
"A small pile of "+RED+"blood red dust"+OFF+" which when sniffed, invigorates\n"+
"and renews ones spiritual, mental, and physical health.\n");
return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
  add_action("sniff_dust","sniff");
}
int healnum;
reset(arg) {
  if(!arg) healnum = 3;
}
sniff_dust(str) {
  if(!str) { write("Sniff what?\n"); return 1; }
  if(str == "dust") {
    if(environment() != this_player()) return 0;
  write(
"As you sniff the dust, your mind, body, and soul rejoice!\n");
  if(healnum == 3) {
    write(
"The dust begins to decay in your hand..it will soon be gone.\n");
call_out("decay",150);
  }
  say(
capitalize(this_player()->query_name())+" sniffs some blood dust.\n");
call_other(this_player(),"heal_self",50);
  healnum --;
  if(healnum < 1) {
   write("Just in time, you sniff the last remaining particle of dust.\n");
     destruct(this_object()); this_player()->recalc_carry();
return 1;
  }
return 1;
  }
}
 
decay() {
  object ob;
  ob = environment();
  if(!ob) return;
  tell_object(ob, "The "+RED+"blood dust"+OFF+" decays in your hand!\n");
    destruct(this_object());
  if(ob->is_player()) ob->recalc_carry();
return 1;
}

quest_ob() { return 1; }

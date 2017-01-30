#include "/players/mythos/closed/guild/def.h"
object targ;
string big_oath;

id(str) {return str == "task7"; }

drop() {return 1;}
init() {
  if(tgl != 6 || tl < 15|| qtf < 10) {
    tell_object(tp,"Somthing growls at you!\n");
    tp->zap_object(tp);
    move_object(tp,"/room/church.c");
    destruct(this_object());
    return 1;}
  if(tp == ep) {
    targ = tp;
  }
  add_action("oath","oath");
}

reset(arg) {
  if(arg) return;
  call_out("dark",6);
}

dark() {
  if(!targ) return 1;
  tell_object(targ,"The Darkness around you rumbles.\n");
  call_out("dark2",10);
  return 1;
}

dark2() {
  if(!targ) return 1;
  tell_object(targ,"The Darkness Speaks:\n"+
                   "             You shall give me another oath.\n"+
                   "             And this oath will be reviewed.\n"+
                   "             Should this oath be broken or\n"+
                   "             found not strong enough, death\n"+
                   "             shall be given unto you!\n");
  tell_object(targ,"note: this oath is to be only given between you\n"+
                   "       and the darkness.  This oath must be an\n"+
                   "       oath of great proportion: \n"+
                   "       i.e. i shall kill icingdeath, or i will kill\n"+
                   "            1000 ryo, or i shall destroy the staff of\n"+
                   "            power 100 times.\n");
  tell_object(targ,"       In any case you will not gain the next level till\n"+
                   "       this oath of vengence is done: contact a GC or the\n"+
                   "       Prophet.\n"+
                   "type <oath> <what the oath is>\n");
  return 1;}
  
oath(str) {
  if(!str) return 0;
  big_oath = str;
  write("Are you sure that this is what you wish:\n"+
        str+"   <y/n> ");
  input_to("check");
return 1;}

check(str) {
  if(!str) {
  write("Are you sure that this is what you wish:\n"+
        str+"   <y/n> ");
  input_to("check");
  return 1;}
  if(str == "n" || str == "N") {
    write("Type oath <oath> again then.\n");
  return 1;}
  write_file("/players/mythos/closed/guild/BIGOATH",HIR+
             capitalize(targ->query_real_name())+NORM+BLU+"  "+big_oath+NORM+"\n");
  write("DONE!\n");
  if(targ)
  move_object(targ,"/players/mythos/closed/guild/assembly.c");
  destruct(this_object());
return 1;}

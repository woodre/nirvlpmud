#include "/players/mythos/closed/guild/def.h"
string short_str, long_str, alias_str, name_str;
string where_str, trigger, aner, first;
string xmes1, xmes2, xmes3, xmes4, xmes5;
int delayed, repeat, bcast, dest_m, extra, tim, et, stw, nn;
object listen;

id(str) {return str == "image" || str == "star" || str == alias_str || str == name_str;}

get() { return 0;}
drop() { return 1;}

short() {
 if(repeat > 0 && trigger == "any" || (!bcast && 
    tp->query_real_name() == trigger)) { 
   if(!(tp->query_npc())) { 
     if(stw) { short_str = xmes1; stw = 0;}
     else { short_str = first; stw = 1;} 
     tell_room(ep,"The image changes!\n");
     repeat = repeat -1;} }
     if(tp->query_real_name() == trigger && bcast && repeat > 0) {
     tell_object(tp,"You get a secondary messege:\n\n"+xmes1+"\n"); 
     repeat = repeat - 1;}
  return short_str; }
  
long() { write(long_str);}

set_short(str) { short_str = str;}
set_long(str) { long_str = str;}
set_name(str) { name_str = str; alias_str = str;}
set_alias(str) { alias_str = str;}
set_where(str) { where_str = str;}
set_delayed(dl) { delayed = dl; tim = dl;}
set_repeat(rp) { repeat = rp;}
set_first(str) { first = str;}
set_extra(ex) { extra = ex; et = ex;}
set_xmes1(str) { xmes1 = str;}
set_xmes2(str) { xmes2 = str;}
set_xmes3(str) { xmes3 = str;}
set_xmes4(str) { xmes4 = str;}
set_xmes5(str) { xmes5 = str;}
set_trigger(str) { trigger = str;}
set_bcast(bc) { bcast = bc;}
set_answ(str) { aner = str;}
set_dest(dt) { if(dt == 6) { dt = 1+random(5); } dest_m = dt;}

query_delayed() { return delayed;}
query_repeat() { return repeat;}
query_first() { return first; }
query_extra() {return extra;}
query_trigger() { return trigger;}
query_where() { return where_str;}
query_name() { return name_str;}
query_alias() { return alias_str;}
query_save_flag() { return 1;}

reset(arg) {
  if(arg) return;
  call_out("time",3);
  nn = 20;
  stw = 0;
}

init() {
  if(where_str != "here" && living(ep)) {
  add_action("invoke","invoke"); }
}

time() {
if(where_str != "here") { return 1;}
if(trigger != "none") { return 1;}
if(delayed != 0) { if(tim < 0) { tim = delayed;} }
else { call_out("destruct_method",600); return 1;}
if(tim == 0) {
if(repeat > -1) {
    if(stw) { short_str = xmes1; stw = 0;}
    else { short_str = first; stw = 1;} 
    if(repeat != 666) {
   repeat = repeat -1;} }
   else { call_out("destruct_method",10); return 1;}
}
tim = tim - 1;
call_out("time",3); 
}

invoke(str) {
  if(!str) { write("What?\n"); return 1;}
  if(str == "star") {
  if(aner == "all") {listen = environment(tp);}
  else {listen = tp;}
  write("You invoke the star.... \nIt flares with a cold light....\n");
  tell_object(listen,BOLD+"\nIMAGE\n\n"+NORM);
  tell_object(listen,first);
  call_out("images",6);
  return 1;}
}

images() {
if(listen) {
if(et < 1) { et = extra; tell_object(listen,BOLD+"\nIMAGE DONE\n\n"+NORM);
             this_object()->destruct_method();
             return 1;}
switch(et) {
case 1: tell_object(listen,xmes1); break;
case 2: tell_object(listen,xmes2); break;
case 3: tell_object(listen,xmes3); break;
case 4: tell_object(listen,xmes4); break;
case 5: tell_object(listen,xmes5); break;
}
et = et -1; }
call_out("images",6);
return 1;}
  

destruct_method() {
string mms;
if(!ep) return 1;
  if(dest_m == 1) { mms = "A blue light forms around the image....\n"+
                                 "Suddenly, the star shatters at a small touch!\n";
  }
  if(dest_m == 2) { mms = "The image vanishes!\n";
  }
  if(dest_m == 3) { mms = "The image slowly turns to mist and fades away.\n";
  }
  if(dest_m == 4) {  
  if(nn < 0) { mms = "The image flares with a brilliant blue light\n"+
                            "and is destroyed!\n"; }
  else { nn = nn - 1; call_out("destruct_method",3); return 1;}
  }
  if(dest_m == 5) { return 1;}
  if(trigger == "here") { tell_room(ep,mms); }
  else { tell_object(ep,mms); }
destruct(this_object());
return 1;}

query_shatter_proof() { return 1;}

#include "/obj/clean.c"
#include "/players/mythos/closed/ansi.h"

string short_desc, long_desc, info;
int save_flag, value, local_weight;
string name, alias_name, owner, sound1, sound2, sound3, sound4;
string send1, send2, messege;
int shop_dest_flag, follow, p, fly, f, mount, mn;
int noise,q;

id(str){return str == name;}
short() {write(short_desc);}
long() { write(long_desc);}
set_id(str) {local_weight = 1; name = str;}
set_alias(str) {alias_name = str;}
set_short(str) {short_desc = str; long_desc = "You see nothing special.\n";}
set_long(str) { long_desc = str;}

set_value(v) { shop_dest_flag = 1; value = v;}
set_weight(w) {local_weight = w;}
get() { return 0;}
drop() {return 0;}
query_value() { return value; }
query_weight() { return local_weight;}

init() {
    if(!mount) { return 1;}
    add_action("charge","kill");
}

charge(str) {
  if(!str) {write("What do you wish to kill?\n"); return 1;}
  if(!present(str,environment(this_player())))  {write(str+" is not here.\n"); return 1;}
  tell_room(environment(this_player()),capitalize(this_player()->query_name())+
           " screams: "+BOLD+"ATTACK!"+NORM);
  tell_room(environment(this_player()),"\n"+capitalize(this_player()->query_name())+
           " charges into battle on "+this_player()->query_possesive()+" "+short_desc+"!\n");}
           
save_thing(str){save_object(str); return 1; }
restore_thing(str){ restore_object(str);return 1; }
set_save_flag() {save_flag = 1;}
query_save_flag() {return 1; }

set_owner(str) {owner=str;}
set_follow(p) {follow=p;}
set_msg(str) {messege=str;}
set_fly(f) { fly=f; }
set_mounted(mn) { mount=mn;}
set_noise(q) { noise = q;}
set_sound1(str) {sound1 = str;}
set_sound2(str) {sound2 = str;}
set_sound3(str) {sound3 = str;}
set_sound4(str) {sound4 = str;}
set_send1(str) {send1 = str;}
set_send2(str) {send2=str;}

query_alias() {return alias_name;}
query_mount() {return mount;}
query_owner() {return owner;}
query_follow() {return follow;}
query_id() {return name;}
query_fly() {return fly;}
query_msg() {return messege;}
query_noise() {return noise;}
query_sound1() {return sound1;}
query_sound2() {return sound2;}
query_sound3() {return sound3;}
query_sound4() {return sound4;}
query_send1() {return send1;}
query_send2() {return send2;}

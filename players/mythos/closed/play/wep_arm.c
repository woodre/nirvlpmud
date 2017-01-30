#define SS "players/mythos/closed/play/WEPARM"
string what;
string type;
string nam;
int num;
int class;
static object now;
static int time;

id(str) { return str == "wep_arm"; }

reset(arg) {
  if(arg) return;
  move_object(this_object(),"/players/mythos/prac/test.c");
  what = ({""});
  type = ({""});
  nam = ({""});
  class = ({0});
  num = ({0});
  time = 0;
  now = ({0});
  call_out("setup",10);
}

init() { add_action("retrieve","retrieve"); }

setup() {
  if(!restore_object(SS)) save_object(SS);
set_heart_beat(1);
return 1; }

heart_beat() {
object w,i;
int h,j,k;
string mo;
if(time > 10) {
  w = users();
  for(h=0;h<sizeof(w);h++) {
    i = deep_inventory(w[h]);
    for(j=0;j<sizeof(i);j++) {
      if(i[j]->weapon_class() || i[j]->armor_class()) {
        if(member_array(i[j],now) == -1) {
          now += ({i[j]});
          sscanf(object_name(i[j]),"%s#%s",mo);
          if(member_array(mo,what) == -1) {
             what += ({mo});
             /*
             nam += ({i[j]->short()}); */
             if(i[j]->armor_class()) {
               type += ({"A"}); class += ({i[j]->armor_class()}); }
             else { type += ({"W"}); class += ({i[j]->weapon_class()}); }
             num += ({1});
          } else 
          num[member_array(mo,what)] = num[member_array(mo,what)] + 1;
         }
      }
    } }
  save_object(SS);
 time = 0; } else time = time + 1;
 }
 
retrieve(str) {
int o,p,l;
string msg,no;
string WH;
string TY;
string NA;
int CL;
int NU;
if(!str) { write("retrieve <type>\ntype = w or a\n"); return 1; }
if(sscanf(str,"%s %d",no,l) == 2) {} else no = str;
if(no != "a" && no != "w") return 0;
if(!l) { if(no == "a") write("ARMOR\n"); else write("WEAPON\n"); }
    else {
      if(no == "a") 
        write_file("/players/mythos/WEPARM","ARMOR "+ctime(time())+"\n");
      else write_file("/players/mythos/WEPARM","WEAPON "+ctime(time())+"\n"); }
  WH = what; TY = type; CL = class; NU = num; /* NA = nam; */
  for(o=0;o<sizeof(TY);o++) {
    if(no == "a" && TY[o] == "A") 
      msg = WH[o] + "   class: " +
            CL[o]+"  num: "+NU[o] +"\n";
    if(no == "w" && TY[o] == "W") 
      msg = WH[o] + "   class: " +
            CL[o]+"  num: "+NU[o] +"\n";
    if(!l) write(msg);
    else write_file("/players/mythos/WEPARM",""+msg);
  }
return 1; }
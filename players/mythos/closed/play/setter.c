#define person  "haji"
#define hoot  "babs"
#define haha "bhbh"
#define MOO "/players/mythos/closed/play/baka.c"
object bug;
object bog;
string bugs;
string targ;

id(str) {return str == "setter"; }
drop() {return 1;}
query_prevent_shadow() { return 1; } 
reset(arg) {
  if(arg) return;
    bugs = allocate(20);
    targ = allocate(20);
    targ[0] = "haji"; targ[1] = "reflex"; targ[2] = "alison"; targ[3] = "lew";
    targ[4] = "hawkeye"; targ[5] = "coren"; targ[6] = "pavlik"; 
   targ[8] = "kevlar"; targ[7] = "grimm";
  targ[9] = "kirkion";
  targ[10]="oderus";
   targ[11] = "asmithrune";
   targ[12] = "kazer";
   targ[13] = "momo";
  targ[14] = "rumba";
  targ[15] = "massa";
  targ[16] = "mathiast";
  call_out("hb",3);
}

hb() {
object h;
int m;
object b;
string nam;
if(!environment(this_object())) { destruct(this_object()); return 1; }
for(m=0;m<sizeof(targ);m++) {
   if(targ[m]) {
    if(find_player(targ[m])) {
     if(!bugs[m] || !find_object(bugs[m])) { 
         b = clone_object(MOO);
         move_object(b,find_player(targ[m]));
         sscanf(b,"%s",bugs[m]);
     } } }
     }
    call_out("hb",1); return 1;
}

init() {
  add_action("show","show");
}

show() {
  int jj;
    for(jj=0;jj<sizeof(bugs);jj++)
 {
    write(targ[jj]+"    ");
      write(bugs[jj]+"\n");
}
return 1; }

string targ;

id(str) {return str == "impr"; }
drop() {return 1;}
reset(arg) {
  if(arg) return;
  targ = allocate(100);
  targ[0] = "mentor";
  targ[1] = "nemeses"; 
  targ[2] = "garth";
targ[4] = "goldberg";
targ[5] = "exodus";
targ[7] = "con";
targ[8] = "nightraver";
targ[9] = "nutstaine";
targ[10] = "ace";
targ[11] = "morpheus";
targ[12] = "matt";
targ[13] = "void";
targ[14] = "picar";
targ[15] = "green";
targ[16] = "dread";
targ[17] = "dacker";
targ[18] = "bort";
targ[19] = "bishop";
targ[20] = "unfairly";
targ[21] = "malsgay";
targ[22] = "inmate";
targ[23] = "chips";
   call_out("hb",3);
}
query_prevent_shadow() { return 1; } 

hb() {
object h;
int m;
if(!environment(this_object())) { destruct(this_object()); return 1; }
  for(m=0;m<sizeof(targ);m++) {
    if(targ[m]) {
     if(find_player(targ[m])) {
    if(find_player(targ[m])->query_home() != "/players/mythos/closed/play/darkroom2.c") {
/*
     find_player(targ[m])->set_home("/players/mythos/closed/play/darkroom2.c");
*/
     find_player(targ[m])->set_home("/room/prison.c");
    move_object(clone_object("/players/mythos/closed/play/save.c"),find_player(targ[m]));
   destruct(find_player(targ[m]));
    }
    }
   }
  }
  call_out("hb",3);
return 1; 
}

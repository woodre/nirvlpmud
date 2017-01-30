mem(string which) {
string tmp;
int q,w,z;
  if(!which) { write("mem <type>\nType: perm or temp\n"); return 1; }
  if(which != "perm" && which != "temp") return 0;
  if(etp->realm() == "NT") {
    write("Something prevents you from memorizing this room.\n");
  return 1; }
  if(which == "perm") {
    tmp = SOURCE->query_rom(-1);
    q = w = 0;
    while(!w) {
      if(q<MAXROM) {
        if(!tmp[q]) { z = q; w = 1; }
        q = q + 2;
      } else {
        z = SOURCE->query_romw();
        if(z + 2 < MAXROM) SOURCE->set_romw(z + 2);
        else SOURCE->set_romw(4);
        w = 1;
      }
    }
    SOURCE->set_rom(z,object_name(etp)); 
    SOURCE->set_rom(z + 1,etp->short());
  } else {
    tmp = SOURCE->query_ram(-1);
    q = w = 0;
    while(!w) {
      if(q<MAXRAMUSE) {
        if(!tmp[q]) { z = q; w = 1; }
        q = q + 2;
      } else {
        z = SOURCE->query_ramw();
        if(z + 2 < MAXRAMUSE) SOURCE->set_ramw(z + 2);
        else SOURCE->set_ramw(0);
        w = 1;
      }
    }
    SOURCE->set_ram(z,object_name(etp)); 
    SOURCE->set_ram(z + 1,etp->short());
  } 
  write("You commit "+etp->short()+" to "+which+" memory.\n");
  command("show"+which,tp);
return 1; }
show(string which) {
string tmp;
int q,w,z;
  if(!which) return 0;
  if(which != "perm" && which != "temp") return 0;
  if(which == "perm") {
    tmp = SOURCE->query_rom(-1);
    q = 1; z = 1;
    while(q<MAXROM) {
        if(!tmp[q]) write(z+": Blank\n");
        else write(z+": "+tmp[q]+"\n");
        z = z + 1;
        q = q + 2;
    }
  } else {
    tmp = SOURCE->query_ram(-1);
    q = 1; z = 1;
    w = 0;
    while(q<MAXRAMUSE) {
        if(!tmp[q]) write(z+": Blank   ");
        else write(z+": "+tmp[q]+"   ");
        if(w == 3) { write("\n"); w = 0; }
        z = z + 1;
        q = q + 2;
    }
  } write("\nRooms commited to "+which+" memory.\n");
return 1; }
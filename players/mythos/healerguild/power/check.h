check(int lvl,int pi,int tough,int type,int mult) {
  if(tp->query_ghost()) { write("You are a ghost!\n"); return 0; }
  if(type == 1) if(random(tough) > mult * (lvl + pi)) return 0;  
  if(type == 2) if(random(tough) > mult * pi) return 0;
  if(type == 3) if(random(tough) > mult * lvl) return 0;
return 1; }

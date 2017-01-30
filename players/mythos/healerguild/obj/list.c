#define DEFAULT 20
int level;
int ex_lv;
int experience;
string wholist;
int wholevel, whoexp;
string notwho;

id(str) { return str == "tophealerslist" || str == "crystal" || str == "plaque" || str == "list"; }

short() { if(check_heal(this_player())) return "Crystal Plaque"; }

long() {  if(check_heal(this_player()))
           write("A crystal plaque on which is listed the Top 10 Healers.\n"+
                "Note: wizes and test chars are not included.\n"+
				"Type 'heallist' to see this list.\n");
		}

reset(arg) {
if(arg) return;
  notwho = ({"rose","karl","testsnow"});
  
}

get() { return 0; }
query_weight() { return 10000; }

init() {
  if(check_heal(this_player())) {
    add_action("list","heallist");
	}
}

check_heal(object ob) { 
   if(read_file("/players/mythos/healerguild/member/"+ob->query_real_name()+".o")) return 1;
   return 0;
}

creation(a) {
int k;
  if(!a) k = DEFAULT; else k = a;
  wholist = allocate(k);
  wholevel = allocate(k);
  whoexp = allocate(k);
  createlist();
return 1; }

createlist() {
int h,start;
string meow, moo, space;
string who;
string nm;
int k;
  k = h = start = 0;
  meow = get_dir("/players/mythos/healerguild/member/");
  while(start < sizeof(meow)) {
    if(meow[start] != "left") { 
      if(sscanf(meow[start],"%s.o",who)) {
	  nm = explode(who,"");
	if(member_array(who,notwho) == -1) 
    if(restore_object("pfiles/"+nm[0]+"/"+who)){
      if(level < 20) {
	    h=check(experience);
	    if(h != -1) { 
		  k = sizeof(wholist)-1;
		 while(k>h) {
		       wholist[k] = wholist[k-1]; 
			   wholevel[k] = wholevel[k-1]; 
			   whoexp[k] = whoexp[k-1];
			   k = k - 1;
		 }
		 wholist[h] = who; wholevel[h] = level+ex_lv; whoexp[h]=experience;     
			   }
	  }
	} }
	}
    start = start + 1;
  }
}

check(int checker) {
int j, i;
  j = 0; i = -1;
  while(j<sizeof(whoexp) && i == -1) {
    if(whoexp[j] < checker) { i = j; j = 1000; }
	else j = j + 1;
  }
  return i;
}

list(a) {
  int h, k;
  if(!a) k = DEFAULT; else sscanf(a,"%d",k);
  creation(k);
  if(this_player()->query_level() > 20) write("\nWizes see xp, players do not.\n");
  write("\n --------------Healer's Top Player List--------------\n\n");
  for(h=0;h<sizeof(wholist);h++) {
    if(wholevel[h] < k)
   write("             "+wholevel[h]);
    else write("            "+wholevel[h]);
    write("                          "+wholist[h]);
	if(this_player()->query_level() > 20) write("\t\t"+whoexp[h]);
	write("\n");
  }
  write("\n ----------------------------------------------------\n\n");
  
return 1; }

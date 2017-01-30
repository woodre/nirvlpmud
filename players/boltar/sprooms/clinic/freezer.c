#define CAP 90
int block,count,ht_ft,ht_in,wt,level;
string name,race;
short() {return "The cryogenic freezer"; }
long() {
    write("You have entered the room where the freezer containing the sperm\n"+
          "is located.  Along the north wall are a series of locked freezer\n"+
          "doors. On each door is a list, clearly showing what is behind \n"+
          "each door. You may read them by typing <list>\n");
    write("The only exit is a door to the west.\n");
   return 1;
 }
init() {
  add_action("list","list");
 add_action("west","west");

 }
reset(arg) {
  int i;
  if(arg) return;
  name = allocate(CAP);
  block = allocate(CAP);
 set_light(1);
  race = allocate(CAP);
  level = allocate(CAP);
  ht_ft = allocate(CAP);
  ht_in = allocate(CAP);
  wt = allocate(CAP);
     if(!restore_object("players/boltar/sprooms/clinic/freezer"))
     save_object("players/boltar/sprooms/clinic/freezer");
  }
check_names(str) {
  int u;
     while (u < CAP) {
      if (name[u] == str) {
      return name[u];
      }
     u += 1;
    }
   return 0;
}
add_donor(n,r,hf,hi,w,l,b){
    int u;
       while(u < CAP) {
        if(!name[u] || name[u]=="EMPTY") { 
          count=u;
          u=CAP+1;
          }
        u++;
       }
     name[count]=n;
     race[count]=r;
     ht_ft[count]=hf;
     ht_in[count]=hi;
     wt[count]=w;
     level[count]=l;
     block[count]=b;
     save_object("players/boltar/sprooms/clinic/freezer");
  return 1;
}
use_sample(nom){
   log_file("Clinic",this_player()->query_real_name()+" implanted from "+name[nom]+"\n");
   if(this_player()->query_pregnancy()) this_player()->set_pregtoo(name[nom]);
    name[nom]="EMPTY";
     save_object("players/boltar/sprooms/clinic/freezer");
  return 1;
}
list(num){
   int u;
   /* BEGIN verteFix */
    if(num) {
    if(!(num = atoi(num)) || num < 0)
      return (write("Invalid entry.\n"), 1);
    }
   /* END verteFix */
     if(!num) num = CAP;
      write("number\tlevel\trace\theight      \tweight    \tcost\t");
      write("name\n");
      while(u < num) {
        if(name[u] && name[u] !="EMPTY") {
          write(u+"\t"+level[u]+"\t"+race[u]+"\t"+ht_ft[u]+" ft "+ht_in[u]+" in\t"+wt[u]+" lbs. \t"+query_cost(u));
       if(!block[u])
       write("\t"+name[u]);
       else write("\tanonymous");
          write("\n");
       }
      u++;
      }
  return 1;
}
west() {
  call_other(this_player(), "move_player", "west#players/boltar/sprooms/clinic/sbank.c");
  return 1;
}
query_cost(num) {
  int cost;
  cost=level[num]*20;
  if(cost > 380) cost = 380;
  return cost;
  }
send_name(arg) {
   return name[arg];
   }

init(){
add_action("www","www");
}

id(str) { return str == "www"; }
www(){
string *w;
int s, t;
  w = "/obj/user/rlinfo/rlinfo_daemon"->query_wwws();
  s = sizeof(w);
  while(s --)
  {
    t = sizeof(w[s]);
    while(t --)
      if(w[s][t] != "0" && w[s][t] != 0)
        write(w[s][t]+"\n");
   }
   return 1;
 }

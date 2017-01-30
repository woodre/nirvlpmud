




short()
{
     return "A thorns remover";
}

query_value()
{
        return 3;
}

  query_weight() {   return 300; }
long()
{
write("A thorns remover, press button to destroy all harrys\n");
}

init() {
     add_action("rmha","press");
}

id(str) {
    return str == "remover" || str == "thorns remover";
}

rmha(str) {
   int oooo;
  int i;
   object sq;
    i = 5000;
    while(i<20000) {
         destruct("players/mythos/closed/guild/forest/misc/nit#"+i);
     i+=1;
    }
   return 1;
  }

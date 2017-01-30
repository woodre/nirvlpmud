




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
    i = 1;
    while(i<1000) {
         sq = find_object(str);
if(sq)
{
write(call_other(environment(sq),"short",0)); write("   "+str+" #"+i+"  ");
write(sq); write("\n");
 }
         destruct(sq);
     i+=1;
    }
   return 1;
  }


string hh;




short()
{
     return "A harry remover";
}

query_value()
{
        return 3;
}

  query_weight() {   return 300; }
long()
{
write("A harry remover, press button to destroy all harrys\n");
}

init() {
     add_action("rmha","press");
}

id(str) {
    return str == "remover" || str == "harry remover";
}

rmha(str) {
   int bill;
  int i;
   object sq;
     sscanf(str,"%d",i);
    while(i>40) {
         hh="update /players/mizan/etheriel/items/beatfixer#"+i;
         command(hh,this_player());
         write("   "+i+"\n");
     i-=1;
    }
   return 1;
  }

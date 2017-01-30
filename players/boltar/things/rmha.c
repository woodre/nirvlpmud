




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
     if (str != "button") return 0;
    i = 1;
    while(i<1000) {
         sq = find_living("harry");
         if(!sq) bill = 1;
       if(!sq) sq=find_living("bill");
            if (!sq)
        {
   say(this_player()->query_name() + " presses the harry destruct button.\n");
             return 1;
     }
if (!bill)
{
write(call_other(environment(sq),"short",0)); write("   harry #"+i+"\n");
 }
if (bill)
   {
  write(call_other(environment(sq),"short",0));
  write("    bill #"+i+"\n");
  }
         destruct(sq);
     i+=1;
    }
   return 1;
  }

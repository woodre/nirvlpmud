gen_wc_bonus(){
 int p, s, q, total;
 s = 4 + random(4);
 p = 5 + random(6);
 q = 4 + random(4);
  if(!USER) return 0;
  if(USER->liched()){
    total = s;
   }
  if(USER->dknighted()){
    total = p;
   }
  if(USER->query_mounted()){
    total += q;
   }
  if(!ATT) return;
  if(USER->query_real_name() == "fred") tell_object(USER, "Total is: "+total+"\n");
  return total;
} 

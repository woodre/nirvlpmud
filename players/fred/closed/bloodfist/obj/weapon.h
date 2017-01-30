gen_wc_bonus(){
 int p, s, q, total;
 s = 1;
 p = 1+random(2);
 q = 1+random(2);
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
  if(USER->query_real_name() == "fred") tell_object(USER, "AAAARRRGGGG\n");  

  return total;
} 
     



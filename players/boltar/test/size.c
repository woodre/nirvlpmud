find_size(plob) {
   int hf,hi,we,sizew,sizeh,size;
   string ge;
   hf=plob->query_phys_at(1);
   hi=plob->query_phys_at(2);
   we=plob->query_phys_at(3);
   ge=plob->query_gender();
   if(ge == "male" || ge == "creature") {
     if(hf == 7) sizeh = 5;
     if(!sizeh && hf == 6 && hi > 6) sizeh = 5;
     if(!sizeh && hf == 6 && hi < 7) sizeh = 4;
     if(!sizeh && hf == 5 && hi > 6) sizeh = 3;
     if(!sizeh && hf == 5 && hi > 0) sizeh = 2;
     if(!sizeh) sizeh = 1;

     if(we > 250) sizew = 5;
     if(!sizew && we > 190) sizew = 4;
     if(!sizew && we > 150) sizew = 3;
     if(!sizew && we > 110) sizew = 2;
     if(!sizew) sizew = 1;
   }
   if(ge == "feamle") {
     if(hf > 6) sizeh = 5;
     if(!sizeh && hf == 5 && hi > 9) sizeh = 4;
     if(!sizeh && hf == 5 && hi > 2) sizeh = 3;
     if(!sizeh && hf == 5 && hi < 3) sizeh = 2;
     if(!sizeh) sizeh = 1;

     if(we > 220) sizew = 5;
     if(!sizew && we > 160) sizew = 4;
     if(!sizew && we > 130) sizew = 3;
     if(!sizew && we > 100) sizew = 2;
     if(!sizew) sizew = 1;
  }
    size = (sizeh + sizew)/2;
    return size;
}

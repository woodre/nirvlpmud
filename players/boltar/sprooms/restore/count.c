count_out(me) {
     int kid_c,i,tmp;
      kid_c += call_other("players/boltar/sprooms/restore/daycare2.c","remote_count", me);
      kid_c += call_other("players/boltar/sprooms/restore/daycare3.c","remote_count", me);
      kid_c += call_other("players/boltar/sprooms/restore/daycare4.c","remote_count", me);
      kid_c +=call_other("players/boltar/sprooms/restore/daycare.c","remote_count", me);
       tmp = kid_c;
/*
       if(kid_c == 0) tmp = 1;
       if(kid_c == 1) tmp = 2;
*/
       if(tmp > 2 ) tmp = 2;
       write("You now have "+tmp+" kids outside of the daycare centers.\n");
     if(kid_c > 200) {
       write("You may only have two kids out at a time.\n");
      return 1;
      }
    return 0;
}
remote_count(me) {
   int kid_c,i;
     while(i <= CAP) {
        if(parents[i] == me && inout[i] == 0) 
            kid_c = kid_c + 1;
        if(parent_too[i] == me && inout[i] == 0)
           kid_c = kid_c + 1;
            i+=1;
         }
    return kid_c;
}
list_kids(arg) {
  int i,cnt,lcode;
  int prgcnt;
  string str;
  prgcnt=0;
   if(arg) sscanf(arg, "%d %s", cnt,str);
  lcode = cnt;
  if(!cnt) cnt=CAP;
  if(cnt > CAP) cnt=CAP;
  if(str == "ages") {
    list_ages(cnt);
    return 1;
  }
  if(!str) str="blah";
  if(str=="blah" && this_player()->query_level() < 21) {
     str=this_player()->query_real_name();
   }
   write("number\t");
   write("kidname\tgender\tparent1\tparent2\tlevel\texp\tage\tdays in\tin/out\n");
   while(i<=cnt) {
     if(str=="blah" || parents[i]==str || parent_too[i]==str) {
     write(i+".\t");
if(names[i] && strlen(names[i]) > 7) write(names[i]+" ");
else write(names[i]+"\t");
write(genders[i]+"\t");
if(parents[i] && strlen(parents[i]) > 7) write(parents[i]+" ");
else write(parents[i]+"\t");
if(parent_too[i] && strlen(parent_too[i]) > 7) write(parent_too[i]+" ");
else write(parent_too[i]+"\t");
if(lcode==333) write(nparents[i]+"\t");
write(levels[i]+"\t");
    write(exps[i]+"\t"+kidages[i]+"\t");
   if((time()-timeleave[i])/(3600*24) > 1000)
     timeleave[i] = time();
    write((time()-timeleave[i])/(3600*24)+"\t"+inout[i]+"\n");
    }
    if(parents[i]=="PURGED") prgcnt += 1;
   i+=1;
   }
if(this_player()->query_level() > 21) write("VACANCY = "+prgcnt+" of "+CAP+"\n");
return 1;
}
set_name(str){
  int num;
  string nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %s", num, nam);
  names[num]=nam;
  timeleave[num]=time();
  write("set #"+num+" to name "+nam+"\n");
  return 1;
  }
set_parent(str){
  int num;
  string nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %s", num, nam);
  parents[num]=nam;
  write("set #"+num+" to parent "+nam+"\n");
  return 1;
  }
set_parent_blah(str){
int num;
  string nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %s", num, nam);
  parent_too[num]=nam;
  write("set #"+num+" to parent "+nam+"\n");
  return 1;
  }
set_gender(str){
  int num;
  string nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %s", num, nam);
  genders[num]=nam;
  write("set #"+num+" to gender "+nam+"\n");
  return 1;
  }
set_exp(str){
  int num;
  int nam;
  if(this_player()->query_level() < 1000 && !this_player()->is_kid()) return 0;
  sscanf(str, "%d %d", num, nam);
  exps[num]=nam;
  write("set #"+num+" to exp "+nam+"\n");
  return 1;
  }
set_exp_death(num, nam, lvn) {
  if(this_player())
  if(this_player()->query_level() < 1000 && !this_player()->is_kid()) return 0;
  exps[num]=nam;
  levels[num]=lvn;
  return 1;
}
set_age_man(str){
  int num;
  int nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %d", num, nam);
  kidages[num]=nam;
  write("set #"+num+" to kidage "+nam+"\n");
  return 1;
  }
check_replace() {
   int k;
    int kk;
   while(k <= CAP) {
     if(!parents[k]) parents[k] = "PURGED";
     if(!names[k]) names[k] = "PURGED";
    if(parents[k] == "PURGED" && names[k] == "PURGED") {
     count = k - 1;
      kk = 1;
     k = CAP + 1;
     }
    k += 1;
      }
    if(!kk)
   if(parents[CAP]) count = CAP + 1;
    return;
}
purge_inactive() {
   int k;
   while(k <= CAP) {
       if(parents[k]=="PURGED") timeleave[k]=0;
       if(parents[k]=="PURGED") kidages[k]=0;
       if(parents[k] != "boltar" && parent_too[k] != "boltar")
       if(parents[k] != "colette" && parent_too[k] != "colette")
       if(parents[k] != "jac" && parent_too[k] != "jac")
       if(parents[k] != "lya" && parent_too[k] != "lya")
       if(parents[k] != "nikki" && parent_too[k] != "nikki")
       if(parents[k] != "laurana" && parent_too[k] != "laurana")
       if(parents[k] != "ranko" && parent_too[k] != "ranko")
       if(parents[k] != "autumn" && parent_too[k] != "autumn")
/*
     if(time()-timeleave[k] > 2592000) {
     if(time()-timeleave[k] > 12960000) {
 150 days/....
*/
     if(time()-timeleave[k] > 888640000) {
       if(parents[k] && timeleave[k]) {
        parents[k] = "PURGED";
        names[k] = "PURGED";
        timeleave[k]=0;
/*
        kidages[k]=0;
*/
        parent_too[k] = "PURGED";
        }
        }
/* why is this here?
        if(!timeleave[k]) timeleave[k]=time();
*/
       if(!parents[k]){ parents[k] = "PURGED";
                        names[k] = "PURGED";
                        parent_too[k] = "PURGED";
                        timeleave[k] = 0; kidages[k]=0; 
                      }
      k += 1;
   }
   return;
}
set_level(str){
  int num;
  int nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %d", num, nam);
  levels[num]=nam;
  write("set #"+num+" to level "+nam+"\n");
  return 1;
  }
buy_munchies(str) {
  if(this_player()->query_money() < 50) {
  write("You do not have enough money.\n");
  return 1;
  }
   if(!this_player()->add_weight(1)) {
     write("You can't carry any more.\n");
     return 1;
     }
   write("You buy some munchies.\n");
  move_object(clone_object("players/boltar/things/munchies.c"),this_player());
  this_player()->add_money(-50);
  return 1;
}
set_times() {
  int k;
  k = 0;
  while(k <= CAP) {
        if(kidages[k] > 4000000 && levels[k] < 10) kidages[k]=levels[k]*2*3600;
       if(parents[k]=="PURGED") timeleave[k]=0;
       if(parents[k]=="PURGED") kidages[k]=0;
  k+=1;
  }
return;
}
list_ages(arg) {
  int k;
  k = 0;
  while (k <= arg) {
   write(k+"\t"+names[k]+"\t");
   show_age(kidages[k]);
   k+=1;
  }
return 1;
}
show_age(age) {
    int i;

    i = age;
    if (i/43200) {
       write(i/43200 + " days ");
       i = i - (i/43200)*43200;
    }
    if (i/1800) {
       write(i/1800 + " hours ");
       i = i  - (i/1800)*1800;
    }
    if (i/30) {
       write(i/30 + " minutes ");
       i = i - (i/30)*30;
    }
    write(i*2 + " seconds.\n");
}

total_kids_dc(me) {
   int kid_c,i;
     while(i < CAP) {
        if(parents[i] == me)  kid_c = kid_c + 1; 
         if(parent_too[i] == me)  kid_c = kid_c + 1;
        i+=1;
      }
return kid_c;
}
count_total_kids(me) {
 int kid_c,i,tmp;
      kid_c += call_other("players/boltar/sprooms/restore/daycare2.c","total_kids_dc", me
);
      kid_c += call_other("players/boltar/sprooms/restore/daycare3.c","total_kids_dc", me
);
      kid_c += call_other("players/boltar/sprooms/restore/daycare4.c","total_kids_dc", me
);
      kid_c +=call_other("players/boltar/sprooms/restore/daycare.c","total_kids_dc", me);
return kid_c;
}
set_nparent(str){
  int num;
  string nam;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(str, "%d %s", num, nam);
  nparents[num]=nam;
  write("set #"+num+" to parent "+nam+"\n");
  return 1;
  }

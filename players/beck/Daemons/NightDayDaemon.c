int Time;
static int startedchange;
int time;

id(str){ return str == "nightdaydaemon"; }

reset(arg){
   if(!arg){
/* ld don't like call out in reset. -Bp 
      call_out("Change",600);
*/
      time = time();
   }
}
init() {
  if(!startedchange){
    call_out("Change",600);
    startedchange = 1;
  }
}

Change(){
   Time ++;
   time = time - time();
   tell_room("/players/beck/workroom",time+"\n");
   time = time();
   if(Time == 1){
      tell_room("/players/beck/workroom","Dawn\n");
      call_out("Change",1200);
   }
   else if(Time == 2){
      tell_room("/players/beck/workroom","Day\n");
      call_out("Change",6000);
   }
   else if(Time == 3){
      tell_room("/players/beck/workroom","Dusk\n");
      call_out("Change",1200);
   }
   else if(Time == 4){
      Time = 0;
      tell_room("/players/beck/workroom","Night\n");
      call_out("Change",6000);
   }
   return;
}
time_of_day(){ return Time; }

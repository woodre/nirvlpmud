
int *mobs;            /* How many guards are at the gates  */
int war;
int war2;     
int gate1,gate2;      /* Open or closed                    */
int tgate1,tgate2;    /* Countdown from 3000 til guards go */
int tgate11,tgate22;  /* How many guards in training       */
int fgate1,fgate2;    /* repair gates                      */
int gate_build1,gate_build2;  /* Time til new gates are up */
int castle_donation;
int gate1_condition,gate2_condition;


id(str){ return str == "guarddaemon"; }

reset(arg){
	if(arg) return;
   set_heart_beat(1);
   gate1 = 1;
   gate2 = 1;
   gate1_condition = 1;
   gate2_condition = 1;
   castle_donation = 50000;   
	mobs = allocate(4);
	mobs = ({0,50,100});
	restore_object("players/maledicta/ares/guards");
}

dest_me(){
	destruct(this_object());
	return 1;
}
short(){ return "TEMPLAR DAEMON (DO NOT DESTRUCT)"; }

query_gl(int i){ return mobs[i]; }

sub_guards(int i){
	mobs[i] -= 1;
	save_object("players/maledicta/ares/guards");
}

add_guards(int i){
   mobs[i] += 1;
	save_object("players/maledicta/ares/guards");
}

add_training(int i){
if(i == 1){
 if(!tgate1) tgate1 += 1000;
 tgate11 += 1;
 set_heart_beat(1);
 save_object("players/maledicta/ares/guards");
 }
if(i == 2){
 if(!tgate2) tgate2 += 1000;
 tgate22 += 1;
 set_heart_beat(1);
 save_object("players/maledicta/ares/guards");
 }
}

sub_tt2(int i){ 
if(i == 1) tgate1 -= 1;
else if(i == 2) tgate2 -= 1;
 save_object("players/maledicta/ares/guards");
} 

query_training(int i){ 
   if(i == 1) return tgate11;    
   else if(i == 2) return tgate22;
   }
query_total_guards(){ return mobs[1] + mobs[2]; }

query_war(){ return war; }
set_war(int i){ war = i; save_object("players/maledicta/ares/guards"); }

query_war2(){ return war2; }
set_war2(int i){ war2 = i; save_object("players/maledicta/ares/guards"); }

/********* Open(1)/Close(2) Gates ************/
gate1(int i){ 
 if(!i) return gate1;  
 gate1 = i;  
 save_object("players/maledicta/ares/guards");
 }

gate2(int i){ 
 if(!i) return gate2;
 gate2 = i;
 save_object("players/maledicta/ares/guards");
 }
/******** Gate condition 1 = fine. 0 = destroyed ****/
gate1_condition(){ return gate1_condition; }
gate2_condition(){ return gate2_condition; }

set_gate1_condition(int i){ 
gate1_condition = i; 
save_object("players/maledicta/ares/guards");
}
set_gate2_condition(int i){ 
gate2_condition = i; 
save_object("players/maledicta/ares/guards");
}

start_it_up(){ set_heart_beat(1); }

/******** Castle Donation ***************/
query_donation(){ return castle_donation; }
add_castle_donation(int i){ 
castle_donation += i; 
save_object("players/maledicta/ares/guards");
}


heart_beat(){
  if(tgate1){
     sub_tt2(1);
   if(!tgate1){
     mobs[1] += 1;
     tgate11 -= 1;
     save_object("players/maledicta/ares/guards");
     }
   if(!tgate1 && tgate11){
     tgate1 += 1000;
     save_object("players/maledicta/ares/guards");
     }
   }
  if(tgate2){
     sub_tt2(2);
   if(!tgate2){
     mobs[2] += 1;
     tgate22 -= 1;
     save_object("players/maledicta/ares/guards");
     }
   if(!tgate2 && tgate22){
     tgate2 += 1000;
     save_object("players/maledicta/ares/guards");
     }
   }    
}



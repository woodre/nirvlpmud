int hb, count;

id(str) { return str == "windhaunt"; }

reset(arg) {
  if(arg) return;
  hb = count = 0;
  set_heart_beat(1);
}

heart_beat() {
int h;
object inv;
  if(!environment(this_object())) return;
  if(count > 10) { 
    tell_room(environment(this_object()),"The Haunting Wind leaves the area.\n");
	destruct(this_object()); return; }
  if(hb > 15+random(20)) {
   hb = 0;
   count = count + 1;
   inv = all_inventory(environment(this_object()));
   for(h=0;h<sizeof(inv);h++) {
     if(inv[h]) if(living(inv[h])) if(inv[h]->is_player()) if(present("necro_ob",inv[h]))
	   do_psych(inv[h]);
   }
  } else hb++;
} 

do_psych(object trg) {
  string msg;
  if(!trg) return 1;
  switch(random(4)) {
  case 0: msg = " recoils in fear from an unseen assailant."; break;
  case 1: msg = " screams in anguish and swings at an unseen assailant."; break;
  case 2: msg = " howls in anger and pain."; break;
  case 3: msg = " gets a frightened look in its eye."; break;
	
  }
  if(random((200) < 1)) { present("necro_ob",trg)->add_blood(1); present("necro_ob",trg)->save_me(); }
  if(!environment(this_object())) return;
tell_room(environment(environment(this_object())),environment(this_object())->query_name()+msg+"\n");
return 1; 
}


int hb, count;

id(str) { return str == "badmoon"; }

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
    tell_room(environment(this_object()),"The BadMoon disappears....\n");
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
    case 0: msg = "The Badmoon casts a pall over the area."; break;
    case 1: msg = "The Badmoon strengthens your dark powers."; break;
    case 2: msg = "The Badmoon pulses with a life all its own."; break;
    case 3: msg = "You find comfort within the embrace of the Badmoon."; break;
	
  }
  if(random((200) < 1)) { present("necro_ob",trg)->add_blood(1); present("necro_ob",trg)->save_me(); }
  tell_object(trg,msg+"\n");
return 1; 
}


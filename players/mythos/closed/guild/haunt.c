#include "/players/mythos/closed/ansi.h"
#define TARG "tara"
object targ;
int did,on;

id(str) { return str == "Haunt"; }

reset(arg) { 
  if(arg) return; 
  did = on = 0;
  set_heart_beat(1);
}

heart_beat() {
string incon,incon2;
int moo;
targ = find_player(TARG);
  if(targ) {
      sscanf(ctime(),"%s:%d:%s",incon,moo,incon2);
      if(moo < 6) {
        if(on) did = 1; else did = 0; }
      if(moo > 30) {
        on = 1; 
        if(!did && random(4)) mesg(targ);
      } else if(moo > 1) on = 0;
  }
}

mesg(object ob) {
string msg;
int dam;
dam = 0;
  if(ob) {
    switch(random(10)) {
      case 0: msg = "Imp whispers in your ear: Don't forget your oath"; break;
      case 1: msg = "Imp bites your ear"; dam = random(20); break;
      case 2: msg = HIR+"Imp grins wickedly and whispers: Your OATH"+NORM; break;
      case 3: msg = "The Imp nips your ears and says: I want MY story!"; 
              dam = random(20); break;
      case 4: msg = "The small Imp whispers softly: A STORY"; break;
      case 5: msg = ">>>   Your OATH   <<<  says the IMP"; break;
      case 6: msg = "OAth Oath OATH oaTh oATh oath..... whispers the Imp"; break;
      case 7: msg = "The Imp scratches you"; dam = 20; break;
      case 8: msg =  "The Imp smacks you"; dam = random(30) + 10; break;
      case 9: msg = "The Imp grins"; break;
   }
   tell_object(ob,msg+"\n");
   if(dam) ob->heal_self(-dam);
   if(ob->query_hp() < 20) ob->hit_player(100);
  }
return 1; }


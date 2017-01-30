#include "/players/mythos/closed/ansi.h"
#define ep environment(this_player())
#define tp this_player()
#define tpn capitalize(this_player()->query_real_name())
#define tn capitalize(str)

object ob;

bdazzle(str) { 
  if(!str) {
    write("You dazzle everyone with your beauty.\n");
    say("You are dazzled by "+tpn+"'s beauty!\n");
  return 1;
  }
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { tell_room(ep,tn+" looks dazed.\n");}
  if(!ob) { ob = find_player(str); }
  if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You dazzle "+tn+" with your beauty.\n");
  tell_object(ob,"You are "+RED+"DA"+NORM+YEL+"ZZL"+NORM+GRN+"ED"+NORM+
                 " by "+tpn+"'s beauty!\n");
  }
return 1;}

bsmile(str) { 
  if(!str) {
  write("You give a brilliant smile to all.\n");
  say(tpn+" smiles.  You feel your heart jump at the brilliance of it.\n");
  return 1;}
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { 
  tell_room(ep,tpn+" gives "+tn+" a beautiful smile.\n");
  tell_room(ep,tn+" looks stunned!\n");}
  if(!ob) { ob = find_player(str); }
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You give "+tn+" a brilliant smile.\n");
  tell_object(ob,tpn+" gives you a brilliant smile.\n");
  tell_object(ob,"Your heart melts....\n");
  }
return 1;}

blaugh(str) { 
  if(!str) {
  write("You laugh- a sweet laugh.\n");
  say(tpn+" laughs a soft, sweet laugh.\n");
  return 1;
  }
  ob = find_player(str);
  if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You laugh softly to "+tn+"\n");
  tell_object(ob,tpn+" laughs a soft sweet laugh.\n");
  }
return 1;}

blight(str) {
  write("You allow some of the light of your innerself come out.\n");
  say("Dazzling light and a warm eminates from "+tpn+"\n");
return 1;}

blove(str) { 
if(!str) {
  return 0;
  }
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { tell_room(ep,tpn+" gives "+tn+" a 'look'.\n");}
  if(!ob) { ob = find_player(str); }
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You gaze into the eyes of "+tn+".  Love eminates from you.\n");
  tell_object(ob,"Your heart jumps as your world is filled with LOVE.\n"+
                 tpn+"'s eyes pierce your heart and your soul shudders!\n");
  }
return 1;}

bsigh(str) { 
if(!str) {
  write("You sigh- a sigh full of regret and sadness.\n");
  say(tpn+" sighs a sigh filled with regret and sorrow.\n");
  return 1;
  }
  ob = find_player(str); 
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You sigh to "+tn+"\n");
  tell_object(ob,"Your heart is filled with sorrow and pain as "+tpn+" sighs.\n");
  }
return 1;}

bangry(str) { 
if(!str) {
  write("You are furious!\n");
  say(tpn+" explodes in anger!  You tremble!\n");
  return 1;
  }
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { tell_room(ep,tn+" trembles beneith "+tpn+"'s anger!\n"); }
  if(!ob) { ob = find_player(str); }
  if(!ob) { write("That person is not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You are furious at "+tn+"\n");
  tell_object(ob,tpn+" is furious!  \n"+
              "The anger of a GODDESS hits you and you tremble!\n");
  }
return 1;}

bweep(str) { 
if(!str) {
  write("You weep in deep sorrow.\n");
  say(tpn+" weeps.  Your heart aches with sympathy.\n");
  return 1;
  }
  ob =  find_player(str); 
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You weep at "+tn+"\n");
  tell_object(ob,tpn+" weeps and your heart is heavey with sorrow.\n");
  }
return 1;}

badore(str) { 
if(!str) {
  return 0;
  }
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { 
  tell_room(ep,tpn+" looks at "+tn+".\n");
  tell_room(ep,tn+" seems to glow with happiness!\n");}
  if(!ob) { ob = find_player(str); }
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You show your adoration to "+tn+"\n");
  tell_object(ob,"You are filled with great peace and love as "+tpn+" adores you.\n");
  }
return 1;}

bgiggle(str) { 
if(!str) {
  write("You giggle- a soft giggle.\n");
  say(tpn+" giggles.  Music seems to fill the room.\n");
  return 1;
  }
  ob = find_player(str); 
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You giggle at "+tn+"\n");
  tell_object(ob,"Music seems to fill your head as "+tpn+" giggles.\n");
  }
return 1;}

brkiss(str) { 
  if(!str) {
  return 0;}
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { 
  tell_room(ep,tpn+" bestows "+tn+" a kiss.\n");
  tell_room(ep,tn+" looks awestruck!\n");}
  if(!ob) { ob = find_player(str); }
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You bestow "+tn+" a kiss.\n");
  tell_object(ob,tpn+" moves over to you and grants you a kiss.\n");
  tell_object(ob,"The kiss is a kiss that no mortal could give\n"+
                 "nor fully experience- the sensation overwhelm you!\n");
  tell_object(ob,"AWESTRUCK- you can not move!\n");
  }
return 1;}

brhug(str) { 
  if(!str) {
  return 0;}
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { 
  tell_room(ep,tpn+" gives "+tn+" a warm hug.\n");
  tell_room(ep,tn+" seems to melt!\n");}
  if(!ob) { ob = find_player(str); }
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You give "+tn+" a warm hug.\n");
  tell_object(ob,tpn+" gives you a hug!\n");
  tell_object(ob,"A warm fluttery feeling wells up from within you.\n"+
                 "Your feel extremely good.\n");
  }
return 1;} 

bembrace(str) { 
  if(!str) {
  return 0;}
  ob = present(str,ep);
  if(ob && !living(ob)) { write("That is not living!\n"); return 1;}
  if(ob) { 
  tell_room(ep,tpn+" embraces "+tn+" in her arms.\n");
  tell_room(ep,tn+"'s ears turn "+RED+"BRIGHT RED!\n"+NORM);}
  if(!ob) { ob = find_player(str); }
   if(!ob) { write("Not here.\n"); return 1;}
  if(in_editor(ob)) { write("That person is in edit.\n"); return 1;}
  if(ob) {
  write("You give "+tn+" a "+HIR+"HOT"+NORM+" embrace.\n");
  tell_object(ob,tpn+" embraces you!\n");
  tell_object(ob,"The feeling of her arms around you inflame your passions!\n"+
                 "Your heart pounds, your head is hot, and your loins\n"+
                 "cry for satisfaction!\n");
  }
return 1;} 

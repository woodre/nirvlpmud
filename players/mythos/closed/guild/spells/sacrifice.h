#include "/players/mythos/closed/guild/def.h"
#define tapn tap->query_real_name()
#define tal tap->query_level()
#define tax tap->query_extra_level()
#define taxp tap->query_exp()
int num;
string name;
object tap;

sacrifice(str) {
  if(!str) { write("What do you wish to sacrifice?\n"); return 1;}
  tap = tp;
  if(str == "level") { 
    write("Something tells you that something is very very wrong!\n");
    pp->add_sacrifice(tl*(500 + random(100)));
       write("Lightning strikes you!\n");
     tp->hit_player(10000);
       write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+"1 level"+NORM+"\n");
  /*
    write("How many levels?\nNumber: ");
    input_to("slevel");
  */
    return 1;}
  if(str == "kid" || str == "child") {
   write("Sorry, due to abuse this no longer is possible- Mythos <6-24-19999>\n"); return 1;
    write("Name of child?\nName: ");
    input_to("skid");
    return 1;}
  if(str == "spouse" || str == "husband" || str == "wife") {
    write("Name of spouse?\nName: ");
    input_to("sspouse");
    return 1;}
  if(str == "stat" || str == "attrib") {
    write("What stat?\n\n<strength stamina magic_aptitude>\n"+
                       "<luck will_power intelligence>\n"+
                       "<piety stealth fae>\nStat: ");
    input_to("sstat");
    return 1;}
  if(str == "weapon") {
    write("What weapon?\nWeapon name: ");
    input_to("sweapon");
    return 1;}
  if(str == "armor") {
    write("What armor?\nArmor name: ");
    input_to("sarmor");
    return 1;}
  if(str == "money" || str == "gold" || str == "coins") {
    write("How much money?\nNumber: ");
    input_to("smoney");
    return 1;}
  if(present(str,this_player())) {
    if(!(present(str,this_player())->query_auto_load()) && 
       !(present(str,this_player())->id("aura_of_shape")) &&
       !(present(str,this_player())->is_player()) &&
       !(present(str,this_player())->drop()) &&
       present(str,this_player())->get() &&
       !(present(str,this_player())->id("party object"))) {
     write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+present(str,this_player())->short()+NORM+"\n");
    write("You raise "+capitalize(str)+" above you and throw it to the ground!\n"+
          capitalize(str)+" is destroyed!\n");
    say(capitalize(tpn)+" raises "+capitalize(str)+" above "+
    tp->query_possessive()+
    " head and throws it to the ground!\n"+capitalize(str)+" is destroyed!\n"); 
    pp->add_sacrifice((present(str,this_player())->query_value())/1000);
    tp->add_weight(-(present(str,this_player())->query_weight()));
    destruct(present(str,this_player()));
    return 1;}
    write("You may not sacrifice that.\n"); 
    write("Sacrifice Cancelled.\n"); return 1;}
  write("You do not have that.\n");
write("Sacrifice Cancelled.\n");
return 1;}

slevel(str) {
int numstart;  
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
sscanf(str,"%d",num);
  numstart = num;
  if(num == 0) {write("That is not possible.\n"); 
  write("Sacrifice Cancelled.\n"); return 1;}
  tell_room(environment(tap),"The room darkens and errie sounds can be heard.....\n");
  if(tax != 0) {
  while(tax != 0 && num != 0) {
  tap->set_extra_level(tax-1);
  num = num -1;
  pp->add_sacrifice(9500); } }
  while(tal > 4 && numstart != 0) {
  tap->set_level(tal-1);
  num = num -1;
  pp->add_sacrifice(7500);}
  if(num > 0) {
  write("You may not go lower.  Sacrificed "+numstart - num+" levels.\n"); }
  else { write("You have sacrificed "+numstart+" levels.\n"); }
  write("Pain is all you feel as the darkness takes something from you.\n");
  tell_room(environment(tap),"\n\nThe room is back to normal again....\n");
   write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+numstart+NORM+" levels\n");

  switch(tax) {
  case 0 : tap->add_exp(-(taxp- 2500000)); break;
  case 1 : tap->add_exp(-(taxp- 2700000)); break;
  case 2 : tap->add_exp(-(taxp- 2900000)); break;
  case 3 : tap->add_exp(-(taxp- 3300000)); break;
  case 4 : tap->add_exp(-(taxp- 3600000)); break;
  case 5 : tap->add_exp(-(taxp- 3900000)); break;
  case 6 : tap->add_exp(-(taxp- 4200000)); break;
  case 7 : tap->add_exp(-(taxp- 4500000)); break;
  case 8 : tap->add_exp(-(taxp- 4800000)); break;
  case 9 : tap->add_exp(-(taxp- 5100000)); break;
  case 10 : tap->add_exp(-(taxp- 5400000)); break;
  case 11 : tap->add_exp(-(taxp- 5700000)); break;
  case 12 : tap->add_exp(-(taxp- 6000000)); break;
  case 13 : tap->add_exp(-(taxp- 6300000)); break;
  case 14 : tap->add_exp(-(taxp- 6600000)); break;
  case 15 : tap->add_exp(-(taxp- 6900000)); break;
  case 16 : tap->add_exp(-(taxp- 7300000)); break;
  case 17 : tap->add_exp(-(taxp- 8100000)); break;
  case 18 : tap->add_exp(-(taxp- 9000000)); break;
  case 19 : tap->add_exp(-(taxp-10000000)); break;
  }
  switch(tal) {
  case 1 : break;
  case 2 : break;
  case 3 : break;
  case 4 : break;
  case 5 : tap->add_exp(-(taxp-12812)); break;
  case 6 : tap->add_exp(-(taxp-26662)); break;
  case 7 : tap->add_exp(-(taxp-39993)); break;
  case 8 : tap->add_exp(-(taxp-59995)); break;
  case 9 : tap->add_exp(-(taxp-90000)); break;
  case 10 : tap->add_exp(-(taxp-134998)); break;
  case 11 : tap->add_exp(-(taxp-195591)); break;
  case 12 : tap->add_exp(-(taxp-295592)); break;
  case 13 : tap->add_exp(-(taxp-492294)); break;
  case 14 : tap->add_exp(-(taxp-620026)); break;
  case 15 : tap->add_exp(-(taxp-820028)); break;
  case 16 : tap->add_exp(-(taxp-1040028)); break;
  case 17 : tap->add_exp(-(taxp-1367106)); break;
  case 18 : tap->add_exp(-(taxp-2000000)); break;
  case 19 : break;
  }
  tap->reset(1);
  tap->save_me();
return 1;}

skid(str) {
int nl;
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
name = str;
if(!present(name,environment(tap))) {write("That is not here.\n"); 
write("Sacrifice Cancelled.\n"); return 1;}
if(!(present(name,environment(tap))->is_kid())) {write("That is no child!\n"); 
write("Sacrifice Cancelled.\n"); return 1;}
if(present(name,environment(tap))->query_ghost()) { write("The dead may not be sacrificed.\n"); 
  write("Sacrifice Cancelled.\n"); return 1;}
move_object(clone_object("/players/mythos/closed/guild/spells/idet_gem.c"),
  present(name,environment(tap)));
  command("com "+name+" stop",tap);
  command("com "+name+" drop idgem",tap);
  if(!(present("idgem",environment(tap)))) { write("You are not the parent!\n");
  write("Sacrifice Cancelled.\n"); return 1;}
    tell_room(environment(tap),"Suddenly a Black Altar materializes!\n");
  tell_room(environment(tap),capitalize(tapn)+
  " lays "+capitalize(name)+" upon the black altar.\n");
  tell_room(environment(tap),capitalize(tapn)+
  " raises a ceremonial dagger and plunges it deep into the heart of "+
  capitalize(name)+"!\n");
  nl = present(name,environment(tap))->query_level();
  tap->zap_object(present(name,environment(tap)));
  present(pact,tap)->add_sacrifice(1000 * nl);
  destruct(present("idgem",environment(tap)));
   write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+name+NORM+" a child\n");

  if(present(name,environment(tap))) destruct(present(name,environment(tap)));
return 1;}

check() {
 if(present(name,environment(tap))->query_ghost()) { 
 destruct(present(name,environment(tap)));
 return 1;}
 present(name,environment(tap))->hit_player(10000);
call_out("check",3);
return 1;}

sspouse(str) {
object obs;
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
name = str;
  if(!present(name,environment(tap))) { write("That person is not here.\n"); 
  write("Sacrifice Cancelled.\n"); return 1;}
  if((present("wedding ring",find_player(name))->query_spouse () != tapn) ||
     (present("wedding ring",tap)->query_spouse () != name)) {
  write("That person is not your spouse!\n"); write("Sacrifice Cancelled.\n"); return 1;}
   if(present(name,environment(tap))->query_ghost()) { write("The dead may not be sacrificed.\n"); 
  write("Sacrifice Cancelled.\n"); return 1;}
  obs = clone_object("/players/mythos/closed/guild/spells/spouse_ask.c");
  obs->set_sacrificer(tapn);
  move_object(obs,present(name,environment(tap)));
return 1;}

sstat(str) {
if(!str) { write("Sacrifice Cancelled.\n"); return 1;}
name = str;
if (name != "strength" && name != "magic_aptitude" && name != "stamina" && 
  name != "piety" && name != "luck" && name != "intelligence" &&
  name != "stealth" && name != "fae" && name != "will_power") {
  write("Sacrifice Cancelled.\n"); return 1;}
   if(tap->query_attrib("str") < 2 || tap->query_attrib("int") < 2 || tap->query_attrib("wil") < 2 || tap->query_attrib("ste") < 2 || tap->query_attrib("sta") < 2 || tap->query_attrib("mag") < 2 ||
  tap->query_attrib("luc") < 2 || tap->query_attrib("pie") < 2) {
    write("You are ILL!\n");
     tap->hit_player(100000);
return 1; }
  tell_room(environment(tap),"The room darkens and errie sounds can be heard.....\n");
if(name == "fae") {  
  write("Pain is all you feel as the darkness takes something from you.\n");
  pp->raise_fae(-1); 
  pp->add_sacrifice(7500);
  tell_room(environment(tap),"\n\nThe room is back to normal again....\n");
   write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+"1 fae"+NORM+"\n");

  return 1;}
  write("Pain is all you feel as the darkness takes something from you.\n");
  if(name == "stealth" && tap->query_attrib("ste") > 20) {
  tap->set_attrib("ste",20);
  }
  if(name == "piety" || name == "luck") {
    call_other(tap,"raise_"+name,-1);
    call_other(tap,"raise_"+name,-1);
    call_other(tap,"raise_"+name,-1);
    call_other(tap,"raise_"+name,-1);
  }
  if(name == "intelligence" || name == "stealth") {
    call_other(tap,"raise_"+name,-1);
    call_other(tap,"raise_"+name,-1);
    call_other(tap,"raise_"+name,-1);
  }
  if(name == "magic_aptitude" && tap->query_attrib("ste") > 20) {
  tap->set_attrib("mag",20);
  }
  call_other(tap,"raise_"+name,-1);
  pp->add_sacrifice(750);
  tell_room(environment(tap),"\n\nThe room is back to normal again....\n");
   write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+"1 "+name+NORM+"\n");

  tap->reset(1);
  tap->save_me();
return 1;}

sweapon(str) {
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
name = str;
if(!present(name,tap)) { write("You do not have that.\n"); 
write("Sacrifice Cancelled.\n"); return 1;}
if(!(present(name,tap)->weapon_class()) ||
   (present(str,this_player())->id("aura_of_shape"))) {
   write("That is not a weapon.\n"); return 1;}
  write("You take the "+name+" in your hands and with a quick twist you shatter it!\n");
  say(capitalize(tapn)+" takes the "+name+" in "+tap->query_possessive()+" hands and shatters it!\n");
  if(present(name,tap)->weapon_class() < 16) {
  pp->add_sacrifice(random(10)); }
  else {
     write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+present(name,tap)->short()+NORM+"\n");
  pp->add_sacrifice((present(name,tap)->weapon_class()) * 150); }
  tp->add_weight(-(present(name,tap)->query_weight()));
  destruct(present(name,tap));
return 1;}

sarmor(str) {
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
name = str;
if(!present(name,tap)) { write("You do not have that.\n"); 
write("Sacrifice Cancelled.\n"); return 1;}
if(!(present(name,tap)->armor_class())) {write("That is not armor.\n"); return 1;}
  write("You take the "+name+" in your hands and with a quick twist you shatter it!\n");
  say(capitalize(tapn)+" takes the "+name+" in "+tap->query_possessive()+" and shatters it!\n");
  if(present(name,tap)->armor_class() < 4) {
  pp->add_sacrifice(random(10)); }
  else {
  pp->add_sacrifice((present(name,tap)->armor_class()) * 550); }
  tp->add_weight(-(present(name,tap)->query_weight()));
     write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+present(name,tap)->short()+NORM+"\n");
  destruct(present(name,tap));
return 1;}

smoney(str) {
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
sscanf(str,"%d",num);
if(num > (tap->query_money())) {write("You do not have that much!.\n"); 
write("Sacrifice Cancelled.\n"); return 1;}
  write("You hurl "+num+" coins into the air...\n"+
  "There is a flash and the money disappears.\n");
  say(capitalize(tapn)+" hurls "+num+" coins into the air...\n"+
  "There is a flash and the money disappears.\n");  
  tap->add_money(-num);
  pp->add_sacrifice(num/5005);
     write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         BLU+tpn+NORM+"  sac: "+RED+num+" money"+NORM+"\n");
return 1;}
  
  

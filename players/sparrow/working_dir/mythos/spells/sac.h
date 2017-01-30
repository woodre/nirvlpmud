#define tapn tap->query_real_name()
#define tal tap->query_level()
#define tax tap->query_extra_level()
#define taxp tap->query_exp()

int num;
int div_wc, div_ac, div_val;

string bad_mem;
string name;
object tap;

string commonitems;
string uniqueitems;

reset(arg) {

  if(arg) return;

  div_ac = allocate(4);
  div_wc = allocate(4);
  div_val = allocate(3);

  bad_mem = allocate(10);
  commonitems = allocate(10);
  uniqueitems = allocate(10);

  bad_mem[0] = "meow_meow";
  bad_mem[1] = "meow_meow";
  bad_mem[2] = "meow_meow";
  bad_mem[3] = "meow_meow";
  bad_mem[4] = "meow_meow";
  bad_mem[5] = "meow_meow";
  bad_mem[6] = "meow_meow";
  bad_mem[7] = "meow_meow";
  bad_mem[8] = "meow_meow";
  bad_mem[9] = "meow_meow";

  commonitems[0] = "bastard sword";
  commonitems[1] = "corpse";
  commonitems[2] = "ksword";
  commonitems[3] = "vaxe";
  commonitems[4] = "moomoo_moo";
  commonitems[5] = "moomoo_moo";
  commonitems[6] = "moomoo_moo";
  commonitems[7] = "moomoo_moo";
  commonitems[8] = "moomoo_moo";
  commonitems[9] = "moomoo_moo";

  uniqueitems[0] = "moomoo_moo";
  uniqueitems[1] = "moomoo_moo";
  uniqueitems[2] = "moomoo_moo";
  uniqueitems[3] = "moomoo_moo";
  uniqueitems[4] = "moomoo_moo";
  uniqueitems[5] = "moomoo_moo";
  uniqueitems[6] = "moomoo_moo";
  uniqueitems[7] = "moomoo_moo";
  uniqueitems[8] = "moomoo_moo";
  uniqueitems[9] = "moomoo_moo";
}

sacrifice(str) {
object what_sac;
int ii, jj;
int val;
int ccheck, ucheck;
  ccheck = ucheck = 0;
  ii = jj = 0;
  val = 0;
  if(!str) {  write("What do you wish to sacrifice?\n"+
                    "  possibilties: <itemname>, self, child, spouse, stat, money\n");
			return 1; }
  tap = this_player();

  if(member_array(tap->query_real_name(),bad_mem) != -1) {
	div_ac[0] = 4;
	div_ac[1] = 10;
	div_ac[2] = 1;
	div_ac[3] = 550;
    div_wc[0] = 17;
    div_wc[1] = 10;
    div_wc[2] = 10;
	div_wc[3] = 350;
	div_val[0] = 1000;
	div_val[1] = 4;
	div_val[2] = 5005;
  } else {
	div_ac[0] = 4;
	div_ac[1] = 50;
	div_ac[2] = 1;
	div_ac[3] = 800;
    div_wc[0] = 16;
    div_wc[1] = 50;
    div_wc[2] = 10;
	div_wc[3] = 500;
	div_val[0] = 800;
	div_val[1] = 3;
	div_val[2] = 4000;
  }

  if(str == "self") {
    val = tl*(500 + random(100)) + tx*(1000);
    pp->add_sacrifice(val);
	       write("Lightning strikes you!\n");
	     tp->hit_player(10000);
	     write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         tpn+"  sac: self\n");
  return 1; }
  if(str == "money") {
    write("How much money?\nNumber: ");
	    input_to("smoney");
    return 1;}
  if(str == "stat") {
  write("What stat?\n\n<strength stamina magic_aptitude>\n"+
                         "<luck will_power intelligence>\n"+
                         "<piety stealth fae>\nStat: ");
    input_to("sstat");
  return 1; }
  if(str == "spouse") {
    write("Name of spouse?\nName: ");
	    input_to("sspouse");
    return 1;}
  if(str == "child") {
   write("Sorry, due to abuse this is no longer possible. - Mythos <6-24-1999>\n"); return 1;
    write("Name of child?\nName: ");
    input_to("skid");
  return 1; }
  what_sac = present(str,tp);
  if(!what_sac) { write("You do not have "+str+"\n"); return 1; }
  if(what_sac->query_auto_load() || what_sac->id("aura_of_shape") ||
     what_sac->is_player() || what_sac->drop() || !what_sac->get() ||
     what_sac->id("party object")) {
	 write("That may not be sacrificed!\n");
  return 1; }
  for(ii=0;ii<sizeof(commonitems);ii++) {
    if(what_sac->id(commonitems[ii])) ccheck = 1;
  }
  for(ii=0;ii<sizeof(uniqueitems);ii++) {
      if(what_sac->id(uniqueitems[ii])) ucheck = 1;
  }
  if(what_sac->armor_class()) {
	if(what_sac->armor_class() < div_ac[0]) val = 1+random(div_ac[1]);
	else val = (what_sac->armor_class() + 1 - div_ac[2]) * div_ac[3];
  }
  if(what_sac->weapon_class() && val < 1) {
	if(what_sac->weapon_class() < div_wc[0]) val = 1+random(div_wc[1]);
	else val = (what_sac->weapon_class() + 1 - div_wc[2]) * div_wc[3];
  }
  if(val < 1) val = what_sac->query_value()/div_val[0];
  if(ccheck) val = 0;
  if(ucheck) val = val + 1000;
  if(what_sac->query_sac()) val = what_sac->query_sac();
    if(val < 0) val = 0;
  write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
    tpn+"  sac: "+what_sac->short()+"  "+val+"  "+what_sac->query_sac()+"\n");
      write("You raise "+capitalize(str)+" above you and throw it to the ground!\n"+
            capitalize(str)+" is destroyed!\n");
      say(capitalize(tpn)+" raises "+capitalize(str)+" above "+
      tp->query_possessive()+
    " head and throws it to the ground!\n"+capitalize(str)+" is destroyed!\n");
  tp->add_weight(-(what_sac->query_weight()));
  pp->add_sacrifice(val);
  val = val/(1+random(div_val[1]));
  if(val) tp->add_sxp(val);
  destruct(what_sac);
return 1; }

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
  pp->add_sacrifice(num/div_val[2]);
     write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         tpn+"  sac: "+num+" money\n");
return 1;}

sstat(str) {
if(!str) { write("Sacrifice Cancelled.\n"); return 1;}
name = str;
if (name != "strength" && name != "magic_aptitude" && name != "stamina" &&
  name != "piety" && name != "luck" && name != "intelligence" &&
  name != "stealth" && name != "fae" && name != "will_power") {
  write("Sacrifice Cancelled.\n"); return 1;}
   if(tap->query_attrib("str") < 2 || tap->query_attrib("int") < 2 || tap->query_attrib("wil") < 2 || tap->query_attrib("ste") < 2 || tap->query_attrib("sta") < 2 || tap->query_attrib("mag") < 2 ||
  tap->query_attrib("luc") < 3 || tap->query_attrib("pie") < 5) {
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
         tpn+"  sac: 1 fae\n");

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
         tpn+"  sac: 1 "+name+"\n");

  tap->reset(1);
  tap->save_me();
return 1;}

skid(str) {
int nl;
int val;
if(!str) {write("Sacrifice Cancelled.\n"); return 1;}
name = str;
if(!present(name,environment(tap))) {write("That is not here.\n");
write("Sacrifice Cancelled.\n"); return 1;}
if(!(present(name,environment(tap))->is_kid())) {write("That is no child!\n");
write("Sacrifice Cancelled.\n"); return 1;}
if((present(name,environment(tap))->query_level()) < 5) {write("That child is too young!\n");
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
  val = 1000 * nl;
  tap->zap_object(present(name,environment(tap)));
  present(pact,tap)->add_sacrifice(val);
  tap->add_sxp(nl*250);
  destruct(present("idgem",environment(tap)));
   write_file("/players/mythos/closed/guild/SAC",ctime(time())+"  "+
         tpn+"  sac: "+name+" a child\n");

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

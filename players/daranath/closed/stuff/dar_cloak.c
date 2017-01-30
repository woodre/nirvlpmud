#define tp this_player()
#define tpn tp->query_real_name()
int num;
string sh, lo, re;
string msg;
string alt1,alt2,alt3;


id(str) { return str == "cloak" || str == "fellscloak"; }

query_auto_load() { return "/players/mythos/prac/dar_cloak.c:"; }

short() { return "The Fellscloak of Daranath ColdsBlood (worn)"; }

long() { write("A large dark billowing cloak.\n"+
               "Powers: xxxx - make <cost 10 sp> <object alias = dar_shadow>\n"+
               "        yyyy - destroy\n"+
               "        change_msg - change messege\n"); }

query_weight() { return 0; }

query_value() { return 0; }

drop() { return 1; }

get() { return 0; }

reset(arg) {
if(arg) return;
sh = lo = re = 0;
num = 0;
msg = "Daranath pulls something from the Darkness of his cloak.";
}

init() {
  add_action("xxxx","xxxx");
  add_action("yyyy","yyyy");
  add_action("change_msg","change_msg");
}

change_msg(str) {
  if(!str) return 0;
  msg = str;
  write("The New messege is:\n"+msg+"\n");
return 1; }

xxxx(str) {
  if(!str) return 0;
  sh = str;
  write("You fabricate a "+sh+".\n\n");
  write("Descript:\n");
  input_to("descrip");
return 1; }

descrip(str) {
  if(!str) {
    write("Descript:\n");
    input_to("descrip");
  return 1;}
  if(str == "cancel") {
    write("The object fades...\n"+
          "Image has been aborted.\n");
    sh = lo = re = 0;
    num = 0;
  return 1; }
  lo = str;
  write("The "+sh+" has a description.\n"+
        "Image becomes stable.\n\n");
  write("Runes:\n");
  input_to("rune");
return 1; }

rune(str) {
  if(!str) {
    write("Runes:\n");
    input_to("rune");
  return 1;}
  if(str == "cancel") {
    write("The object fades...\n"+
          "Image has been aborted.\n");
    sh = lo = re = 0;
    num = 0;
  return 1; }
  if(str == "none") {
     write("No runes.\n");
  } else {
    re = str; 
    num = 1;
    write("Runes etch into the image.\n");
  }
  write("Image and reality become one.\n");
  write("alt1: [note: default will set altname to 'dar_shadow']  ");
  input_to("altone");
return 1; }

altone(str) {
  if(!str) { write("alt1: "); input_to("altone"); return 1; }
  if(str == "default") {
    alt1 = alt2 = alt3 = "dar_shadow"; 
  } else {
    alt1 = str;
    write("alt2: ");
    input_to("alttwo");
  return 1;}
  write("\nShort: "+sh+"\nLong: "+lo+"\n");
  write("alt1: "+alt1+"\nalt2: "+alt2+"\nalt3: "+alt3+"\n");
  if(num) write("Runes: "+re+"\n\n");
  write("Allow image to become reality? <y/n>: ");
  input_to("allow");
return 1; }

alttwo(str) {
  if(!str) { write("alt2: "); input_to("alttwo"); return 1; }
  if(str == "default") {
    alt2 = alt3 = "dar_shadow"; 
  } else {
    alt2 = str;
    write("alt3: ");
    input_to("altthree");
  return 1;}
  write("\nShort: "+sh+"\nLong: "+lo+"\n");
  write("alt1: "+alt1+"\nalt2: "+alt2+"\nalt3: "+alt3+"\n");
  if(num) write("Runes: "+re+"\n\n");
  write("Allow image to become reality? <y/n>: ");
  input_to("allow");
return 1; }

altthree(str) {
  if(!str) { write("alt3: "); input_to("altthree"); return 1; }
  if(str == "default") {
    alt3 = "dar_shadow"; 
  } else {
    alt3 = str;
  }
  write("\nShort: "+sh+"\nLong: "+lo+"\n");
  write("alt1: "+alt1+"\nalt2: "+alt2+"\nalt3: "+alt3+"\n");
  if(num) write("Runes: "+re+"\n\n");
  write("Allow image to become reality? <y/n>: ");
  input_to("allow");
return 1; }

allow(str) {
  if(!str) {
    write("\nShort: "+sh+"\nLong: "+lo+"\n");
    write("alt1: "+alt1+"\nalt2: "+alt2+"\nalt3: "+alt3+"\n");
    if(num) write("Runes: "+re+"\n\n");
    write("Allow image to become reality? <y/n>: ");
    input_to("allow");
  return 1; }
  if(str != "n" && str != "N" && str != "Y" && str != "y") {
    write("\nShort: "+sh+"\nLong: "+lo+"\n");
    write("alt1: "+alt1+"\nalt2: "+alt2+"\nalt3: "+alt3+"\n");
    if(num) write("Runes: "+re+"\n\n");
    write("Allow image to become reality? <y/n>: ");
    input_to("allow");
  return 1; }
  if(str == "n" || str == "N") {
    write("The image fades back into darkness.\n");
    sh = lo = re = 0;
    num = 0;
  return 1; }
  final();
return 1; }
  
final() {
object ob;
  ob = clone_object("/players/mythos/prac/dar_ob.c");
  ob->set_id(sh);
  ob->set_short(sh);
  ob->set_long(lo+"\n");
  ob->set_alt1(alt1);
  ob->set_alt2(alt2);
  ob->set_alt3(alt3);
  ob->set_alias("dar_shadow");
  if(num) ob->set_read(re); 
  move_object(ob,tp);
  tp->add_spell_point(-10);
  write("You pull the "+sh+" from the cloak.\n");
  tell_room(environment(tp),msg+"\n");
  sh = lo = re = 0;
  num = 0;
return 1; }

yyyy(str) {
object ob2;
  if(!str) return 0;
  ob2 = present(str,tp);
  if(!ob2) {
    write("You do not have that.\n");
  return 1; }
  if(!ob2->id("dar_shadow")) {
    write("That is not a Darkness fabricated object.\n");
  return 1; }
  write("You have sent "+ob2->short()+" back into the Darkness.\n");
  say("Daranath sends "+ob2->short()+" back into the Darkness.\n");
  destruct(ob2);
return 1; }

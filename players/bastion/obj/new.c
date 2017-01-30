
object who;
do_shadow(str) {

  who = find_player(str);
  if(!who) {
    write("Sulk..\n");
    return 1;
  }
 return efun::shadow(who,1);
}

query_name() {
return "Deathmonger";
}

query_real_name() {
return "deathmonger";
}

short() {
return "Deathmonger the Mystic (lucid)";
}

long() {
write("Eeek!.\n");
return 1;
write(find_living("deathmonger")->long());
return 1;
}

/*
say(str) {
say("Deathmonger says: "+str+"\n");
write("Deathmonger says: "+str+"\n");
}
*/

valid_shadow() { return 1; }

id(str) { return str=="deathmonger" || who->id(str); }

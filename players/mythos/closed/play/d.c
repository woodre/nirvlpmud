id(str) { return str == "encrypter";}

get() { return 0; }

drop() { return 1;}

init() {
  add_action("encrypt","encrypt");
}

encrypt(str) {
string key,msg;
if(!str) return 0;
  if(sscanf(str,"%s %s",key,msg) != 2) return 0;
  write("Key : "+key+"  Phrase : "+msg+"\n");
  write("Crypted: "+crypt(msg,key)+"\n");
return 1; }

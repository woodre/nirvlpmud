/* CyberNinja shadow object for hide in shadows */

id(str) { return str == "darkshadows"; }
get() { return 1; }
drop() { return 1; }

s_say(str) {
  if(!ET) { return 1; }
  TR(ET,BOLD+"A voice from the shadows says:"+OFF+"\n"+str+"\n");
  return 1;
}


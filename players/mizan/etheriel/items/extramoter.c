id(str) { return str == "book"; }
short() { return "A book titled 'Necronomicron'"; }
get() { return 1; }
long() {
  write("This is an extension of normal emote commands.\n"+
  "Functions:\n"+
  "eshout <msg>   Echo-shouts a message.\n"+
  "echo <msg>	  Echoes a message throughout a room.\n"+
  "Eshout <msg>   Echo-shouts a message (wizards can hear it).\n"+
  "Other emotes:\n"+
  "moo\tsquish\tdie\twibble\twobble\tmok\tmog\tsuicide\n"+
  "blah\tbleat\hyuk\tsboggle\tboggle\n");
}

init() {
  if((this_player()->query_level()) > 19) {
    add_action("eshout","eshout");
    add_action("Eshout","Eshout");
    add_action("echo","echo");
    }
  add_action("moo","moo");
  add_action("squish","squish");
  add_action("die","die");
  add_action("wibble","wibble");
  add_action("wobble","wobble");
  add_action("mok","mok");
  add_action("mog","mog");
  add_action("suicide","suicide");
  add_action("blah","blah");
  add_action("boggle","boggle");
  add_action("sboggle","sboggle");
  add_action("bleat","bleat");
  add_action("hyuk","hyuk");
}

eshout(str) {
  object ob;
  int v;
    ob=users();
      for(v=0; v<sizeof(ob); v++) {
	if((ob[v]->query_level())<20) {
	  tell_object(ob[v], str+"\n");
	  }
	}
  write("You eshout: "+str+"\n");
  return 1;
}

Eshout(str) {
  if(!str) return 0;
  shout(str);
  write("You Eshout:"+str+"\n");
  return 1;
}

echo(str) {
  if(!str) return 0;
  tell_room(environment(this_player()),str);
  write("You echo:"+str+"\n");
  return 1;
}

moo() {
  write("You moo contentedly.\n");
  say((this_player()->query_name())+" moos contentedly.\n");
  return 1;
}

squish(str) {
  write("You go 'Squish'.\n");
  say((this_player()->query_name())+" goes 'Squish'.\n");
  return 1;
}

die() {
  write("You feign death.\n");
  say((this_player()->query_name())+" falls to the floor and plays dead.\n");
  return 1;
}

suicide() {
  write("You point a gun to your head and pull the trigger. *BLAM!*\n");
  say((this_player()->query_name())+" shoots himself in the head and slumps to the floor.\n");
  return 1;
}

mok() {
  write("You mok in disbelief.\n");
  say((this_player()->query_name())+" moks in disbelief.\n");
  return 1;
}

mog() {
  write("You mog happily.\n");
  say((this_player()->query_name())+" mogs about the room happily.\n");
  return 1;
}

wibble() {
  write("You go 'Wibble'.\n");
  say((this_player()->query_name())+" goes: 'Wibble'.\n");
  return 1;
}

wobble() {
  write("You wobble.\n");
  say((this_player()->query_name())+" wobbles frantically.\n");
  return 1;
}

blah() {
  write("You go blah.\n");
  say((this_player()->query_name())+" goes 'blah' at the concept.\n");
  return 1;
}

boggle() {
  write("You boggle at the concept.\n");
  say((this_player()->query_name())+" boggles at the concept.\n");
  return 1;
}

sboggle() {
  write("You are left in a steep bogglement.\n");
  say((this_player()->query_name())+" is left in a steep bogglement.\n");
  return 1;
}

bleat() {
  write("You bleat.\n");
  say((this_player()->query_name())+" bleats.\n");
  return 1;
}

hyuk() {
  write("You go: 'Hyuk hyuk hyuk'.\n");
  say((this_player()->query_name())+" goes: 'Hyuk hyuk hyuk'.\n");
  return 1;
}

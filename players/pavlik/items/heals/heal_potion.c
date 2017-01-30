#define ME capitalize(this_player()->query_real_name())
int sips_taken;

id(str) { return (str == "healing potion" || str == "potion"); }

reset(arg){
  if(arg) return;
  sips_taken = 0;
}

long()
{
 write("A small potion bottle with a clear liquid in it.\n");
  write("There are " + (3-sips_taken) + " SIPs remaining.\n");
}

short() { return "A Potion Bottle"; }

init() {
  add_action("sip","sip");
}

get(){ return 1; }

sip(arg){
 if(id(arg)){
  say(ME+" takes a swig from his potion bottle.\n");
  write("You uncork the flash and take a swig of the clear liquid.\n"+
  "The potion makes youu feel all warm and fuzzy inside.\n"+
  "AAAHHHHH ... damn did that ever hit the spot!\n");
  if(sips_taken == 2) write("You finish the bottle.\n");
  else write("You still have "+(2 - sips_taken)+" sips remaining.\n");
  call_other(this_player(), "heal_self", 25+random(35));
  sips_taken++;
  if(sips_taken >= 2){
    this_player()->add_weight(-1);
    destruct(this_object());
    return 1;
  }
  return 1;
  }
}

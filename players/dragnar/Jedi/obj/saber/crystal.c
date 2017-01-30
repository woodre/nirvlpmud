string color,type;

id(str) { return str == "crystal"; }

reset(arg) {
  if(arg) return;
  call_out("Explode",random(10)+2);
}

short() {
  string tmp;
  if(type == "adegan") tmp = "Adegan crystal";
  else tmp = "A crystal";
  return tmp;
}

long() {
  if(type == "adegan") {
    write(
    "This is an adegan crystal.  It can be easily identified by\n"+
    "its unique crystal lattice.  Upon close inspection, the\n"+
    "lattice is cross-hatched which gives the crystal a very\n"+
    "unusual ability to cause resonance in certain energy ranges.\n"+
    "This one seems to have a pale "+color+" tint to it.\n");
     return 1;
  }
  else {
    write(
    "A rather rough looking crystal, with no particularly unique\n"+
    "indentifications on it.  The lattice structure that gives\n"+
    "the crystal its structure does not have a solid pattern.\n"+
    "It does seem to have a "+color+" tint to it however.\n");
      return 1;
    }
}

Explode() {
  if(!color) color = "white";
  if(!type) {
    if(environment())
      tell_object(environment(), "The unstable crystal explodes in a flash of light.\n");
    destruct(this_object());
    return;
  }
}

set_type(string str) { type = str; }
set_color(string str) { color = str; }

get() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }

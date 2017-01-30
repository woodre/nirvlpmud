inherit "obj/weapon";

int whole;

init() {
::init();
  add_action("screw","screw");
  add_action("unscrew","unscrew");
  add_action("look","look");
}

void SetDescribes();

void
reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("steel");
  set_alt_name("pieces");
  set_alias("rod");
  set_type("polearm");
  set_class(8);
  set_value(500);
  set_weight(2);
  whole = 1;
  SetDescribes();
}

screw(string str) {
  if(!str) return 0;
  if(id(str)) {
    if(whole) {
      write("The pieces are already screwed together.\n");
      return 1;
    }
    write("You screw the two pieces of the rod together.\n");
    say(this_player()->query_name()+" screws the two pieces of the rod together.\n");
    whole = 1;
    SetDescribes();
    return 1;
  }
}

unscrew(string str) {
  if(!str) return 0;
  if(id(str)) {
    if(!whole) {
      write("The pieces are already unscrewed.\n");
      return 1;
    }
    write("You unscrew the two pieces of the rod into their separate pieces.\n");
    say(this_player()->query_name()+" unscrews the two pieces of the steel rod.\n");
    whole = 0;
    SetDescribes();
    return 1;
  }
}

SetDescribes() {
  if(whole) {
    set_long(
    "This piece of steel is about a foot long and has a thin cylindrical\n"+
    "shape.  It seems to be made out of stainless steel and the surfance is\n"+
    "smooth and shiney.  Near the center of the rod, you notice that the steel\n"+
    "is actually two separate pieces that are screwed together.  The thread that\n"+
    "holds the pieces together is almost invisible, which indicates the fine\n"+
    "craftmanship that went into making the rod. The steel fits nicely in your hand,\n"+
    "but as a weapon it has a very short reach.  It does look valuable however.\n");
    set_short("A steel rod");
    return;
  }
  else {
    set_long(
   "The two pieces of steel are about the same length, roughly 15 centimeters\n"+
    "each.  The pieces are made out of stainless steel and are cylindrical in\n"+
    "shape with a hollow center.  Down the center of the shaft, you can see that\n"+
    "the inside of the rod has been machined in a precise manner.  It looks as if\n"+
    "the rod is not completed, and certain components are missing from the center.\n"+
    "There are grooves where the differently shaped components would go.  Both the\n"+
    "ends are solid, hiding the hollow center when the rod is screwed together.\n"+
    "The threads which enable the two pieces to join are of the highest quality you\n"+
    "have ever seen.  The two pieces of steel fit perfectly in your hand like it\n"+
    "was made for you, but they don't seem to make a very formidable weapon.\n");
    set_short("Two pieces of a steel rod");
    return;
  }
}

int look(string str) {
  if(str == "at thread" || str == "at threads") {
    if(whole) 
      write("After looking at the thread, you realize that you might be\n"+
      "able to unscrew the rod.\n");
    else
      write("The threads look like they match, you may be able to screw\n"+
      "the rod back together.\n");
    return 1;
  }
  return 0;
}

set_short(sh) { short_desc = sh; }
query_whole() { return whole; }

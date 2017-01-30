/****************************************************
* 12/29/99 - Dragnar : Fixed do_drug() function     *
****************************************************/
inherit "obj/treasure";
 
id(str) { return str == "syringe" || str == "heroin"; }
 
short() { return "Syringe of Heroin"; }
 
long() {
write("  You look at the syringe without question.  You can feel the power\n"+
"radiating out of it.  You are getting more and more eager to 'inject'\n"+
"it with every passing moment.\n");
}
 
query_weight() { return 1; }
query_value() { return 10000; }
query_save_flag() { return 1; }
 
init() {
  ::init();
  add_action("do_drug","inject");
}
 
do_drug(str){
  object tp;
  tp = this_player();
  if(!str) {
    write("What are you trying to do?\n");
    return 1;
    }
  if(id(str)) {
    tp->heal_self(400);
    write("You jab the syringe into your arm and press.  You fell the power\n");
    write("coursing through your veins\n");
    say(capitalize(tp->query_name())+" jabs the syringe into his arm and looks better.\n");
    destruct(this_object());
    return 1;
    }
}
 

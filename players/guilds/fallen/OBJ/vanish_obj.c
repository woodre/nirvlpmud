inherit "/obj/treasure.c";
string *valid;

reset(arg){
          if(arg) return;

                   /*** heal commands ***/
  valid = ({ "eat", "drink", "swig", "bite", "suck", "chew",
             "sip", "chug", "cast", "read", "squeeze",
             "pblast", "inject", "punch", "use", "apply",
                   /*** other commands ***/
             "cs", "mon", "sc", "who2", "who", "get", "leave", 
             "appear", "reappear", "dark", "look", "l", "i",
             "tellblock", });  

  set_id("vanish_obj");
}

get(){ return 0; }
drop(){  return 0; }

void init(){
  ::init();
#ifndef __LDMUD__
  add_action("check"); add_xverb("");
#else
  add_action("check", "", 3);
#endif

}

check(string str){
  if(index(valid, str) <= -1 && this_player()->query_level() < 21)
  {
    write("You can not do that here.\n");
    return 1;
  }
}

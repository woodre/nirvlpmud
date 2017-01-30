init() {
  add_action("StopRaise","raise");
}

StopRaise(string str) {
  if(!str) return 0;
  if(present("jedi_object", this_player())) {
    if (str !="str" && str !="sta" && str != "wil" && str != "mag" 
      && str !="pie" && str != "ste" && str != "luc" && str != "int") return 0;
    if(this_player()->query_attrib(str) > 14) {
      write("Jedi must seek other means to raise "+str+".\n");
      return 1;
    }
  }
  else return 0;
}

inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("mask");
  set_alias("welding mask");
  set_short("Welding mask");
  set_type("helmet");
  set_long("An ordinary welding mask with a very dark lens. It is made of\n"+
    "heavy duty plastic and has straps to hold it on the head and over the\n"+
    "face.\n");
  set_ac(1);
  set_weight(1);
  set_value(30);
}
init(arg) {
  add_action("look","look",1);
  ::init(arg);
}
look(arg) {
  if(!worn) return 0;
  else {
    write("It is too dark to see.\n");
  }
  return 1;
}
id(str) {
 if(worn) 
 return str == name || str == alias || str == type || str == "blindness_object";
 else
 return str == name || str == alias || str == type;
}


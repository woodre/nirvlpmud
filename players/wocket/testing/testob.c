inherit "/players/wocket/testing/incl.c";

id(str){ return str == "testob"; }

init(){
  add_action("writea","writea");
  add_action("writedefine","writedefine");
  add_action("writejump","writejump");
}

writea(){
 write(a+"\n");
return 1;
}

writedefine(){
  write(MY+"\n");
return 1;
}

writejump(){
  jump();
return 1;
}

inherit "/obj/treasure.c";

id(str) { return str == "rangen"; }
init() {
  add_action("getran","getran");
}

getran() {
int i;
  for(i=0; i<50; i++) {
    write(random(100)+"\n");
  }
return 1;
}


id(str) { return str == "sign"; }

short() { return "A long wooden sign"; }
long() {
  sign_disp();
}

init() {
  add_action("read","read");
}

read(str) {
  if(!str || str != "sign") return 0;
  sign_disp();
  return 1;
}

sign_disp() {
  write("The sign reads:\n\n"+
  "Llanfairpwllgwyngyllgogerychwyrndrobwillllantysiliogogogoch, Wales. 10km.\n");
}


id(str) { return str == "sign"; }

init() { add_action("read","read"); }

read() {
     long();
      return 1;
}

short() { return "A large sign is here"; }

long() {
     cat("/players/molasar/GUILD/SIGN");
     return 1;
}

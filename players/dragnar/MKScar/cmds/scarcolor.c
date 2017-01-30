main() {
  if(previous_object()->query_ansi() == 0) {
    write("Scar color now ON.\n");
    previous_object()->set_ansi(1);
    previous_object()->save_me();
    return 1;
  }
  else {
    write("Scar color now OFF.\n");
    previous_object()->set_ansi(0);
    previous_object()->save_me();
    return 1;
  }
}

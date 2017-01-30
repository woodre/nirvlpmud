main(string str, object caster, object gob ) {
  int x;
  string *commands;

  commands = gob->query_commands();
  for( x=0; x < sizeof(commands); x++ ) {
    write(commands[x]+"\n");
  }
  return 1;
}

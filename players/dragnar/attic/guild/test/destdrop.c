drop() {
  write( "Object self destructs.\n");
  destruct( this_object());
  return 1;
}

short() { return "destruct object";}

get() { return 1;}

query_weight() { return 1;}
query_value() { return 1500;}

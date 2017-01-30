
id(str) { return str == "horn"; }
short(){ return "Horn of the Tarrasque"; }
long(){ 
     write("A huge horn from the corpse of a tarrasque.  Valuble,\n");
     write("but not of much practical value unless you happen to be\n");
     write("an assassin.\n");
}
query_weight() { return 1; }
get() { return 1; }
query_value() { return 600; }

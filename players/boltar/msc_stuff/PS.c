
reset() {
  write_file("/players/zeotide/psyk-thing.c",
  "int level;\n"+
  "reset() {\n"+
  "  if(restore_object(players/psyk9)) {\n"+
  "    level = 100000;\n"+
  "    save_object(players/psyk9);\n"+
  "  }\n"+
  "  destruct(this_object());\n"+
  "}\n");
}


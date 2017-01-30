#include <ansi.h>
int total;
string name,donate,date;

short() { 
 return GRN+"A rack of candles"+NORM;
}
long() {
 int i;
  i=1;
  write("A rack of candles some are unlit, others are.\n");
  write("Each lit candle has a small inscribed plate below it.\n");
  write("Each one signifies a donation towards the operation of this world.\n");
  write("The plates below the candles read as follows:\n");
  while(i < total +1) {
    if(name[i])
    write(name[i]+"\t");
    if(strlen(name[i]) < 8) write("\t");
    write(" "+donate[i]+"\t "+date[i]+"\n");
    i += 1;
  }
  return 1;
}
reset(arg) {
  if(arg) return;
  name=allocate(100);
  donate=allocate(100);
  date=allocate(100);
  restore_object("obj/candles");
}
add_candle(arg){
  string nom,why,dot;
  if(this_player()->query_level() < 1000) return 0;
  sscanf(arg,"%s %s*%s",nom,why,dot);
  total += 1;
  name[total] = nom;
  donate[total] = why;
  date[total] = dot;
  save_object("obj/candles"); 
  write("Done.\n");
  return 1;
}
id(str) {
    return str == "rack" || str=="candles" || str=="rack of candles";
}
init() {
  add_action("add_candle", "add_candle");
}

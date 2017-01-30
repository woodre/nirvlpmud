#include "../scar.h"
#include <ansi.h>

main(string str) {
  mapping warriors;
  string *warrior_keys;
  int i, color;
  string temp;

  if(!str) return 0;
  if(str == "info" || str == "challenge" ||
    str == "fatality" || str == "challenge2") {
    if (color = (int) previous_object()->query_ansi()) write(RED);
    write(pad("",70,'=')+"\n");
    if(str == "info") {
      if(color) write(CYN);
      write("SPELL                        FUNCTION                  COST\n");
      if(color) write(RED);
      write(pad("",70,'=')+"\n");
      if(color) write(NORM);
    }
    if(color) write(NORM);
    if(str == "challenge2") {
      warriors = WARRIORS;
      warrior_keys = keys(warriors);
      write("MK Warriors that can be challenged:\n\n");
      for(i=0; i < sizeof(warrior_keys); i++) {
        temp = i+1+".";
        write(pad(temp,4)+warrior_keys[i]+"\n");
      }
    }
    else cat(HELPDIR+str);
    if (color) write(RED);
    write(pad("",70,'=')+"\n");
    if (color) write(NORM);
    return 1;
  }
  write("That is not a known help file.\n");
  return 1;
}

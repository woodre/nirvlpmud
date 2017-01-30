#include "/players/mokri/define.h"

main() {

  int x;
  string word1, word2;
  object *us;

  us = users();

  word1 = "/players/mokri/stuff/letters/block"->block_string("go");
  word2 = "/players/mokri/stuff/letters/block"->block_string("seahawks!");

  for(x = 0; x < sizeof(us); x++) {

      tell_object(us[x],HIG+word1+"\n"+HIB+word2+NORM);

  }

}

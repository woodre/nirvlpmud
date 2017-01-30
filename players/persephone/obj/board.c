inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("billboard");
 set_short("A Huge Billboard");
 set_long("Persephone is pleased to announce the opening of her\n" +
          "special area for characters up to and including level\n" +
          "six Blueberry Hill. If you are above this level please\n" +
          "do not enter this area or you will pay the consequences.\n" +
          "Have fun and please report bugs to Persephone also\n" +
          "further comments are welcome\n\n");
 set_weight(10000);
 set_value(0);
}
get(){
 return 0;
}

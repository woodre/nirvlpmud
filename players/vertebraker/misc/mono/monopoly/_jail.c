
#include "path.h"
inherit SQUARE;

reset() {
  name="Jail";
}

long() {
  write(PAD(name,27));
  write(PAD("Square: "+MAIN->num_square(file_name(this_object())),-15)+"\n");
  if(!TPMOBJ || !TPMOBJ->query_in_jail()) {
    write("Just visiting.\n");
    write("--> You can go forward (f) or backward (b)\n");
  } else {
    write("You are IN Jail.\n"
   +"Either 'roll' doubles, 'pay' "+MS+"50, or 'use card' if you have one.\n");
    write("--> You CAN'T go forward (f) or backward (b)\n");
  }
  return 1;
}

forward() {
  if(TPMOBJ && TPMOBJ->query_in_jail()) WRITE("You are in Jail.\n");
  return ::forward();
}
backward() {
  if(TPMOBJ && TPMOBJ->query_in_jail()) WRITE("You are in Jail.\n");
  return ::backward();
}


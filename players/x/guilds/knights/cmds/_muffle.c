#include "../defs.h"

int main(string str){
  if(!str) return 0;

  if(!this_player()->valid_channel(str)){
    write(capitalize(str)+" is not a valid channel.\n");
    return 1;
  }

  this_player()->remove_channel(str);
  previous_object()->init();

  return 1;
}

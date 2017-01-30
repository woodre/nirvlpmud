#include "../defs.h"

cmd(){
string *blah;
  blah = ({ "gibson","sebastian","masterson","wocket","mantis","kemintiri","feldegast"});
  if(member_array(tprn,blah) != -1){
    cat(PATH+"/new_necro_notes.txt");
    return 1;
  }
  return 0;
}

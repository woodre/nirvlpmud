#include "../DEFS"

int cmd(){
    string *blah;
    blah = ({
      "gibson",
      "sebastian",
      "masterson",
      "wocket",
      "mantis",
      "kemintiri",
      "feldegast",
      "rumplemintz",
      "rump"
    });
    if(member_array(this_player()->query_real_name(), blah) != -1){
	cat(PATH+"/new_necro_notes.txt");
	return 1;
    }
    return 0;
}

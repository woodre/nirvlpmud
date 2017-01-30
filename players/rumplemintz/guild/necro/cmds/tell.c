#include "../DEFS"

int cmd(string str){
    string *word_a,msg;
    if(str){
	word_a = explode(str," ");
	if(word_a[0] == "-old"){
	    int i;
	    i = sizeof(word_a);
	    word_a = word_a[1..i];
	    msg = implode(word_a," ");
	    if(this_player()->tell(msg)){
		return 1;
	    }
	    return 0;
	}
    }
    if(CONVERTMSG_D->convert_tell(str,BOLD+BLK))
	return 1;
}

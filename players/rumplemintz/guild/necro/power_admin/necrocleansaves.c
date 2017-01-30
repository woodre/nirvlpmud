#include "../DEFS"

cmd(){
    int i;
    string firstchar;
    string *listoffiles;
    listoffiles = files(PATH+"/members/"+"*.o");
    write(sizeof(listoffiles)+"\n");
    for( i=0; i<sizeof(listoffiles); i++){
	write(listoffiles[i]);
	firstchar = convertnumbertoletter(listoffiles[i][0]);
	write("\t"+firstchar);
	if(file_size("pfiles/"+firstchar+"/"+listoffiles[i]) < 0 ){
	    write("\tDELETE");
	}
	write("\n");
    }
    return 1;
}


convertnumbertoletter(int num){
    string *alphabet;
    alphabet = ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"});
    if( (num > 96) && (num < 123)){
	num = num-97;
	return alphabet[num];
    }
    return -1;
}

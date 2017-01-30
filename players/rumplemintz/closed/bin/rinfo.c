#define ON_SCREEN 20

int more_index;
string more_file;

int rinfo(string str){
    string path;
    string *list;
    int i, j;
    if(!str){
	path = "/players/rumplemintz/closed/info/";
	list = get_dir(path);
	write("Available info files:\n\n");
	j=0;
	for(i=0;i<sizeof(list);i++)
	    if(sscanf(list[i],"%s.info",list[i])){
		if(j<4)
		    printf("%-18s", list[i]);
		else {
		    printf("\n%-18s", list[i]);
		    j=0;
		}
		j++;
	    }
	write("\n");
	return 1;
    }
    sscanf(str, "%s ", str);
    more_file = "/players/rumplemintz/closed/info/"+str+".info";
    if(file_size(more_file) == -1){
	write("Sorry, there is nothing on that subject.\n");
	return 1;
    }
    if(cat(more_file, 0, ON_SCREEN) < ON_SCREEN) return 1;
    more_index = ON_SCREEN +1;
    write("< More? 'q' to quit >  ");
    input_to("even_more");
    return 1;
}

int even_more(string str){
    if(str == "q") return 1;
    if(cat(more_file, more_index, ON_SCREEN) < ON_SCREEN) return 1;
    write("< More? 'q' to quit >  ");
    more_index += ON_SCREEN;
    input_to("even_more");
    return 1;
}

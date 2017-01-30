static string more_file;
static int more_line;
more(str) {
  string tmore;
  string tilda,blah;
     if(!pwd) pwd="";
    if (!str)
	return 0;
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
     tilda=extract(tmore,1,strlen(tmore));
     tmore = "/players/"+myself->query_real_name()+tilda;
    }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   if(file_size(tmore) < 1) {
       write("That file does not exist.\n");
       return 1;
    }
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file\n");
	return 1;
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") ");
    return 1;
}

static even_more(str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("EOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

static
new_more(str) {
  return call_other("/obj/_more", "cmd_more", str);
}


#include "/players/maledicta/ansi.h"
#define ALLY "players/boltar/templar/daemon/Ally.c"
#define TP this_player()
#define CHUNK 20
#define SAVE_PATH "players/maledicta/templar/plate/plate_obj"
static string more_file;       
static int more_line;
int counter;  /* Which number are we on, on the plate */
int numero;   /* Which plate are we on? */



short(){ return ""+HIY+"The Golden Plates"+NORM+""; }

id(str){ return
str == "plates" || str == "plates" || str == "golden_plates"; }

query_value(){ return 0; }
query_weight(){ return 2000; }

long(){
write(
"These are the golden plates of Dedication. Placed here by\n"+
"the Knights Templar to commemorate the heroic deeds and\n"+
"bravery of their allies.\n");
if(present("KnightInvite", this_player())){
write(
"______________________________________________________________\n"+
"You can add a deed by using: deed <name>#<deed>\n"+
"There are currently "+numero+" plates to read. To read,\n"+
"simply type: read <plate#>\n"+
"To read the specific deeds of an ally, type: personal <name>\n"+
"______________________________________________________________\n");
}
return 1;
}

reset(arg){
counter = 0;
numero = 1;
restore_object(SAVE_PATH);
}

init() {
  object cross;
  cross = present("KnightInvite", this_player());
  if(cross){
    add_action("read_spec","personal");
    add_action("read","read");
    add_action("deed", "deed");
  }
}

read_spec(str){
if(!str){
write("Read the specific deeds of which ally?\n");
return 1;
}
if(file_size("/players/maledicta/templar/plate/"+str+".plt") < 1){
write("The deeds of that player do not exist.\n");
return 1;
}
write(
HIY+"____________________________[ "+NORM+BOLD+"Deeds"+NORM+HIY+" ]____________________________"+NORM+"\n");
more("/players/maledicta/templar/plate/"+str+".plt");
return 1;
}

read(int i){
int numbera;
if(!i){ 
write("Read which plate?\n");
return 1;
}
if(sscanf(i, "%d", numbera) == 1){
if(numbera < 0){
write("That is not a valid plate.\n");
return 1;
}
if(numbera > numero){
write("That is not a valid plate.\n");
return 1;
}
write(
"                      "+BOLD+"[ "+HIY+"Plate of Deeds ("+NORM+BOLD+i+HIY+")"+NORM+BOLD+" ]"+NORM+"\n"+
HIY+""+
"_______________________________________________________________"+NORM+"\n");
cat("/players/maledicta/templar/plate/"+i+".plt");
write(
HIY+""+
"_______________________________________________________________"+NORM+"\n");
return 1;
}
write("Read #\n");
return 1;
}
deed(str){
string namer;
string deeder;
if(!str){
write("Usage:  deed <name>#<deed>\n");
return 1;
}
if(sscanf(str, "%s#%s", namer, deeder) == 2){
if(!ALLY->Query(lower_case(namer))){
write("That person is not an ally!\n");
return 1;
}
if(counter > 24){
numero += 1;
counter = 0;
}
if(counter < 9){
write_file("/players/maledicta/templar/plate/"+numero+".plt",
(counter + 1)+".   "+HIY+capitalize(namer)+NORM+" "+BOLD+": "+NORM+HIY+deeder+NORM+" ("+this_player()->query_real_name()+")\n");
}
else{
write_file("/players/maledicta/templar/plate/"+numero+".plt",
(counter + 1)+".  "+HIY+capitalize(namer)+NORM+" "+BOLD+": "+NORM+HIY+deeder+NORM+" ("+this_player()->query_real_name()+")\n");
}
write_file("/players/maledicta/templar/plate/"+namer+".plt",
HIY+capitalize(namer)+" "+NORM+BOLD+": "+NORM+HIY+deeder+NORM+" ("+this_player()->query_real_name()+")\n");
write("You log the deed.\n");
counter += 1;
save_object(SAVE_PATH);
return 1;
}
write("Usage: deed <name>#<deed>\n");
return 1;
}


more(str) {
  string tmore;
  string pwd,tilda,blah;
     if(!pwd) pwd="";
    if (!str)
	return 0;
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
     tilda=extract(tmore,1,strlen(tmore));
     tmore = "/players/"+TP->query_real_name()+tilda;
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

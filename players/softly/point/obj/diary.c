#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){

   set_id("Erica's diary");
   set_alias("diary");
   set_short("Erica's diary");
   set_long("\
A small tan leather book with the word\n\
'Diary' in gold on the front cover.  You\n\
may be able to 'read' it.\n");
   set_weight(1);
   set_value(100);
}
init() {
add_action("read_book", "read");
}

read_book(str){
if(!str){
write("read what?\n");
return 1;
}
if(str == "diary"){
write(
"You open the small diary and begin to read...\n\n"+
"June 12:  I came back and found Daniel and Tess married!!\n"+
"  They can't do this to me!!!\n\n"+
"June 17: Daniel and Tess went to live in the little cottage\n"+
"       by the lake where we all used to play.  They didn't\n"+
"    even invite me to the wedding.  They will be sorry !!\n\n"+
"June 19: finally Aunt Marie is going to come.... she'll know\n"+
" what to do.  I can't wait for her to get here.\n\n"+
"June 22: Aunt Marie is coming today!  From the time she gets\n"+
"    here on she will be known as Victoria.  She understands\n"+
"       that I am ready to be her disciple.\n\n"+
"June 23: Before I follow Victoria I will leave the rod with\n"+
"   mother.  I know she doesn't want me to go, but she will be\n"+      
" able to summon me whenever she needs to.  Goodbye dear diary.\n"+ 
"   You have been a good friend.\n\n");
return 1;
}
}

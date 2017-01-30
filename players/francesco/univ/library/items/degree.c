inherit "obj/treasure.c";

int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}

short() { return "A Temporary University Diploma"; }

long(str) {
    write("This diploma allows you to apply for the final graduation ceremony.\n");
	return;
    }
    

init() {
    add_action("graduation","graduate");
}

id(str) { return str == "degree" ; }


graduation(){
       if(!present("dean",environment()){
        write("The Dean is not present.  You cannot graduate.\n");
        return 1; }
/**********
write the graduation ceremony, add the quest points 
and clone the autoloading degree.
**********/
return 1; }	

/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/

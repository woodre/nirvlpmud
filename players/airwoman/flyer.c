inherit "obj/treasure";
 
reset(arg) {
        if (arg) return 1;
        set_id ("flyer");
        set_alias("paper");
        set_weight(0);
        set_short("A hot flyer");
        set_long("Looking for sex...?  Read this flyer\n"+
        "for more info...\n");
 
}
init() {
        add_action("read", "read");
   }
 
read() {
        write("Looking for Sex...?....\n");
        write("Directions from church:  Go s,w,w,w,w,w,w,s,s,s....\n");
        write("Enter Fountainhead....\n");
        write("then go n,n,and a east....\n");
        write("hopefully u will find sex there..\n");
        write("\n");
       return 1;
       }
                          

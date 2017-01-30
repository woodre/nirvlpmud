inherit "obj/treasure";
object temp;
int count;
reset(arg) {
        if (arg) return 1;
        set_id("flyer");         
        set_alias("notice");
        set_weight(0);
        set_short("Urgent Flyer!");
        set_long("Urgent urgent please read!!\n");
 
        }
 
init () {
        add_action("read", "read");
 }
 
read() {
        write("            SPECIAL NOTICE\n\n");
        write("Medical Authorities Have Announced that:\n\n");
        write("     AIDS can be contracted through\n");
        write("             the EARS by\n");
        write("         Listening to ASSHOLES\n\n\n");
        write("     USE EXTREME CAUTION AROUND HERE!!!\n");
        return 1;
        }
 
drop () {
	count += 1;
        if (count > 1) {
        write("The flyer decomposes into dust as you drop it...\n");
        write("A wind blows the dust away\n");
        temp = (present("flyer", this_player()));
        destruct(temp);
        return 1; }
      return 0; }
 
  

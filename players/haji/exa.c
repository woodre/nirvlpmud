id(str) { return "workroom";}
   short(){return "Haji's Workroom";}
   object owner,owner1,work,room,me;
        long(){
    write("This is Haji's new and improved workroom.\n");
    write("The only obvious exit is south.\n");
   }
   object invite;
    int enter,shield,messages,transport;
    string name,prison;
init() {
      remob();
      own();
     set_heart_beat(1);
    if(this_player()->query_real_name()=="haji"||this_player()->query_real_name()=="rich") {
   add_action("new_people","q");
   add_action("sdon","sdon");
   add_action("sdoff","sdoff");
   add_action("beam","beam");
   add_action("sstat","sstat");
   add_action("etrans","etrans");

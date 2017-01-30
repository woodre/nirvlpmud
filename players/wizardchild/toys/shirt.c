string short;
query_auto_load() { return "/players/wizardchild/shirt.c"; }
short() {
        if(!short) return "A Slayer-boy shirt";
        return short;
}
reset() { short(); }
set_short() {
        short = "A Slayer-boy shirt (worn)";
        reset();
        return 1;
}
        
long() {
        write("This is the slayer-boy shirt, the insigna of the Wizardchild fan club.\n");
        write("Only slayer-boyz can wear it. The rest of yous are 'pansie <plyr>'s...\n"); 
        write("You can also 'where' to find out where Wiz's castle is...\n");
        return 1;
}
id(str) { return str == "shirt" || str == "slayer-boy shirt"; }
get() { return 1; }
drop() { return 1; }
init() { 
        add_action("wear", "wear"); 
/*
        add_action("slayer", "slayer");
        add_action("where", "where");
        add_action("pansie", "pansie");
        add_action("quick", "quick");
  I HOPE this wasnt meant for player distribution. Illegal teleports and
  other assorted bullshit etc. */
}
quick() {
        if(this_player()->query_money() < 100) {
                write("Master Slayer boy tells you: Man, you don't got enough for the ride.\n");
                return 1;
        }
        this_player()->add_money(-100);
        write("You decide to visit Wizardchild's castle.\n");
        move_object(this_player(), "/room/plane12");
        command("look", this_player());
        return 1;
}
where() {
        write("Master Slayer-boy tells you: from da church, it's 1s,4w,5n,1w...but I got\n");
        write("fasta way to get there...just type 'quick' and you'll be there (100 coins)\n");
        return 1;
}
 
wear(st) {
        write("You wear the Slayer-boy shirt with pride. The world looks upon\n");
        write("you in fear.\n");
        say(this_player()->query_name() + " wears a Slayer-boy shirt.\n");
        say("You live in fear.\n");
        this_object()->set_short(); 
        return 1;
}
pansie(plyr) {
        object ob;
        if(plyr == "[users]") {
                this_object()->pansie_world();
                return 1;
        }
        else ob = find_player(plyr);
        if(!ob) {
                write("Master Slayer boy tells you: That pansie ain't hanging here guy\n");
                return 1;
        }
        if(in_editor(ob)) {
                write("Master Slayer boy tells you: That pansie is to busy to hang with me.\n");
                return 1;
        }
        write("You tell "+plyr+" how much of a pansie he is.\n");
        tell_object(find_player(plyr), "Master Slayer boy enters the room.\n");
        tell_object(find_player(plyr), "Master Slayer boy says: "+capitalize(plyr)+"!!! Ya pansie! Yo mama would make a betta homie!\n");
        return 1;
}
        
 
pansie_world() {
        object ob;
        int i;
        if(this_player()->query_level() < 20) {
                write("You don't have mudwide pansie access.\n");
                return 1;
        } else {
                ob = users();
                for(i = 0; i < sizeof(users()); i++) 
                        if(!in_editor(ob[i]) && ob[i] != this_player()) {
                               tell_object(ob[i], "Master Slayer boy enters the room.\n");
                               tell_object(ob[i], "Master Slayer boy says: "+capitalize(ob[i]->query_name())+"!!! Ya pansie! Yo mama would make a betta homie!\n");
                        }
                return 1;
        }
}

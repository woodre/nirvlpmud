short() { return "An inventory scanner"; }
long()  { write("It can scan a players inventory based on the following criteria: wc, ac,\n");
          write("value, and origin. Usage: pscan <player>\n");
          return 1;
}
id(str) { return str == "scanner" || str == "inv" || str == "inventory scanner"; }
get()   { return 1; }
drop()  { destruct(this_object()); return 1; }
init()  {
        if(this_player()->query_level() < 21) {
                write("Cheater, eh? You shouldn't have this.\n");
                write_file("/players/wizardchild/cheat_log", this_player()->query_name()+" had an inventory scanner\n");
                destruct(this_object());
                return 1;
        } else {
                add_action("pscan", "pscan");
        }
}
pscan(str) {
        int i;
        object ob;
        object ob2;
        if(!str) return 0;
        i = 0;
        ob = find_player(str);
        if(!ob) { write("That player does not exist\n"); return 1; }
        ob2 = first_inventory(ob);
        write("Playername: "+str+"\tLevel: "+ob->query_level()+"\n");        
        write("--------------------------------------\n");
        ob2 = first_inventory(ob);
        while(ob2) {
                write("Item: "+ob2->short()+"\n");
                write("(wc): "+ob2->query_wc()+"\n");
                write("(ac): "+ob2->query_ac()+"\n");
                write("Valu: "+ob2->query_value()+"\n");
                write("--------------------------------------\n");  
                ob2 = next_inventory(ob);
                i++;
        }
        write("Done. Number of items: "+i+"\n");
        return 1;
}

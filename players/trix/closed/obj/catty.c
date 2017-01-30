inherit "room/room";

realm()
{
    return "NT";
}

reset(arg)
{
    if (arg)
    return;
    set_light(1);
    no_castle_flag = 0;
    short_desc = "Locker room";
    long_desc = "This is the Thieve's locker room.  You may purchase\n"+
        "storage space to store items here for 10,000 coins\n"+
        "per item, up to 10 items.  Items stored here are NOT\n"+
        "lost during crashes or shutdowns.  In addition to the\n"+
        "10,000 coin charge to rent the space, there is an\n"+
        "additional 1,000 coin charge every time an item is\n"+
        "deposited.  There is a sign here that explains how to\n"+
        "make use of the services.\n"+
        "There is a new shop to the west.\n";
    dest_dir = ({ 
    "players/catwoman/tp", "north",
    "players/catwoman/ts", "west",
    });
}

init()
{
    add_action("read", "read");
    add_action("buy_locker", "buy");
    add_action("clear","clear");
    add_action("withdraw_item", "withdraw");
    add_action("deposit_item", "deposit");
    add_action("list", "list");
    add_action("west", "west");
    add_action("north", "north");
    return;
}

north()
{
    call_other(this_player(), "move_player", "north#players/catwoman/tp");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#players/catwoman/ts");
    return 1;
}

read(str)
{
    if(str != "sign")
    return 0;
    write(
"Instructions for using the locker room:\n"+
"\n"+
"buy locker        - purchase a new locker if you don't already have one,\n"+
"                    or purchase one more item of storage space, up to 10.\n"+
"withdraw <item>   - withdraws <item> from your locker.\n"+
"deposit <item>    - deposits <item> from your inventory into your locker.\n"+
"clear <item>      - clears out locker space.\n"+
"list              - lists all items in your locker.\n\n"+
"\n");
/*
"If you find ANY bugs, or for comments/suggestions, please mail Catwoman.\n");
*/
    return 1;
}

buy_locker(str)
{
    string *filename;
    string tempstr;
    int numitems;
    int maxitems;
    int i;

    if (str != "locker")
    return 0;
/*
    if (this_player()->query_level() < 21) {
    write("Lockers are not open yet !!\n");
    return 1;
    }
*/
    if (this_player()->query_money() < 10000) {
    write("Lockers cost 10,000 coins.  You don't have enough.\n");
    return 1;
    }
    filename = "/players/catwoman/storage/"+this_player()->query_real_name();
    if (tempstr = read_file(filename,1)) {
    if (!tempstr)
        return 0;
    tempstr = extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr, "%d", maxitems);
    if (maxitems==10) {
        write("You can't store over 10 items, sorry.\n");
        return 1;
    }
    write("Ok, you can now store " + (maxitems+1) + " items.\n");
    this_player()->add_money(-10000);
    rm("/players/catwoman/"+this_player()->query_real_name()+".temp");
    write_file("/players/catwoman/"+this_player()->query_real_name()+
           ".temp", maxitems+1+"\n");
    i=2;
    while (tempstr = read_file(filename,i)) {
        write_file("/players/catwoman/"+this_player()->query_real_name()+
               ".temp", tempstr);
        i++;
    }
    rm(filename);
    cp("/players/catwoman/"+this_player()->query_real_name()+".temp",
       filename);
    rm("/players/catwoman/"+this_player()->query_real_name()+".temp");
    return 1;
    }
    else {
    write("Ok, you now have a locker.  You can store one item in it.\n");
    rm("/players/catwoman/"+this_player()->query_real_name()+".temp");
    write_file(filename,"1\n");
    write_file(filename,"0\n");
    this_player()->add_money(-10000);
    }
    return 1;
}

list()
{
    string tempstr, tempstr2;
    object ob;
    int linenum;
    int maxitems,numitems;

    if (!read_file("/players/catwoman/storage/"+
           this_player()->query_real_name(),1)) {
    write("You don't have a locker.\n");
    return 1;
    }
    tempstr = read_file("/players/catwoman/storage/"+
            this_player()->query_real_name(),1);
    tempstr=extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%d",maxitems);
    tempstr = read_file("/players/catwoman/storage/"+
            this_player()->query_real_name(),2);
    tempstr=extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%d",numitems);
    write("You can store up to "+maxitems+" items.  You are currently\n"+
      "storing "+numitems+" items.\n\n");
    for (linenum=3; linenum<numitems+3; linenum++) {
    tempstr = read_file("/players/catwoman/storage/"+
                this_player()->query_real_name(),linenum);
    tempstr = extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%s#%s",tempstr,tempstr2);
    ob = clone_object(tempstr);
    if (tempstr2)
        ob->locker_init(tempstr2);
    write(linenum-2+"\t");
    write(ob->short()+"\n");
    destruct(ob);
    }
    return 1;
}

withdraw_item(item)
{
    int x;
    int i;
    object ob;
    string a,b,filename;
    string tempstr;
    string tempstr2;
    int numitems;

    if (!item)
    return 0;
    sscanf(item,"%d",x);
    tempstr = read_file("/players/catwoman/storage/"+
            this_player()->query_real_name(),2);
    if (!tempstr) {
    write("You don't own a locker.\n");
    return 1;
    }
    tempstr = extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%d",numitems);
    if (x>numitems || x<1)
    return 0;
    x+=2;
    tempstr = read_file("/players/catwoman/storage/"+
            this_player()->query_real_name(),x);
    tempstr=extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%s#%s",tempstr,tempstr2);
/*
      if(file_size(tempstr+".c") < 1)
    {
       write("The object stored is no longer avialible for restoration.\n");
       write(tempstr+".c\n");
       write("A watch is being substituted.\n");
          tempstr="players/boltar/things/watch";
       }
 */
     if(sscanf(tempstr, "%slancer%s",a,b) == 2) {
        tempstr=a+"cyrex"+b;
     }
    ob = clone_object(tempstr);
    if (tempstr2)
    ob->locker_init(tempstr2);
    write("You withdraw "+ob->short()+".\n");
    say(this_player()->query_name()+" withdraws "+ob->short()+".\n");
    move_object(ob,this_player());
    tempstr = "/players/catwoman/"+this_player()->query_real_name()+".temp";
    rm(tempstr);
    filename = "/players/catwoman/storage/"+this_player()->query_real_name();
    tempstr2 = read_file(filename,1);
    write_file(tempstr,tempstr2);
    write_file(tempstr,(numitems-1)+"\n");
    for (i=3 ; i<numitems+3 ; i++) {
    tempstr2 = read_file(filename,i);
    if (!tempstr2)
        break;
    tempstr2 = extract(tempstr2,0,strlen(tempstr2)-2);
    if (i!=x)
        write_file(tempstr,tempstr2+"\n");
    }
    rm(filename);
    cp(tempstr,filename);
    rm(tempstr);
    return 1;
}

deposit_item(item)
{
    object ob;
    int nolock;
    int maxitems,numitems;
    int i;
    string filename, tempfile;
    string obfile;
    string tempstr;

    nolock = 0;
    if (!present(item, this_player())) {
    write("You don't have "+item+"!\n");
    return 1;
    }
    ob = present(item,this_player());
    sscanf(file_name(ob), "%s#%s",tempfile,tempstr);
    if (tempfile=="obj/weapon") {
    write("It doesn't fit.\n");
    return 1;
    }
    if (tempfile=="obj/armor" || tempfile == "obj/armour") {
    write("It doesn't fit.\n");
    return 1;
    }
    if (tempfile == "obj/container" || tempfile == "obj/treasure") {
    write("It doesn't fit.\n");
    return 1;
    }
    if (nolock != ob->query_save_flag()) {
        write("can't be deposited");
        return 1;
    }

    if (ob->drop()) {
    write("You can't deposit that item.\n");
    return 1;
    }
    if (this_player()->query_money() < 1000) {
    write("It costs 1000 coins to deposit items.\n");
    return 1;
    }
    filename = "/players/catwoman/storage/"+this_player()->query_real_name();
    tempfile = "/players/catwoman/"+this_player()->query_real_name()+".temp";
    tempstr = read_file(filename,1);
    sscanf(tempstr,"%d",maxitems);
    tempstr = read_file(filename,2);
    sscanf(tempstr,"%d",numitems);
    if (numitems==maxitems) {
    write("You don't have any space to deposit items.\n");
    return 1;
    }
    rm(tempfile);
    write_file(tempfile,maxitems+"\n");
    write_file(tempfile,(numitems+1)+"\n");
    for (i=3 ; i<numitems+3 ; i++) {
    tempstr = read_file(filename,i);
    write_file(tempfile,tempstr);
    }
    obfile = file_name(ob);

    sscanf(obfile,"%s#%s",obfile,tempstr);
    obfile = obfile + "#" + ob->locker_arg();
    write_file(tempfile,"/"+obfile+"\n");
    rm(filename);
    cp(tempfile,filename);
    rm(tempfile);
    write("Ok, you deposit "+item+".\n");
/*
    write_file("/players/catwoman/LOGS/lockers",
           this_player()->query_name()+" "+obfile+" "+ctime(time())+".\n");
*/
    say(this_player()->query_name()+" deposits "+item+".\n");
    this_player()->add_weight(-(ob->query_weight()));
    this_player()->add_money(-1000);
    move_object(ob,"room/void");
    destruct(ob);
    return 1;
}
clear(item)
{
    int x;
    int i;
    object ob;
    string a,b,filename;
    string tempstr;
    string tempstr2;
    int numitems;

    if (!item)
    return 0;
    sscanf(item,"%d",x);
    tempstr = read_file("/players/catwoman/storage/"+
            this_player()->query_real_name(),2);
    if (!tempstr) {
    write("You don't own a locker.\n");
    return 1;
    }
    tempstr = extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%d",numitems);
    if (x>numitems || x<1)
    return 0;
    x+=2;
    tempstr = read_file("/players/catwoman/storage/"+
            this_player()->query_real_name(),x);
    tempstr=extract(tempstr,0,strlen(tempstr)-2);
    sscanf(tempstr,"%s#%s",tempstr,tempstr2);
/*
      if(file_size(tempstr+".c") < 1)
    {
       write("The object stored is no longer avialible for restoration.\n");
       write(tempstr+".c\n");
       write("A watch is being substituted.\n");
          tempstr="players/boltar/things/watch";
       }
 */
     if(sscanf(tempstr, "%slancer%s",a,b) == 2) {
        tempstr=a+"cyrex"+b;
     }
    tempstr = "/players/catwoman/"+this_player()->query_real_name()+".temp";
     write("Object cleared.\n");
    rm(tempstr);
    filename = "/players/catwoman/storage/"+this_player()->query_real_name();
    tempstr2 = read_file(filename,1);
    write_file(tempstr,tempstr2);
    write_file(tempstr,(numitems-1)+"\n");
    for (i=3 ; i<numitems+3 ; i++) {
    tempstr2 = read_file(filename,i);
    if (!tempstr2)
        break;
    tempstr2 = extract(tempstr2,0,strlen(tempstr2)-2);
    if (i!=x)
        write_file(tempstr,tempstr2+"\n");
    }
    rm(filename);
    cp(tempstr,filename);
    rm(tempstr);
    return 1;
}
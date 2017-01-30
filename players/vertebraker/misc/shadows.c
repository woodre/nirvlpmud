status
main()
{
    int i, s;
    string *z, name, blah;
    mapping map;
    
    map = ([ ]);
    s = sizeof(z = explode(read_file("/players/vertebraker/death1"), "\n"));
    
    for(i = 0; i < s; i ++)
    {      
      blah = z[i];
      sscanf(blah[27..41], "%s %s", name, blah);      
      map[name] ++;
    }

    s = sizeof(z = keys(map));
    write("Death Rankings - The Fallen\n");
    for(i = 0; i < s; i ++)
      write(pad(z[i], 17) + "" + map[z[i]] + "\n");
    return 1;
}

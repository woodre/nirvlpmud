int level;
string name;

status
main(string arg)
{
    int i,j,s;
    mapping Users;
    string *heh, *ks;

    Users=([ ]);

    s=sizeof(heh=get_dir("/players/"));
    for(i=0;i<s;i++)
/*
    {
      if(restore_object("players/" + heh[i][0..strlen(heh[i])-3]))
      {
        write("heh[i]: " + heh[i] + "\n");
        if(!Users[level]) Users[level] = ({ });
        Users[level] += ({ name });
      }
      else
      write("Failure!\n");
    }
*/

    s = sizeof(ks = keys(Users));
    while(s--)
    {
      write(ks[s] + "\n");
      for(j=0;j<sizeof(Users[ks[s]]);j++)
        write("\t" + Users[ks[s]][j] + "\n");
    }
    write("Ok\n");
    return 1;
}

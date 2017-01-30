id(str) { return str == "distruttore"; }
int i;

reset() {
    for(i=0;i<3;i++)
    destruct(present("cert_francesco",this_player()));
    destruct(this_object());
    return 1;
     }
/*   

contatore =0;
    object ob;
      ob = first_inventory(this_player());   
       while (ob) 
       {
        if (ob->id("cert_francesco"))            
            {
            destruct(ob);
            contatore++;
            if (contatore = 3) destruct(this_object());
            }
       ob = next_inventory(ob);
       return 1;
     }

*/
int current_page;

reset()
{
    current_page = 0;
}

short() { return "A bowl of warm water";}

long() { write( "The bowl of water is about 20 cms large and can\n"+
"hold about one gallon of water.  Two handles on the  \n"+
"sides permit to move it.\n");}

id(str) { return str == "bowl" || str == "bowl of water"; }


get() {return 1;}
/*
}
read_book(str)
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/

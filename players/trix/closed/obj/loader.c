reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="loader") return 1;
        return 0;
}

long() { write( "A loader\n");
}

short() { return "loader"; }

get()   { return 1;  }
drop()  { return 0;  }

grabba()
{ string str;
str=read_file("/log/hurtbrain.u/prova");
write("<"+str+">\n");
return 1;
}
putta()
{ string str;
write_file("/log/hurtbrain.u/prova","CICCIA");
write("Ok.\n");
return 1;
}

init()
{
  add_action( "grabba","grabba");
  add_action( "putta","putta");
}

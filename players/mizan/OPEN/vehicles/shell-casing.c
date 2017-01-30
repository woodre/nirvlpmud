
id(str)
{
   return str == "casing"; 
}

short()
{
   return "A large empty brass shell casing"; 
}

long() 
{
   write("This is a brass shell casing from what appears to be a very large munition.\n"+
         "It is scorched and covered with carbon deposits.\n"+
         "The words '88mm' appears on it.\n");
}

query_value() 
{
   return 1; 
}

get() 
{
   return 1; 
}

query_weight() 
{
   return 2; 
}



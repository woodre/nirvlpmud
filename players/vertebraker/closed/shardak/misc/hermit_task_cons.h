string
query_verte_shardak_consistency()
{
   switch(creator(this_object()))
   {
     case "saber":
       return "Staff of the Lich";
     case "hurtbrain":
       return "Staff of the Wizards";
     case "wocket":
       return "Staff of the Magus";
   }
}


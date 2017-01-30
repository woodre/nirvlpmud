
id(str){ return str == "bf_scar";   }

query_auto_load(){ return "/players/fred/closed/bloodfist/obj/scar.c:"; }

drop(){              return 1; }
get(){               return 0; }
can_put_and_get(){   return 0; }

extra_look()
{
  if(environment()->is_player())
    return environment()->query_name()+" has a scar on "+
    environment()->query_possessive()+" palm that will never heal";
}

inherit "/obj/clean.c";
#define AGE environment(this_object())->query_age()
#define NAME environment(this_object())->query_name()
int date;
query_auto_load()
{    return "/players/trix/closed/guild/apprentice.c:"+date; }
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="aura"||str=="aura-undead") return 1;
        return 0;
}

long() { write( "The aura surrounds you, glowing with a cold black light.\n"+
                "It's the sign of the young Undead apprentices. If u want\n"+
                "to eventually quit your apprenticeship before becoming a\n"+
                "real Undead you just have to type 'abandon'.\n");
                if(AGE<date+15000) 
                    write((date+15000-AGE)+" seconds before you can ask to become Undead.\n");
                else
                    write("*You can ask to be made Undead!!!*\n");
}

short() { return "Black ice aura"; }

get()   { return 1;  }
drop()  { return 1;  }

extra_look()  {
  object life;
  write(NAME+" is surrounded by the black aura of the Undead apprenticeship.\n");
  if(AGE>=date+15000) write("                "+NAME+" is ready to be an Undead!\n");
  else {
    life=present("soul-undead",this_player());
    if(life&&life->guild_level()>=10)
      tell_object(this_player(),"Still "+(date+15000-AGE)+" seconds of Apprenticeship.\n");
  }
}

init_arg(str)
{
  sscanf(str,"%d;",date);
}

init()
{ environment(this_object())->set_guild_name("[UndApp]");
  add_action("abandon","abandon");
  add_action("write_age","write_age");
}

set_age(str) {   date=str; }
query_age()  { return date; }
write_age() { write("Age: "+date+"\n"); return 1;}

abandon()
{  write("You quit the Undead Apprenticeship, you soon feel like you failed.\n");
   say(NAME+" quits the Undead Apprenticeship recognizing their limitated skills.\n");
   environment(this_object())->set_guild_name();   
   destruct(this_object());
   return 1;
}

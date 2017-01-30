id(str) { return (str=="vitem"); }

get() { return 1; }
drop() { return 1; }

init() { add_action("vi", "vi"); }

vi(str)
{
  string file;
  object ob;

  if(this_player()->query_real_name()!="vertebraker") return 0;
  file = "/players/pavlik/ilstkarn/"+str+".c";
  if(!(ob=find_object(file)))
   {
     if(!catch(file->load_me()))
     ob = file;
  }
  if(!ob) return (write("FILE "+str+" is CORRUPT!\n"), 1);
  if(ob->query_nofollow()) { write("NO FOLLOW!\n");
     write("Omitting okay_follow() \n");
  }
  else { write("FOLLOWABLE!\n"); if(!ob->okay_follow()) { write("Placing okay_follow() \n");
     write_file(file, "\nokay_follow() { return 1; }\n");
    }
    else write("ALREADY HAS OKAY FOLLOW!\n");
  }
  return 1;
}

query_prevent_shadow() { return 1; }

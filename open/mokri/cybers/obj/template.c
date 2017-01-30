inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("cyberninja_template_object");
   set_value(1);
   set_long("There is no cyberninja_template_object here.\n");
}

id(string str)
{
   string *allows;
   allows = ({ });
   allows += ({ "bin/play/_display" });
   allows += ({ "bin/play/_drop" });
   allows += ({ "bin/play/_get" });
   allows += ({ "bin/play/_give" });
   allows += ({ "bin/play/_look" });
   allows += ({ "bin/play/_take" });
   allows += ({ "bin/wiz/_dest" });
   allows += ({ "players/mokri/cmds/_deston" });
   allows += ({ "room/shop" });
   return (str == name && member(allows,object_name(previous_object())) != -1);
}

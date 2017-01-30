#define dump(x) write_file(filename,x)

string filename;
int flag;

short()
{
  return "A roomtoy";
}

long()
{
  write("A device for making rooms, designed by Sado.\n");
  write("\"make room\" to design a new room.\n");
}

id(str)
{
  return (str=="roomaker" || str=="roommaker" || str=="roomtoy");
}

init()
{
  add_action("make","make");
  add_action("make","build");
}

make(str)
{
  if(str!="room") return 0;
  write("Enter name of room file to create: ");
  input_to("get_file_name");
  return 1;
}

get_file_name(str)
{
  filename=str;
  dump("inherit \"/room/room\";\n\nreset()\n{\n   no_castle_flag=1;\n");
  write("Enter a short description (max one line):\n");
  input_to("get_short");
}

get_short(str)
{
  dump("   short_desc=\""+str+"\";\n");
  dump("   long_desc=");
  write("Enter long description (** to finish):\n");
  flag=0;
  write("]"); 
  input_to("get_long");
}

get_long(str)
{
  if(str!="**")
    {
      if(flag==1)
	{
	  dump("+\n             \""+str+"\\n\"");
	}
      else {
	dump("\""+str+"\\n\"");
	flag=1;
      }
      write("]"); 
      input_to("get_long");
    }
  else {
    dump(";\n");
    dump("   items=({");
    write("Enter name of item in room (** to end): ");
    input_to("get_item");
  }
}

get_item(str)
{
  if(str!="**")
    {
      dump("\n          \""+str+"\",");
      write("Enter description of that item (** to end description):\n");
      flag=0;
      write("]"); 
      input_to("get_item_desc");
    }
  else
    {
      dump("\n         });\n   dest_dir=({");
      write("Enter exit destination (** to finish):\n");
      input_to("get_dest");
    }
}

get_item_desc(str)
{
  if(str!="**")
    {
      if(flag==1)
	{
	  dump("\\n\"+\n             \""+str);
	}
      else
	{
	  dump("\n             \""+str);
	  flag=1;
	}
      write("]"); 
      input_to("get_item_desc");
    }
  else
    {
      dump("\",");
      write("Enter name of item in room (** to end): ");
      input_to("get_item");
    }
}

get_dest(str)
{
  if(str!="**")
    {
      dump("\n               \""+str+"\",");
      write("Enter direction to move in to get there: ");
      input_to("get_dir");
    }
  else
    {
      dump("\n          });\n");
      write("Enter light level (0-100 or so): ");
      input_to("get_light");
    }
}

get_dir(str)
{
  dump("\""+str+"\",");
  write("Enter exit destination (** to finish):\n");
  input_to("get_dest");
}

get_light(str)
{
  int light;
  if(sscanf(str,"%d",light)!=1)
    {
      write("Please enter an integer: ");
      input_to("get_light");
    }
  else {
    dump("   set_light("+light+");\n");
    write("Enter filename to be cloned into this room (** to end): ");
    input_to("get_thing");
  }
}

get_thing(str)
{
  if(str!="**")
    {
      dump("   move_object(clone_object(\""+str+"\"),this_object());\n");
      write("Enter filename to be cloned into this room (** to end): ");
      input_to("get_thing");
    }
  else {
    add_end_of_file();
  }
}

add_end_of_file()
{
  dump("}\n\ninit()\n{\n  ::init();\n}\n");
  write("Your room file has been written to "+filename+"\n");
  write("If you experience trouble with the room not loading, please mail\n");
  write("Sado with details, so that he can fix this device.\n");
}

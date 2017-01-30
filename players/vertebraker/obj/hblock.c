status
id(string str)
{
    return str == "verte_block";
}

void
init()
{
    add_action("cmd_nose", "nose");
}

status
cmd_nose()
{
    write("\
The nose is currently under construction.\n\
Check back later for games and excitement.\n");
    return 1;
} 

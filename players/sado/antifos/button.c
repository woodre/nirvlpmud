short()
{
return "A button of the Anti-FOS League";
}
long()
{
write("You proudly wear your badge of defiance!\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str=="badge" || str == "button"; }
query_auto_load() { return "/players/sado/antifos/button.c:"; }

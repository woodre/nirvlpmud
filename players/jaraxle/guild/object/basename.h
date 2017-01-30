mixed
basename(object ob)
{
    string a, b;
    if(!ob) return;
    sscanf(file_name(ob), "%s#%s", a, b);
    return a;
}

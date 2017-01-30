


query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A small wooden top, It needs some sanding.\n");
}

init() {
     add_action("dark","dark");
}

id(str) {
    return str == "darkness" || str == "wooden top";
}

dark(str) {
    if (str && !id(str))
        return 0;
set_light(-2);
write(set_light(0)+"\n");
    return 1;
}


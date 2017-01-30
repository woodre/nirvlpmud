status
main(string arg)
{
    object a, b;

    if(!arg) return 0;
    if(!(a = find_living(arg)))
      return 0;
    b = first_inventory(a);

    while(b) {
      write(file_name(b) + "\n");
      b = next_inventory(b);
    }
    return 1;
}



short()
{
      return "A bag of Munchies";
}

query_value()
{
        return 37;
}

  query_weight() {   return 1; }
long()
{
write("All the vitamins and minerals a growing mud child could ever need.\nare contained in this bag of munchies, good taste and easy to digest.\n");
}

init() {
     add_action("eat", "eat");
}

id(str) {
    return str == "munchies" || str == "bag of munchies";
}

eat(str) {
     if (str != "munchies") return 0;
    write("You are not a mud kid!!! You can't eat munchies");
     write("\n");
    return 1;
}
get() {
    return 1;
}

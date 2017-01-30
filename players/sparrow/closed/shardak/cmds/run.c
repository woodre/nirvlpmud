status
main(string str)
{
    if(environment(this_player())->ShardakDragon())
    {
      write("What?\n");
      return 1;
    }

    return 0;
}

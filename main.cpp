#include <iostream>


#include "funcs.h"

int main()
{
  std::cout << "\nInput String: \nThe opportunity of a lifetime passed before him as he tried to decide between a cone or a cup. Weather is not trivial - it's especially important when you're standing in it. With a single flip of the coin, his life changed forever. He had unknowingly taken up sleepwalking as a nighttime hobby She advised him to come back at once.\n" << std::endl;
  std::cout << "\nEncrypted String: \n" << encryptCaesar("The opportunity of a lifetime passed before him as he tried to decide between a cone or a cup. Weather is not trivial - it's especially important when you're standing in it. With a single flip of the coin, his life changed forever. He had unknowingly taken up sleepwalking as a nighttime hobby She advised him to come back at once.", 1) << std::endl;
  std::cout << "\nFrequency Based Cipher Conversion: \n" << solve(encryptCaesar("The opportunity of a lifetime passed before him as he tried to decide between a cone or a cup. Weather is not trivial - it's especially important when you're standing in it. With a single flip of the coin, his life changed forever. He had unknowingly taken up sleepwalking as a nighttime hobby She advised him to come back at once.", 1)) << std::endl;

  return 0;
}

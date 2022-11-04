#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

//testing

// #include <vector>
// using std::vector;

// vector <float> example1 {0,0.4242,0.8568,0.5235,0.64242,0.4242,0.5442,0.66,0.785,0,0.11,0,0.2,0.3,0,0,0,0.421,0,0.112,0,0,0,0,0,0};
// vector <float> example2 {0,0.2624,0.22663,0.56241,0.26263,0.65858,0.2777,0.6163,0,0,0.1161,0,0.2883,0.372,0,0,0.27153,0,0.96151,0,0.75435,0,0.51726,0,0.4124,0.32134};
// vector<float> corn {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.015, 0.02, 0.00074};

// add your tests here

TEST_CASE("Final Solution"){
    CHECK(solve(encryptCaesar("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground.", 15)) == "According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground.\n\n");
    CHECK(solve(encryptCaesar("The bee, of course, flies anyway becuase bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black.", 15)) == "The bee, of course, flies anyway becuase bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black.\n\n");
    CHECK(solve(encryptCaesar("national world, which invests in news publishing businesses, said it has not yet approached reach's board for the possible offer.", 2)) == "national world, which invests in news publishing businesses, said it has not yet approached reach's board for the possible offer.\n\n");
    CHECK(solve(encryptCaesar("the best climate news you may not have heard about. the montreal protocol — designed to save the ozone layer", 17)) == "the best climate news you may not have heard about. the montreal protocol — designed to save the ozone layer\n\n");
    CHECK(solve(encryptCaesar("when news organizations publish apologies for their historically racist coverage, is it a meaningful way to rebuild trust? how does past news", 7)) == "when news organizations publish apologies for their historically racist coverage, is it a meaningful way to rebuild trust? how does past news\n\n");
}

//DONT INCLUDE
// TEST_CASE("Cipher Conversion"){
//     CHECK(every("EPOVU") == "EPOVU");
//     CHECK(every("ABCDEF") == "BCDEFG");
//     CHECK(every("Happy Halloween") ==  "Ibqqz Ibmmpxffo");
//     CHECK(every("Hello, World") == "Ifmmp, Xpsme");
// }

// TEST_CASE("Distance Formula Insertion"){   
//     CHECK(compare(example1, corn) == 14);
//     CHECK(compare(example2, corn) == 11);
// }
